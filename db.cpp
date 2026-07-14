#include "db.h"
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include <QFile>

bool Db::db_open = false;

Db::Db()
{
    if(!db_open)
    {
        db = QSqlDatabase::addDatabase("QSQLITE");

        QString appDir = QCoreApplication::applicationDirPath();
        QString dbPath = appDir + "/db/db.db";

        if (!QFile::exists(dbPath)) {
            dbPath = appDir + "/db.db";
        }

        db.setDatabaseName(dbPath);

        if (!db.open())
        {
            qDebug() << "Database open failed:" << db.lastError().text();
            qDebug() << "Tried path:" << dbPath;
            QMessageBox::critical(nullptr, "Database Error",
                "Could not open database.\n\nExpected location:\n" + dbPath +
                "\n\nMake sure db.db is placed in a 'db' folder next to the .exe");
        }
        else
        {
            qDebug() << "Database connected:" << dbPath;
            QSqlQuery pragma(db);
            pragma.exec("PRAGMA foreign_keys = ON;");
            db_open = true;
            initTables();
        }
    }
    else
    {
        db = QSqlDatabase::database();
    }
}

Db::~Db()
{
}

QSqlDatabase& Db::conDb()
{
    return db;
}

void Db::initTables()
{
    QSqlQuery q(db);

    q.exec(R"(CREATE TABLE IF NOT EXISTS department (
        department_id   INTEGER PRIMARY KEY AUTOINCREMENT,
        name            TEXT NOT NULL,
        status          TEXT,
        date            TEXT
    ))");

    q.exec(R"(CREATE TABLE IF NOT EXISTS patients (
        patient_id      INTEGER PRIMARY KEY AUTOINCREMENT,
        name            TEXT NOT NULL,
        age             INTEGER,
        gender          TEXT,
        phone           TEXT,
        medical_history TEXT,
        date            TEXT
    ))");

    q.exec(R"(CREATE TABLE IF NOT EXISTS doctor (
        doctor_id       INTEGER PRIMARY KEY AUTOINCREMENT,
        name            TEXT NOT NULL,
        age             INTEGER,
        gender          TEXT,
        department_id   INTEGER,
        date            TEXT,
        FOREIGN KEY (department_id) REFERENCES department(department_id) ON DELETE CASCADE
    ))");


    q.exec(R"(CREATE TABLE IF NOT EXISTS appointments (
        appointment_id   INTEGER PRIMARY KEY AUTOINCREMENT,
        patient_id       INTEGER,
        doctor_id        INTEGER,
        department_id    INTEGER,
        appointment_date TEXT,
        status           TEXT DEFAULT 'Scheduled',
        FOREIGN KEY (patient_id)    REFERENCES patients(patient_id)     ON DELETE CASCADE,
        FOREIGN KEY (doctor_id)     REFERENCES doctor(doctor_id)        ON DELETE CASCADE,
        FOREIGN KEY (department_id) REFERENCES department(department_id) ON DELETE CASCADE
    ))");

    q.exec(R"(CREATE TABLE IF NOT EXISTS users (
        id       INTEGER PRIMARY KEY AUTOINCREMENT,
        username TEXT,
        password TEXT,
        role     TEXT
    ))");
}