#ifndef APPOINTMENTDIALOG_H
#define APPOINTMENTDIALOG_H

#include <QDialog>
#include <db.h>
#include <QSqlQuery>
#include <QDate>
#include <QMouseEvent>

namespace Ui {
class AppointmentDialog;
}

class AppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AppointmentDialog(int id = 0, QWidget *parent = nullptr);
    ~AppointmentDialog();

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void onDoctorChanged(int index);

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

private:
    Ui::AppointmentDialog *ui;
    Db curd;
    void loadData();

    int appointmentId;
    void loadAppointmentData(int id);

    bool dragging = false;
    QPoint dragPosition;
};

#endif