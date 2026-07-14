#include "doctor.h"
#include "ui_doctor.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDate>
#include <QDebug>

Doctor::Doctor(int doctor_id, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Doctor)
    , CurrentDoctor_Id(doctor_id)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    loadDepartmentsFromDb();

    if (CurrentDoctor_Id == 0) {
        ui->pageTitle->setText("Add New Doctor");
        ui->saveButton->setText("Save");
    } else {
        ui->pageTitle->setText("Update Doctor");
        ui->saveButton->setText("Update");
        load_data();
    }
}

Doctor::~Doctor()
{
    delete ui;
}

void Doctor::loadDepartmentsFromDb()
{
    ui->comboBoxDepartment->clear();
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlQuery q(db);
    q.prepare("SELECT department_id, name FROM department WHERE status = 'Active' ORDER BY name");

    if (q.exec()) {
        int count = 0;
        while (q.next()) {
            QString deptName = q.value(1).toString();
            int deptId = q.value(0).toInt();

            ui->comboBoxDepartment->addItem(deptName, deptId);
            count++;
        }

        if (count == 0) {
            qDebug() << "No active departments found in database.";
            ui->comboBoxDepartment->addItem("No Active Departments", 0);
        }
    } else {
        qDebug() << "Query failed:" << q.lastError().text();
    }
}

void Doctor::on_saveButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Database", "Database is not open!");
        return;
    }

    QString doctorName = ui->lineEditName->text().trimmed();
    int doctorAge      = ui->lineEditAge->text().toInt();
    QString doctorGender = ui->comboBoxGender->currentText();
    int deptId = ui->comboBoxDepartment->currentData().toInt();

    if (doctorName.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Doctor name cannot be empty.");
        return;
    }

    if (deptId <= 0) {
        QMessageBox::warning(this, "Validation", "Please select a valid department.");
        return;
    }

    QSqlQuery query(db);

    if (CurrentDoctor_Id == 0) {
        query.prepare(
            "INSERT INTO doctor (name, age, gender, department_id, date) "
            "VALUES (:name, :age, :gender, :dept_id, :date)");

        query.bindValue(":name",    doctorName);
        query.bindValue(":age",     doctorAge);
        query.bindValue(":gender",  doctorGender);
        query.bindValue(":dept_id", deptId);
        query.bindValue(":date",    QDate::currentDate().toString("yyyy-MM-dd"));
    } else {
        query.prepare(
            "UPDATE doctor SET name=:name, age=:age, gender=:gender, "
            "department_id=:dept_id, date=:date "
            "WHERE doctor_id = :id");

        query.bindValue(":name",    doctorName);
        query.bindValue(":age",     doctorAge);
        query.bindValue(":gender",  doctorGender);
        query.bindValue(":dept_id", deptId);
        query.bindValue(":date",    QDate::currentDate().toString("yyyy-MM-dd"));
        query.bindValue(":id",      CurrentDoctor_Id);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to save:\n" + query.lastError().text());
    } else {
        accept();
    }
}

void Doctor::load_data()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);

    q.prepare("SELECT name, age, gender, department_id FROM doctor WHERE doctor_id = :id");
    q.bindValue(":id", CurrentDoctor_Id);

    if (q.exec() && q.next()) {
        ui->lineEditName->setText(q.value(0).toString());
        ui->lineEditAge->setText(q.value(1).toString());
        ui->comboBoxGender->setCurrentText(q.value(2).toString());

        int deptId = q.value(3).toInt();

        int index = ui->comboBoxDepartment->findData(deptId);
        ui->comboBoxDepartment->setCurrentIndex(index);
    } else {
        qDebug() << "Failed to load doctor data:" << q.lastError().text();
    }
}

void Doctor::on_closeButton_clicked()
{
    reject();
}

void Doctor::on_comboBoxDepartment_activated(int index)
{
    Q_UNUSED(index)
}