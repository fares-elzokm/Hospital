#ifndef PATIENT_H
#define PATIENT_H

#include <QDialog>

namespace Ui {
class Patient;
}

class Patient : public QDialog
{
    Q_OBJECT

public:
    explicit Patient(int patient_id = 0, QWidget *parent = nullptr);
    ~Patient();

private slots:
    void on_saveButton_clicked();
    void load_data();
    void on_closeButton_clicked();

private:
    Ui::Patient *ui;
    QString name, gender, history;
    double phone;
    int age;
    int CurrentPatient_Id;
};

#endif
