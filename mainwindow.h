#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QSqlQueryModel>
#include <QTableView>
#include <QApplication>
#include <QDate>
#include <db.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString role, QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onToggleButtonClicked();
    void on_close_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_homeButton_clicked();
    void on_patientsButton_clicked();
    void on_appointmentsButton_clicked();
    void on_departmentButton_clicked();
    void on_doctorButton_clicked();
    void on_pushButton_7_clicked();
    void on_settingsButton_clicked();

    void on_addPatientButton_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_PatientsSearchLineEdit_textChanged(const QString &arg1);

    void on_addDepartment_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_6_clicked();
    void on_departmentSearchLineEdit_textChanged(const QString &arg1);

    void on_addDoctorButton_clicked();
    void on_editDoctorButton_clicked();
    void on_deleteDoctorButton_clicked();
    void on_doctorSearchLineEdit_textChanged(const QString &arg1);

    void on_addAppointmentButton_clicked();
    void on_update_appointment_clicked();
    void updateAppointmentsByDate(const QDate &date);

    void on_downloadMonthlyReport_clicked();
    void on_downloadDepartmentPerformance_clicked();
    void on_btn_staff_download_clicked();
    void on_btn_financial_clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    QString currentUserRole;
    Db curd;

    bool isSidebarOpen = false;
    QPropertyAnimation *sidebarAnimation;
    void alignButtons();
    void applyPermissions();

    void tbview(QTableView *tableView);
    bool dragging = false;
    QPoint dragPosition;

    QSqlQueryModel *model            = nullptr;
    QSqlQueryModel *departmentmodel  = nullptr;
    QSqlQueryModel *doctormodel      = nullptr;
    QSqlQueryModel *appointmentmodel = nullptr;

    bool chartsBuilt = false;
    void buildDashboardCharts();
    void updateDashboardStats();
    void setupMainChart();
    void setupBarChart();
    void setupDonutChart();
    void setupVerticalBarChart();
    void updateDashboard();
    QChartView* replaceWithChart(QGraphicsView *placeholder, QChart *chart);
};

#endif