#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appointmentdialog.h"
#include "patient.h"
#include "department.h"
#include "doctor.h"
#include "login.h"

#include <QPainter>
#include <QSqlQuery>
#include <QSqlError>
#include <QStyledItemDelegate>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPdfWriter>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

class CenterTable : public QStyledItemDelegate {
public:
    explicit CenterTable(QObject *p = nullptr) : QStyledItemDelegate(p) {}
    void initStyleOption(QStyleOptionViewItem *opt, const QModelIndex &idx) const override {
        QStyledItemDelegate::initStyleOption(opt, idx);
        opt->displayAlignment = Qt::AlignCenter;
    }
};

void MainWindow::tbview(QTableView *tv)
{
    if (!tv) return;
    tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tv->verticalHeader()->hide();
    tv->verticalHeader()->setDefaultSectionSize(30);
    tv->horizontalHeader()->setStretchLastSection(true);
    tv->setEditTriggers(QTableView::NoEditTriggers);
    tv->setSelectionBehavior(QTableView::SelectRows);
    tv->setSelectionMode(QTableView::SingleSelection);
    tv->setItemDelegate(new CenterTable(tv));
}

QChartView* MainWindow::replaceWithChart(QGraphicsView *placeholder, QChart *chart)
{
    if (!placeholder) return nullptr;
    QWidget *parentWidget = placeholder->parentWidget();
    if (!parentWidget) return nullptr;
    QLayout *parentLayout = parentWidget->layout();
    if (!parentLayout) return nullptr;

    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(parentLayout);
    int row = -1, column = -1, rowSpan = 1, columnSpan = 1;

    for (int i = 0; i < parentLayout->count(); ++i) {
        QLayoutItem *item = parentLayout->itemAt(i);
        QWidget *w = item->widget();
        if (w && (w == placeholder || qobject_cast<QChartView*>(w))) {
            if (gridLayout) {
                gridLayout->getItemPosition(i, &row, &column, &rowSpan, &columnSpan);
            }

            parentLayout->removeItem(item);
            w->hide();
            if (w != placeholder) {
                w->deleteLater();
            }
            break;
        }
    }

    QChartView *cv = new QChartView(chart, parentWidget);
    cv->setRenderHint(QPainter::Antialiasing);

    if (gridLayout && row != -1) {
        gridLayout->addWidget(cv, row, column, rowSpan, columnSpan);
    } else {
        parentLayout->addWidget(cv);
    }

    cv->show();
    return cv;
}

