#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QDialog>

namespace Ui {
class Department;
}

class Department : public QDialog
{
    Q_OBJECT

public:
    explicit Department(int department_id = 0, QWidget *parent = nullptr);
    ~Department();

private slots:
    void on_saveButton_clicked();
    void load_data();
    void on_pushButton_2_clicked();

private:
    Ui::Department *ui;
    QString name, status;
    int CurrentDepartment_Id;

    void loadDepartmentNames();
};

#endif
