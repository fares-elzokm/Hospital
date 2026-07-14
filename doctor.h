#ifndef DOCTOR_H
#define DOCTOR_H

#include <QDialog>

namespace Ui {
class Doctor;
}

class Doctor : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor(int doctor_id = 0, QWidget *parent = nullptr);
    ~Doctor();

private slots:
    void on_saveButton_clicked();
    void load_data();
    void on_closeButton_clicked();
    void on_comboBoxDepartment_activated(int index);
    void loadDepartmentsFromDb();

private:
    Ui::Doctor *ui;
    QString name, gender, department, specialization, phone;
    int age;
    int CurrentDoctor_Id;
};

#endif
