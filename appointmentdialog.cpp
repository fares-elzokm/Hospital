#include "appointmentdialog.h"
#include "ui_appointmentdialog.h"
#include <QMessageBox>
#include <QSqlError>

AppointmentDialog::AppointmentDialog(int id, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AppointmentDialog)
    , appointmentId(id)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);

    ui->dateEdit->setDate(QDate::currentDate());

    if(ui->comboBoxStatus->count() == 0) {
        ui->comboBoxStatus->addItems({"Scheduled", "Completed", "Cancelled"});
    }

    loadData();

    connect(ui->comboBoxDoctor, SIGNAL(currentIndexChanged(int)), this, SLOT(onDoctorChanged(int)));

    if (appointmentId > 0) {
        ui->saveButton->setText("Update");
        loadAppointmentData(appointmentId);
    } else {
        ui->saveButton->setText("Save");
    }
}

AppointmentDialog::~AppointmentDialog()
{
    delete ui;
}

void AppointmentDialog::loadData()
{
    QSqlQuery q(curd.conDb());

    ui->comboBoxPatient->clear();
    if(q.exec("SELECT patient_id, name FROM patients")) {
        while(q.next()) {
            ui->comboBoxPatient->addItem(q.value(1).toString(), q.value(0));
        }
    }

    ui->comboBoxDoctor->clear();
    if(q.exec("SELECT doctor_id, name FROM doctor")) {
        while(q.next()) {
            ui->comboBoxDoctor->addItem(q.value(1).toString(), q.value(0));
        }
    }

    ui->comboBoxDept->clear();
    if(q.exec("SELECT department_id, name FROM department WHERE status = 'Active'")) {
        while(q.next()) {
            ui->comboBoxDept->addItem(q.value(1).toString(), q.value(0).toInt());
        }
    }
}

void AppointmentDialog::on_saveButton_clicked()
{
    if(ui->comboBoxPatient->currentIndex() == -1 ||
        ui->comboBoxDoctor->currentIndex() == -1 ||
        ui->comboBoxDept->currentIndex() == -1) {
        QMessageBox::warning(this, "Warning", "Please select Patient, Doctor, and Department");
        return;
    }

    int patientId = ui->comboBoxPatient->currentData().toInt();
    int doctorId  = ui->comboBoxDoctor->currentData().toInt();
    int deptId    = ui->comboBoxDept->currentData().toInt();

    QString date   = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString status = ui->comboBoxStatus->currentText();

    QSqlQuery q(curd.conDb());

    if (appointmentId == 0) {
        q.prepare("INSERT INTO appointments (patient_id, doctor_id, department_id, appointment_date, status) "
                  "VALUES (:p, :doc, :dept_id, :date, :status)");
    } else {
        q.prepare("UPDATE appointments SET patient_id=:p, doctor_id=:doc, department_id=:dept_id, "
                  "appointment_date=:date, status=:status WHERE appointment_id=:id");
        q.bindValue(":id", appointmentId);
    }

    q.bindValue(":p",       patientId);
    q.bindValue(":doc",     doctorId);
    q.bindValue(":dept_id", deptId);
    q.bindValue(":date",    date);
    q.bindValue(":status",  status);

    if(q.exec()) {
        accept();
    } else {
        QMessageBox::critical(this, "Error", "Database Error: " + q.lastError().text());
    }
}

void AppointmentDialog::on_cancelButton_clicked()
{
    reject();
}

void AppointmentDialog::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton) {
        dragging = true;
        dragPosition = e->globalPosition().toPoint() - frameGeometry().topLeft();
        e->accept();
    }
}

void AppointmentDialog::mouseMoveEvent(QMouseEvent *e) {
    if (dragging && (e->buttons() & Qt::LeftButton)) {
        move(e->globalPosition().toPoint() - dragPosition);
        e->accept();
    }
}

void AppointmentDialog::mouseReleaseEvent(QMouseEvent *) {
    dragging = false;
}

void AppointmentDialog::loadAppointmentData(int id)
{
    QSqlQuery q(curd.conDb());
    q.prepare("SELECT patient_id, doctor_id, department_id, appointment_date, status "
              "FROM appointments WHERE appointment_id = :id");
    q.bindValue(":id", id);

    if (q.exec() && q.next()) {
        int pId = q.value(0).toInt();
        ui->comboBoxPatient->setCurrentIndex(ui->comboBoxPatient->findData(pId));

        int dId = q.value(1).toInt();
        ui->comboBoxDoctor->setCurrentIndex(ui->comboBoxDoctor->findData(dId));

        int deptId = q.value(2).toInt();
        ui->comboBoxDept->setCurrentIndex(ui->comboBoxDept->findData(deptId));

        ui->dateEdit->setDate(q.value(3).toDate());
        ui->comboBoxStatus->setCurrentText(q.value(4).toString());
    }
}

void AppointmentDialog::onDoctorChanged(int index)
{
    if (index == -1) return;

    int doctorId = ui->comboBoxDoctor->itemData(index).toInt();

    QSqlQuery q(curd.conDb());
    q.prepare("SELECT department_id FROM doctor WHERE doctor_id = :doc_id");
    q.bindValue(":doc_id", doctorId);

    if (q.exec() && q.next()) {
        int deptId = q.value(0).toInt();

        int deptIndex = ui->comboBoxDept->findData(deptId);
        if (deptIndex != -1) {
            ui->comboBoxDept->setCurrentIndex(deptIndex);
        }
    }
}