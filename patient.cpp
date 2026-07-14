#include "patient.h"
#include "ui_patient.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDate>

Patient::Patient(int patient_id, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Patient)
    , CurrentPatient_Id(patient_id)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    if (CurrentPatient_Id == 0) {
        ui->pageTitle->setText("Add New Patient");
        ui->saveButton->setText("Save");
    } else {
        ui->pageTitle->setText("Update Patient");
        ui->saveButton->setText("Update");
        load_data();
    }
}

Patient::~Patient()
{
    delete ui;
}

void Patient::on_saveButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Database", "Database is not open!");
        return;
    }

    name    = ui->nameLineEdit->text().trimmed();
    age     = ui->ageLineEdit->text().toInt();
    gender  = ui->genderComboBox->currentText();
    phone   = ui->phoneLineEdit->text().toDouble();
    history = ui->medicalHistoryLineEdit->text().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Patient name cannot be empty.");
        return;
    }

    QSqlQuery query(db);

    if (CurrentPatient_Id == 0) {
        query.prepare(
            "INSERT INTO patients (name, age, gender, phone, medical_history, date) "
            "VALUES (:name, :age, :gender, :phone, :history, :date)");
    } else {
        query.prepare(
            "UPDATE patients SET name=:name, age=:age, gender=:gender, "
            "phone=:phone, medical_history=:history, date=:date "
            "WHERE patient_id = :id");
        query.bindValue(":id", CurrentPatient_Id);
    }

    query.bindValue(":name",    name);
    query.bindValue(":age",     age);
    query.bindValue(":gender",  gender);
    query.bindValue(":phone",   phone);
    query.bindValue(":history", history);
    query.bindValue(":date",    QDate::currentDate().toString("yyyy-MM-dd"));

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to save:\n" + query.lastError().text());
    } else {
        accept();
    }
}

void Patient::load_data()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    q.prepare("SELECT name, age, gender, phone, medical_history FROM patients WHERE patient_id = :id");
    q.bindValue(":id", CurrentPatient_Id);

    if (q.exec() && q.next()) {
        ui->nameLineEdit->setText(q.value("name").toString());
        ui->ageLineEdit->setText(q.value("age").toString());
        ui->genderComboBox->setCurrentText(q.value("gender").toString());
        ui->phoneLineEdit->setText(q.value("phone").toString());
        ui->medicalHistoryLineEdit->setText(q.value("medical_history").toString());
    }
}

void Patient::on_closeButton_clicked()
{
    reject();
}