MainWindow::MainWindow(QString role, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentUserRole(role)
{
    ui->setupUi(this);

    applyPermissions();

    appointmentmodel = new QSqlQueryModel(this);
    model            = new QSqlQueryModel(this);
    departmentmodel  = new QSqlQueryModel(this);
    doctormodel      = new QSqlQueryModel(this);

    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::updateAppointmentsByDate);
    connect(ui->toggleButton, &QPushButton::clicked, this, &MainWindow::onToggleButtonClicked);

    tbview(ui->patientsTableView);
    tbview(ui->departmentsTableView);
    tbview(ui->tableViewdoctor);
    tbview(ui->appointmentsTableView);

    alignButtons();
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    ui->contentStackWidget->setCurrentWidget(ui->homePage);

    if (!curd.conDb().isOpen()) return;

    model->setQuery("SELECT patient_id, name, age, gender, phone, medical_history, date FROM patients", curd.conDb());
    ui->patientsTableView->setModel(model);

    departmentmodel->setQuery("SELECT department_id, name, status, date FROM department", curd.conDb());
    ui->departmentsTableView->setModel(departmentmodel);

    doctormodel->setQuery(
        "SELECT d.doctor_id, d.name, d.age, d.gender, dept.name AS Department, d.date "
        "FROM doctor d LEFT JOIN department dept ON d.department_id = dept.department_id",
        curd.conDb()
        );
    ui->tableViewdoctor->setModel(doctormodel);

    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    updateAppointmentsByDate(QDate::currentDate());

    sidebarAnimation = new QPropertyAnimation(ui->sidebar, "minimumWidth", this);
    sidebarAnimation->setDuration(200);

    chartsBuilt = false;
    buildDashboardCharts();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buildDashboardCharts()
{
    if (chartsBuilt) {
        updateDashboard();
        return;
    }
    setupMainChart();
    setupBarChart();
    setupDonutChart();
    setupVerticalBarChart();
    updateDashboardStats();
    chartsBuilt = true;
}

void MainWindow::updateDashboardStats()
{
    QSqlQuery q(curd.conDb());
    int newToday = 0;
    q.prepare("SELECT COUNT(*) FROM patients WHERE DATE(date) = :d");
    q.bindValue(":d", QDate::currentDate().toString("yyyy-MM-dd"));
    if (q.exec() && q.next()) newToday = q.value(0).toInt();

    ui->mainChartTitle->setText(QString("<span style='color:#00F6FF;'>%1</span> New Patients Today").arg(newToday));
    ui->mainChartTitle->repaint();
}

void MainWindow::updateDashboard()
{
    updateDashboardStats();
    setupMainChart();
    setupBarChart();
    setupDonutChart();
    setupVerticalBarChart();
}

void MainWindow::setupMainChart()
{
    QSqlQuery q(curd.conDb());
    int male = 0, female = 0;
    if (q.exec("SELECT gender, COUNT(*) FROM patients GROUP BY gender")) {
        while (q.next()) {
            QString g = q.value(0).toString().toLower();
            if (g == "male") male = q.value(1).toInt();
            else if (g == "female") female = q.value(1).toInt();
        }
    }
    int total = male + female;

    QBarSet *set = new QBarSet("Patients");
    set->setColor(QColor(0x00F6FF));
    *set << 0 << 0 << 0;

    QBarSeries *series = new QBarSeries();
    series->append(set);
    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->setTitle("Patient Gender Distribution");
    chart->setTitleBrush(QBrush(QColor(0xE6EDF3)));
    chart->setBackgroundBrush(QBrush(QColor(0x161B22)));
    chart->legend()->setVisible(false);

    QStringList cats; cats << "Male" << "Female" << "Total";
    auto *axisX = new QBarCategoryAxis(); axisX->append(cats);
    axisX->setLabelsColor(QColor(0xE6EDF3));
    chart->addAxis(axisX, Qt::AlignBottom); series->attachAxis(axisX);

    auto *axisY = new QValueAxis();
    axisY->setRange(0, (total == 0 ? 10 : total + 2));
    axisY->setLabelsColor(QColor(0xE6EDF3));
    axisY->setGridLineColor(QColor(0x21262D));
    chart->addAxis(axisY, Qt::AlignLeft); series->attachAxis(axisY);

    replaceWithChart(ui->mainChartPlaceholder, chart);

    QVariantAnimation *anim = new QVariantAnimation(this);
    anim->setDuration(1800);
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->setEasingCurve(QEasingCurve::OutCubic);

connect(anim, &QVariantAnimation::valueChanged, this, [set, male, female, total](const QVariant &val) {
        double progress = val.toDouble();
        set->replace(0, male * progress);
        set->replace(1, female * progress);
        set->replace(2, total * progress);
    });
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::setupBarChart()
{
    QBarSet *set = new QBarSet("Patients");
    set->setColor(QColor(0x00F6FF));
    QStringList months;
    QDate today = QDate::currentDate();
    int maxVal = 0;

    for (int i = 2; i >= 0; --i) {
        QDate d = today.addMonths(-i);
        months << d.toString("MMM");

        QSqlQuery q(curd.conDb());
        q.prepare("SELECT COUNT(*) FROM patients WHERE strftime('%Y-%m', date) = :ym");
        q.bindValue(":ym", d.toString("yyyy-MM"));

        int n = 0;
        if (q.exec() && q.next()) n = q.value(0).toInt();
        if (n > maxVal) maxVal = n;
        *set << n;
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(series);
    chart->setTitle("Last 3 Months Admissions");
    chart->setTitleBrush(QBrush(QColor(0xE6EDF3)));
    chart->setBackgroundBrush(QBrush(QColor(0x161B22)));
    chart->legend()->hide();

    auto *axisX = new QBarCategoryAxis();
    axisX->append(months);
    axisX->setLabelsColor(QColor(0xE6EDF3));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto *axisY = new QValueAxis();
    axisY->setRange(0, (maxVal < 5 ? 10 : maxVal + (maxVal * 0.2)));
    axisY->setLabelsColor(QColor(0xE6EDF3));
    axisY->setGridLineColor(QColor(0x21262D));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    replaceWithChart(ui->barChartPlaceholder, chart);
}

void MainWindow::setupDonutChart()
{
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.40);
    QStringList colors = {"#00F6FF","#4E535A","#8A929B","#21262D","#30A0FF"};
    int ci = 0;
    bool hasData = false;

    QSqlQuery q(curd.conDb());
    QString queryStr = "SELECT d.name, COUNT(*) FROM appointments a "
                       "INNER JOIN department d ON a.department_id = d.department_id "
                       "GROUP BY a.department_id ORDER BY 2 DESC LIMIT 5";

    if (q.exec(queryStr)) {
        while (q.next()) {
            QString dept = q.value(0).toString();
            if (dept.isEmpty()) continue;
            series->append(dept, q.value(1).toInt())->setBrush(QColor(colors[ci++ % colors.size()]));
            hasData = true;
        }
    }

    if (!hasData) series->append("No Data", 1)->setBrush(QColor(0x4E535A));

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Top 5 Departments");
    chart->setTitleBrush(QBrush(QColor(0xE6EDF3)));
    chart->legend()->setLabelColor(QColor(0xE6EDF3));
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setBackgroundBrush(QBrush(QColor(0x161B22)));

    replaceWithChart(ui->donutChartPlaceholder, chart);

    series->setPieStartAngle(0);
    series->setPieEndAngle(0);

    QVariantAnimation *donutAnim = new QVariantAnimation(this);
    donutAnim->setDuration(2500);
    donutAnim->setStartValue(0.0);
    donutAnim->setEndValue(360.0);
    donutAnim->setEasingCurve(QEasingCurve::InOutBack);
    connect(donutAnim, &QVariantAnimation::valueChanged, this, [series](const QVariant &val) {
        series->setPieEndAngle(val.toDouble());
    });
    donutAnim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::setupVerticalBarChart()
{
    QBarSet *set = new QBarSet("Appointments");
    set->setColor(QColor(0x00F6FF));
    QStringList names;
    int maxVal = 0;

    QSqlQuery q(curd.conDb());
    if (q.exec("SELECT d.name, COUNT(a.appointment_id) as cnt FROM doctor d "
               "LEFT JOIN appointments a ON d.doctor_id = a.doctor_id "
               "GROUP BY d.doctor_id ORDER BY cnt DESC LIMIT 5")) {
        while (q.next()) {
            int val = q.value(1).toInt();
            if (val > maxVal) maxVal = val;
            QString name = q.value(0).toString();
            names << (name.contains(" ") ? name.split(" ")[0] : name);
            *set << val;
        }
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);
    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(series);
    chart->setTitle("Top 5 Doctors");
    chart->setTitleBrush(QBrush(QColor(0xE6EDF3)));
    chart->setBackgroundBrush(QBrush(QColor(0x161B22)));
    chart->legend()->hide();

    auto *axisX = new QBarCategoryAxis();
    axisX->append(names);
    axisX->setLabelsColor(QColor(0xE6EDF3));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto *axisY = new QValueAxis();
    axisY->setRange(0, (maxVal < 5 ? 10 : maxVal + (maxVal * 0.2)));
    axisY->setLabelsColor(QColor(0xE6EDF3));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    replaceWithChart(ui->verticalBarPlaceholder, chart);
}

void MainWindow::alignButtons()
{
    for (int i = 0; i < ui->sidebarLayout->count(); ++i) {
        QWidget *w = ui->sidebarLayout->itemAt(i)->widget();
        if (auto *btn = qobject_cast<QPushButton*>(w))
            btn->setLayoutDirection(Qt::LeftToRight);
    }
}

void MainWindow::onToggleButtonClicked()
{
    sidebarAnimation->setEndValue(isSidebarOpen ? 60 : 200);
    sidebarAnimation->start();
    isSidebarOpen = !isSidebarOpen;
}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton && ui->topbar->geometry().contains(e->pos())) {
        dragging = true;
        dragPosition = e->globalPosition().toPoint() - frameGeometry().topLeft();
        e->accept();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    if (dragging && (e->buttons() & Qt::LeftButton)) {
        move(e->globalPosition().toPoint() - dragPosition);
        e->accept();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *) { dragging = false; }

void MainWindow::on_close_clicked()         { QApplication::closeAllWindows(); }
void MainWindow::on_pushButton_2_clicked() { isMaximized() ? showNormal() : showMaximized(); }
void MainWindow::on_pushButton_3_clicked() { showMinimized(); }

void MainWindow::on_homeButton_clicked() {
    ui->contentStackWidget->setCurrentWidget(ui->homePage);

    updateDashboardStats();

    if (!chartsBuilt) {
        buildDashboardCharts();
    }
}
void MainWindow::on_patientsButton_clicked() {
    ui->contentStackWidget->setCurrentWidget(ui->patientsPage);
    QString qStr = model->query().lastQuery();
    if (qStr.isEmpty()) {
        qStr = "SELECT patient_id, name, age, gender, phone, medical_history, date FROM patients";
    }
    model->setQuery(qStr, curd.conDb());
}
void MainWindow::on_appointmentsButton_clicked(){
    ui->contentStackWidget->setCurrentWidget(ui->appointmentsPage);
    updateAppointmentsByDate(ui->calendarWidget->selectedDate());
}
void MainWindow::on_departmentButton_clicked() { ui->contentStackWidget->setCurrentWidget(ui->department); }
void MainWindow::on_doctorButton_clicked()     { ui->contentStackWidget->setCurrentWidget(ui->doctor); }
void MainWindow::on_pushButton_7_clicked() {
    ui->contentStackWidget->setCurrentWidget(ui->reportPage);
    QString qStr = model->query().lastQuery();
    if (qStr.isEmpty()) {
        qStr = "SELECT patient_id, name, age, gender, phone, medical_history, date FROM patients";
    }
    model->setQuery(qStr, curd.conDb());
}

void MainWindow::on_addPatientButton_clicked()
{
    Patient dlg(0, this);
    if (dlg.exec() == QDialog::Accepted) {
        model->setQuery(model->query().lastQuery(), curd.conDb());
        updateDashboard();
    }
}

void MainWindow::on_pushButton_clicked()
{
    auto sel = ui->patientsTableView->selectionModel()->selectedRows();
    if (sel.isEmpty()) return;
    Patient dlg(model->data(sel.at(0).siblingAtColumn(0)).toInt(), this);
    if (dlg.exec() == QDialog::Accepted) {
        model->setQuery(model->query().lastQuery(), curd.conDb());
        updateDashboard();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    auto rows = ui->patientsTableView->selectionModel()->selectedRows();
    if (rows.isEmpty()) { QMessageBox::warning(this,"Warning","Select a patient."); return; }
    if (QMessageBox::question(this,"Confirm","Delete this patient?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::No) return;

    QSqlQuery q(curd.conDb());
    q.prepare("DELETE FROM patients WHERE patient_id = :id");
    q.bindValue(":id", model->data(rows.at(0).siblingAtColumn(0)).toInt());
    if (q.exec()) {
        model->setQuery(model->query().lastQuery(), curd.conDb());
        updateDashboard();
    }
}

void MainWindow::on_addDepartment_clicked()
{
    Department dlg(0, this);
    if (dlg.exec() == QDialog::Accepted) departmentmodel->setQuery(departmentmodel->query().lastQuery(), curd.conDb());
}

void MainWindow::on_pushButton_8_clicked()
{
    auto sel = ui->departmentsTableView->selectionModel()->selectedRows();
    if (sel.isEmpty()) return;
    Department dlg(departmentmodel->data(sel.at(0).siblingAtColumn(0)).toInt(), this);
    if (dlg.exec() == QDialog::Accepted) departmentmodel->setQuery(departmentmodel->query().lastQuery(), curd.conDb());
}

void MainWindow::on_pushButton_6_clicked()
{
    auto rows = ui->departmentsTableView->selectionModel()->selectedRows();
    if (rows.isEmpty()) return;
    QSqlQuery q(curd.conDb());
    q.prepare("DELETE FROM department WHERE department_id = :id");
    q.bindValue(":id", departmentmodel->data(rows.at(0).siblingAtColumn(0)).toInt());
    if (q.exec()) departmentmodel->setQuery(departmentmodel->query().lastQuery(), curd.conDb());
}

void MainWindow::on_addDoctorButton_clicked()
{
    Doctor dlg(0, this);
    if (dlg.exec() == QDialog::Accepted) {
        doctormodel->setQuery(doctormodel->query().lastQuery(), curd.conDb());
        updateDashboard();
    }
}

void MainWindow::on_editDoctorButton_clicked()
{
    auto sel = ui->tableViewdoctor->selectionModel()->selectedRows();
    if (sel.isEmpty()) return;
    Doctor dlg(doctormodel->data(sel.at(0).siblingAtColumn(0)).toInt(), this);
    if (dlg.exec() == QDialog::Accepted) {
        doctormodel->setQuery(doctormodel->query().lastQuery(), curd.conDb());
        updateDashboard();
    }
}

void MainWindow::on_deleteDoctorButton_clicked()
{
    auto rows = ui->tableViewdoctor->selectionModel()->selectedRows();
    if (rows.isEmpty()) return;
    QSqlQuery q(curd.conDb());
    q.prepare("DELETE FROM doctor WHERE doctor_id = :id");
    q.bindValue(":id", doctormodel->data(rows.at(0).siblingAtColumn(0)).toInt());
    if (q.exec()) {
        doctormodel->setQuery(doctormodel->query().lastQuery(), curd.conDb());
        updateDashboard();
    }
}

void MainWindow::updateAppointmentsByDate(const QDate &date)
{
    QString selectedDate = date.toString("yyyy-MM-dd");
    QSqlQuery q(curd.conDb());
    q.prepare("SELECT a.appointment_id, p.name AS Patient, d.name AS Doctor, dept.name AS Department, a.status "
              "FROM appointments a "
              "LEFT JOIN patients p ON a.patient_id = p.patient_id "
              "LEFT JOIN doctor d ON a.doctor_id = d.doctor_id "
              "LEFT JOIN department dept ON a.department_id = dept.department_id "
              "WHERE DATE(a.appointment_date) = :date");
    q.bindValue(":date", selectedDate);

    if(q.exec()) {
        appointmentmodel->setQuery(std::move(q));
        ui->appointmentsTableView->setModel(appointmentmodel);
    }
}

void MainWindow::on_addAppointmentButton_clicked()
{
    AppointmentDialog dlg(0, this);
    if (dlg.exec() == QDialog::Accepted) {
        updateAppointmentsByDate(ui->calendarWidget->selectedDate());
        updateDashboard();
    }
}

void MainWindow::on_update_appointment_clicked()
{
    auto sel = ui->appointmentsTableView->selectionModel()->selectedRows();
    if (sel.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select an appointment from the table first.");
        return;
    }
    int appointmentId = appointmentmodel->data(sel.at(0).siblingAtColumn(0)).toInt();
    AppointmentDialog dlg(appointmentId, this);
    if (dlg.exec() == QDialog::Accepted) {
        updateAppointmentsByDate(ui->calendarWidget->selectedDate());
        updateDashboard();
    }
}


void MainWindow::on_downloadMonthlyReport_clicked()
{
    int totalPatients = 0, malePatients = 0, femalePatients = 0, totalAppointments = 0;
    QSqlQuery query(curd.conDb());

    if(query.exec("SELECT COUNT(*) FROM patients") && query.next()) totalPatients = query.value(0).toInt();
    if(query.exec("SELECT COUNT(*) FROM patients WHERE gender='Male'") && query.next()) malePatients = query.value(0).toInt();
    if(query.exec("SELECT COUNT(*) FROM patients WHERE gender='Female'") && query.next()) femalePatients = query.value(0).toInt();
    if(query.exec("SELECT COUNT(*) FROM appointments") && query.next()) totalAppointments = query.value(0).toInt();

    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF Report", "Monthly_Patient_Report.pdf", "PDF Files (*.pdf)");
    if(fileName.isEmpty()) return;

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);
    QPainter painter(&pdf);

    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.drawText(200, 300, "Monthly Patient Report");
    painter.setFont(QFont("Arial", 11));
    painter.drawText(200, 500, "Date: " + QDate::currentDate().toString("yyyy-MM-dd"));
    painter.drawLine(200, 600, 2200, 600);

    painter.setFont(QFont("Arial", 13));
    int y = 900;
    painter.drawText(250, y, "Total Patients: " + QString::number(totalPatients)); y += 250;
    painter.drawText(250, y, "Male Patients: " + QString::number(malePatients)); y += 250;
    painter.drawText(250, y, "Female Patients: " + QString::number(femalePatients)); y += 250;
    painter.drawText(250, y, "Total Appointments: " + QString::number(totalAppointments)); y += 400;

    painter.setFont(QFont("Arial", 10));
    painter.drawText(250, y, "Generated by Hospital Management System");
    painter.end();

    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

void MainWindow::on_downloadDepartmentPerformance_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Department Report", "Department_Performance.pdf", "PDF Files (*.pdf)");
    if(fileName.isEmpty()) return;

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);
    QPainter painter(&pdf);

    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.drawText(200, 300, "Department Performance Report");
    painter.setFont(QFont("Arial", 11));
    painter.drawText(200, 500, "Date: " + QDate::currentDate().toString("yyyy-MM-dd"));
    painter.drawLine(200, 600, 2200, 600);

    painter.setFont(QFont("Arial", 12, QFont::Bold));
    int y = 900;
    painter.drawText(200, y, "Department");
    painter.drawText(1000, y, "Doctors");
    painter.drawText(1500, y, "Appointments");
    painter.drawText(2200, y, "Status");
    y += 150;
    painter.drawLine(200, y, 2600, y);
    y += 200;

    QSqlQuery deptQuery("SELECT department_id, name FROM department", curd.conDb());
    painter.setFont(QFont("Arial", 11));

    while(deptQuery.next()) {
        int deptId = deptQuery.value(0).toInt();
        QString deptName = deptQuery.value(1).toString();

        int doctorCount = 0, appointmentCount = 0;
        QSqlQuery q1(curd.conDb());
        q1.prepare("SELECT COUNT(*) FROM doctor WHERE department_id = :dept_id");
        q1.bindValue(":dept_id", deptId);
        if(q1.exec() && q1.next()) doctorCount = q1.value(0).toInt();

        QSqlQuery q2(curd.conDb());
        q2.prepare("SELECT COUNT(*) FROM appointments WHERE department_id = :dept_id");
        q2.bindValue(":dept_id", deptId);
        if(q2.exec() && q2.next()) appointmentCount = q2.value(0).toInt();

        QString status = (appointmentCount >= 20) ? "High" : (appointmentCount >= 10 ? "Medium" : "Low");

        painter.drawText(200, y, deptName);
        painter.drawText(1050, y, QString::number(doctorCount));
        painter.drawText(1600, y, QString::number(appointmentCount));
        painter.drawText(2200, y, status);
        y += 220;

        if(y > 10000) { pdf.newPage(); y = 500; }
    }

    y += 300;
    painter.drawLine(200, y, 2600, y); y += 200;
    painter.drawText(200, y, "Generated by Hospital Management System");
    painter.end();

    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

void MainWindow::on_btn_staff_download_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Report", "Staff_Performance_Report.pdf", "PDF Files (*.pdf)");
    if(fileName.isEmpty()) return;

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);
    QPainter painter(&pdf);

    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(200, 300, "Staff Performance Report");
    painter.drawLine(200, 500, 3100, 500);

    int y = 850;
    painter.setFont(QFont("Arial", 8, QFont::Bold));
    painter.drawText(200, y,  "Doctor");
    painter.drawText(600, y,  "Department");
    painter.drawText(1000, y, "Tasks");
    painter.drawText(1400, y, "Completed");
    painter.drawText(1800, y, "Scheduled");
    painter.drawText(2200, y, "Cancelled");

    painter.drawLine(200, y + 100, 3150, y + 100);
    y += 350;

    QSqlQuery query(curd.conDb());
    query.prepare("SELECT d.name, dept.name AS dept_name, "
                  "(SELECT COUNT(*) FROM appointments a WHERE a.doctor_id = d.doctor_id) as tasks_count, "
                  "(SELECT COUNT(*) FROM appointments a WHERE a.doctor_id = d.doctor_id AND a.status = 'Completed') as comp_count, "
                  "(SELECT COUNT(*) FROM appointments a WHERE a.doctor_id = d.doctor_id AND a.status = 'Scheduled') as sched_count, "
                  "(SELECT COUNT(*) FROM appointments a WHERE a.doctor_id = d.doctor_id AND a.status = 'Cancelled') as canc_count "
                  "FROM doctor d LEFT JOIN department dept ON d.department_id = dept.department_id");

    painter.setFont(QFont("Arial", 8));
    if(query.exec()) {
        while(query.next()) {
            painter.drawText(200, y,  query.value(0).toString());
            painter.drawText(625, y,  query.value(1).toString());
            painter.drawText(1050, y, QString::number(query.value(2).toInt()));
            painter.drawText(1500, y, QString::number(query.value(3).toInt()));
            painter.drawText(1900, y, QString::number(query.value(4).toInt()));
            painter.drawText(2275, y, QString::number(query.value(5).toInt()));
            y += 200;
            if(y > 13000) { pdf.newPage(); y = 500; }
        }
    }
    painter.end();
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

void MainWindow::on_btn_financial_clicked()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("System Update");
    msgBox.setText("<b>Financial Summary Q1</b><br><br>This feature will be available in the next update.");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setStyleSheet("QLabel{ color: white; font-size: 14px; } "
                         "QMessageBox { background-color: #2b2b2b; border: 1px solid #555; } "
                         "QPushButton { background-color: #3d3d3d; color: white; border-radius: 5px; padding: 5px 15px; }");
    msgBox.exec();
}

void MainWindow::applyPermissions()
{
    if (currentUserRole.toLower() != "admin") {
        ui->pushButton_6->hide();
        ui->deleteDoctorButton->hide();
        ui->pushButton_7->hide();
    }
}

void MainWindow::on_settingsButton_clicked()
{
    Login *login = new Login();
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
    this->close();
}


void MainWindow::on_PatientsSearchLineEdit_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        model->setQuery("SELECT patient_id, name, age, gender, phone, medical_history, date FROM patients", curd.conDb());
        return;
    }
    QSqlQuery query(curd.conDb());
    query.prepare("SELECT patient_id, name, age, gender, phone, medical_history, date "
                  "FROM patients WHERE patient_id = :id OR name LIKE :name");
    query.bindValue(":id", arg1);
    query.bindValue(":name", "%" + arg1 + "%");

    if (query.exec()) model->setQuery(std::move(query));
}

void MainWindow::on_doctorSearchLineEdit_textChanged(const QString &arg1)
{
    QString baseQuery = "SELECT d.doctor_id, d.name, d.age, d.gender, dept.name AS Department, d.date "
                        "FROM doctor d LEFT JOIN department dept ON d.department_id = dept.department_id";

    if (arg1.isEmpty()) {
        doctormodel->setQuery(baseQuery, curd.conDb());
        return;
    }
    QSqlQuery query(curd.conDb());
    query.prepare(baseQuery + " WHERE d.doctor_id = :id OR d.name LIKE :name");
    query.bindValue(":id", arg1.toInt());
    query.bindValue(":name", "%" + arg1 + "%");

    if (query.exec()) doctormodel->setQuery(std::move(query));
}

void MainWindow::on_departmentSearchLineEdit_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        departmentmodel->setQuery("SELECT department_id, name, status, date FROM department", curd.conDb());
        return;
    }
    QSqlQuery query(curd.conDb());
    query.prepare("SELECT department_id, name, status, date FROM department WHERE department_id = :id OR name LIKE :name");
    query.bindValue(":id", arg1);
    query.bindValue(":name", "%" + arg1 + "%");

    if (query.exec()) departmentmodel->setQuery(std::move(query));
}