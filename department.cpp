#include "department.h"
#include "ui_department.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDate>
#include <QDebug>

Department::Department(int department_id, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Department)
    , CurrentDepartment_Id(department_id)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    ui->statusComboBox->clear();
    ui->statusComboBox->addItem("Active");
    ui->statusComboBox->addItem("Inactive");

    loadDepartmentNames();

    if (CurrentDepartment_Id == 0) {
        ui->pageTitle->setText("Add New Department");
        ui->saveButton->setText("Save");
    } else {
        ui->pageTitle->setText("Update Department");
        ui->saveButton->setText("Update");
        load_data();
    }
}

Department::~Department()
{
    delete ui;
}

void Department::loadDepartmentNames()
{
    QStringList deptNames = {
        "Emergency Department",
        "Internal Medicine",
        "Surgery",
        "Pediatrics",
        "Cardiology",
        "Orthopedics",
        "Obstetrics & Gynecology",
        "Radiology",
        "Neurology",
        "Oncology",
        "Dermatology",
        "Psychiatry",
        "ICU",
        "Pharmacy",
        "Laboratory"
    };

    ui->nameComboBox->clear();
    ui->nameComboBox->addItems(deptNames);
}

void Department::on_saveButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Database", "Database is not open!");
        return;
    }

    name   = ui->nameComboBox->currentText();
    status = ui->statusComboBox->currentText();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Department name cannot be empty.");
        return;
    }

    QSqlQuery query(db);

    if (CurrentDepartment_Id == 0) {
        query.prepare("INSERT INTO department (name, status, date) "
                      "VALUES (:name, :status, :date)");
    } else {
        query.prepare("UPDATE department SET name=:name, status=:status, date=:date "
                      "WHERE department_id = :id");
        query.bindValue(":id", CurrentDepartment_Id);
    }

    query.bindValue(":name",   name);
    query.bindValue(":status", status);
    query.bindValue(":date",   QDate::currentDate().toString("yyyy-MM-dd"));

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to save:\n" + query.lastError().text());
    } else {
        accept();
    }
}

void Department::load_data()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    q.prepare("SELECT name, status FROM department WHERE department_id = :id");
    q.bindValue(":id", CurrentDepartment_Id);

    if (q.exec() && q.next()) {
        ui->nameComboBox->setCurrentText(q.value("name").toString());
        ui->statusComboBox->setCurrentText(q.value("status").toString());
    }
}

void Department::on_pushButton_2_clicked()
{
    this->close();
}
