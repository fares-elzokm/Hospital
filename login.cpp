#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "mainwindow.h"
#include "db.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    ui->btn_close->setStyleSheet(
        "QPushButton { background-color: transparent; border: none; image: url(:/img/x.svg); }"
        "QPushButton:hover { background-color: #ff0000; }"
        "QPushButton:pressed { background-color: #cc0000; }"
        );

    QString sideButtonsStyle =
        "QPushButton { background-color: transparent; border: none; }"
        "QPushButton:hover { background-color: #323940; }"
        "QPushButton:pressed { background-color: #161B22; }";

    ui->btn_min->setStyleSheet(sideButtonsStyle + "QPushButton { image: url(:/img/minus.svg); }");
}

Login::~Login()
{
    delete ui;
}

void Login::on_btn_close_clicked()
{
    this->close();
}

void Login::on_btn_min_clicked()
{
    this->showMinimized();
}

void Login::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void Login::mouseMoveEvent(QMouseEvent *event) {
    if (dragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPosition().toPoint() - dragPosition);
        event->accept();
    }
}

void Login::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    dragging = false;
}

void Login::on_btn_max_clicked()
{
}

void Login::on_btn_login_clicked()
{
    Db database;
    QString user = ui->txt_email->text();
    QString pass = ui->txt_password->text();

    if(user.isEmpty() || pass.isEmpty()){
QMessageBox::warning(this, "Login Error", "Username and password are required.");
        return;
    }

    if (!database.conDb().isOpen()) {
        database.conDb().open();
    }

    QSqlQuery query(database.conDb());
    query.prepare("SELECT role FROM users WHERE username = :user AND password = :pass");
    query.bindValue(":user", user);
    query.bindValue(":pass", pass);

    if(query.exec()) {
        if(query.next()) {
            QString role = query.value("role").toString();
            qDebug() << "Success! Logged in as:" << role;

            MainWindow *mainWin = new MainWindow(role);
            mainWin->show();
            this->close();
        } else {
QMessageBox::critical(this, "Error", "Incorrect username or password. Please try again.");        }
    } else {
        qDebug() << "Query Error:" << query.lastError().text();
QMessageBox::critical(this, "Database Error", query.lastError().text());    }
}