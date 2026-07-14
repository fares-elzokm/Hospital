/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *sidebar;
    QVBoxLayout *sidebarLayout;
    QPushButton *toggleButton;
    QPushButton *homeButton;
    QPushButton *patientsButton;
    QPushButton *doctorButton;
    QPushButton *departmentButton;
    QPushButton *appointmentsButton;
    QPushButton *pushButton_7;
    QSpacerItem *verticalSpacer;
    QPushButton *settingsButton;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *topbar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *close;
    QFrame *content;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *contentStackWidget;
    QWidget *homePage;
    QGridLayout *gridLayout;
    QFrame *mainChartFrame;
    QVBoxLayout *mainChartLayout;
    QHBoxLayout *hboxLayout;
    QLabel *mainChartTitle;
    QSpacerItem *spacerItem;
    QGraphicsView *mainChartPlaceholder;
    QFrame *barChartFrame;
    QVBoxLayout *barChartLayout;
    QLabel *barChartTitle;
    QGraphicsView *barChartPlaceholder;
    QFrame *donutChartFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QGraphicsView *donutChartPlaceholder;
    QFrame *verticalBarFrame;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QGraphicsView *verticalBarPlaceholder;
    QWidget *department;
    QVBoxLayout *verticalLayout_10;
    QLabel *departmentTitle;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addDepartment;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *departmentSearchLineEdit;
    QTableView *departmentsTableView;
    QWidget *doctor;
    QVBoxLayout *verticalLayout_11;
    QLabel *docterTitle;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *addDoctorButton;
    QPushButton *editDoctorButton;
    QPushButton *deleteDoctorButton;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *doctorSearchLineEdit;
    QTableView *tableViewdoctor;
    QWidget *patientsPage;
    QVBoxLayout *verticalLayout_3;
    QLabel *pageTitle_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addPatientButton;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *PatientsSearchLineEdit;
    QTableView *patientsTableView;
    QWidget *reportPage;
    QLabel *label_84;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QFrame *frame_26;
    QLabel *label_68;
    QLabel *label_69;
    QLabel *label_70;
    QFrame *frame_27;
    QLabel *label_71;
    QPushButton *btn_staff_download;
    QFrame *frame_28;
    QLabel *label_72;
    QLabel *label_73;
    QLabel *label_74;
    QFrame *frame_29;
    QLabel *label_75;
    QPushButton *downloadMonthlyReport;
    QFrame *frame_30;
    QLabel *label_76;
    QLabel *label_77;
    QLabel *label_78;
    QPushButton *btn_financial;
    QFrame *frame_31;
    QLabel *label_79;
    QFrame *frame_32;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QPushButton *downloadDepartmentPerformance;
    QFrame *frame_33;
    QLabel *label_83;
    QPushButton *pushButton_35;
    QWidget *appointmentsPage;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_9;
    QLabel *pageTitle;
    QCalendarWidget *calendarWidget;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QTableView *appointmentsTableView;
    QSpacerItem *horizontalSpacer_3;
    QSplitter *splitter;
    QPushButton *addAppointmentButton;
    QPushButton *update_appointment;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(845, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("/* --- Add QSS code here --- */"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("/* --- Thor Theme QSS --- */\n"
"\n"
"/* Main Window & Central Widget */\n"
"QMainWindow, QWidget#centralwidget {\n"
"    background-color: #0D1117;\n"
"}\n"
"\n"
"/* --- Frame --- */\n"
"QWidget#frame\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"/* --- Sidebar --- */\n"
"QWidget#sidebar {\n"
"    background-color: #161B22;\n"
"	border-radius: 10px;\n"
"}\n"
"QWidget#sidebar QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #E6EDF3;\n"
"    padding: 10px;\n"
"    padding-left: 15px;\n"
"    border-radius: 5px;\n"
"    text-align: left;\n"
"}\n"
"QWidget#sidebar QPushButton:hover {\n"
"    background-color: #21262D;\n"
"}\n"
"QWidget#sidebar QPushButton:pressed,\n"
"QWidget#sidebar QPushButton:checked {\n"
"    background-color: #00F6FF;\n"
"    color: #0D1117;\n"
"}\n"
"\n"
"/* --- Topbar --- */\n"
"QFrame#topbar {\n"
"    background-color: #161B22;\n"
"}\n"
"QFrame#topbar QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    border-ra"
                        "dius: 4px;\n"
"    padding: 5px;\n"
"    text-align: center;\n"
"}\n"
"QFrame#topbar QPushButton:hover {\n"
"    background-color: #21262D;\n"
"}\n"
"QFrame#topbar QPushButton#close:hover {\n"
"    background-color: #E81123;\n"
"}\n"
"\n"
"/* --- Main Content Area --- */\n"
"QFrame#content, QStackedWidget > QWidget {\n"
"    background-color: #0D1117;\n"
"    border: none;\n"
"}\n"
"\n"
"/* General Page Titles */\n"
"QLabel#pageTitle, QLabel#departmentTitle, QLabel#docterTitle, QLabel#pageTitle_2{\n"
"    color: #E6EDF3;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* --- Dashboard Specific Styles --- */\n"
"#homePage .QFrame {\n"
"    background-color: #161B22;\n"
"    border-radius: 12px;\n"
"}\n"
"#homePage QLabel {\n"
"    color: #E6EDF3;\n"
"    font-size: 11pt;\n"
"}\n"
"#homePage #mainChartTitle, #homePage #barChartTitle {\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"}\n"
"#homePage QProgressBar {\n"
"    border: 1px solid #21262D;\n"
"    border-ra"
                        "dius: 5px;\n"
"    text-align: center;\n"
"    color: #E6EDF3;\n"
"    background-color: #0D1117;\n"
"}\n"
"#homePage QProgressBar::chunk {\n"
"    background-color: #00F6FF;\n"
"    border-radius: 4px;\n"
"}\n"
"#homePage #op1Button, #homePage #op2Button {\n"
"    background-color: #00F6FF;\n"
"    color: #0D1117;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* --- Patients & Appointments Page Styles --- */\n"
"#patientsPage QPushButton, #appointmentsPage QPushButton {\n"
"    background-color: #00F6FF;\n"
"    color: #0D1117;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font-weight: bold;\n"
"}\n"
"#patientsPage QPushButton:hover, #appointmentsPage QPushButton:hover {\n"
"    background-color: #33fdff;\n"
"}\n"
"\n"
"/* --- Department --- */\n"
"#department QPushButton, #addDepartment QPushButton {\n"
"    background-color: #00F6FF;\n"
"    color: #0D1117;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font-weight: bold;\n"
""
                        "}\n"
"#department QPushButton:hover, #addDepartment QPushButton:hover {\n"
"    background-color: #33fdff;\n"
"}\n"
"\n"
"#doctor QPushButton, #docterPage QPushButton {\n"
"    background-color: #00F6FF;\n"
"    color: #0D1117;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font-weight: bold;\n"
"}\n"
"#doctor QPushButton:hover, #docterPage QPushButton:hover {\n"
"    background-color: #33fdff;\n"
"}\n"
"\n"
"/* --- Table View --- */\n"
"QTableView {\n"
"    background-color: #161B22;\n"
"    border: 1px solid #21262D;\n"
"    border-radius: 8px;\n"
"    gridline-color: #21262D;\n"
"    color: #E6EDF3;\n"
"}\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"    border-bottom: 1px solid #21262D;\n"
"}\n"
"QTableView::item:selected {\n"
"    background-color: #00F6FF;\n"
"    color: #0D1117;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #0D1117;\n"
"    color: #E6EDF3;\n"
"    padding: 5px;\n"
"    border: 1px solid #21262D;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* --- Line Edit ("
                        "Search Bar) --- */\n"
"QLineEdit {\n"
"    background-color: #0D1117;\n"
"    border: 1px solid #21262D;\n"
"    border-radius: 5px;\n"
"    padding: 8px 10px;\n"
"    color: #E6EDF3;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #00F6FF;\n"
"}\n"
"\n"
"/* --- Calendar Widget --- */\n"
"QCalendarWidget QToolButton {\n"
"    color: #E6EDF3;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: #21262D;\n"
"}\n"
"QCalendarWidget QMenu {\n"
"    background-color: #161B22;\n"
"}\n"
"QCalendarWidget QSpinBox {\n"
"    color: #E6EDF3;\n"
"}\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"    background-color: #161B22;\n"
"    border: 1px solid #21262D;\n"
"    border-bottom: none;\n"
"    border-radius: 8px 8px 0 0;\n"
"}\n"
"QCalendarWidget QAbstractItemView {\n"
"    background-color: #0D1117;\n"
"    color: #E6EDF3;\n"
"    selection-background-color: #00F6FF;\n"
"    "
                        "selection-color: #0D1117;\n"
"    border: 1px solid #21262D;\n"
"    border-top: none;\n"
"    border-radius: 0 0 8px 8px;\n"
"}\n"
"QCalendarWidget QAbstractItemView:disabled {\n"
"    color: #4E535A;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(8, 8, 8, 8);
        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setMinimumSize(QSize(60, 0));
        sidebar->setMaximumSize(QSize(60, 16777215));
        sidebarLayout = new QVBoxLayout(sidebar);
        sidebarLayout->setSpacing(8);
        sidebarLayout->setObjectName("sidebarLayout");
        sidebarLayout->setContentsMargins(8, 8, 8, 8);
        toggleButton = new QPushButton(sidebar);
        toggleButton->setObjectName("toggleButton");
        toggleButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Dashboard1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toggleButton->setIcon(icon);
        toggleButton->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(toggleButton);

        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Dashboard.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon1);
        homeButton->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(homeButton);

        patientsButton = new QPushButton(sidebar);
        patientsButton->setObjectName("patientsButton");
        patientsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/Patients.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        patientsButton->setIcon(icon2);
        patientsButton->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(patientsButton);

        doctorButton = new QPushButton(sidebar);
        doctorButton->setObjectName("doctorButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/Docter.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        doctorButton->setIcon(icon3);
        doctorButton->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(doctorButton);

        departmentButton = new QPushButton(sidebar);
        departmentButton->setObjectName("departmentButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/Department.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        departmentButton->setIcon(icon4);
        departmentButton->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(departmentButton);

        appointmentsButton = new QPushButton(sidebar);
        appointmentsButton->setObjectName("appointmentsButton");
        appointmentsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/Appointments.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        appointmentsButton->setIcon(icon5);
        appointmentsButton->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(appointmentsButton);

        pushButton_7 = new QPushButton(sidebar);
        pushButton_7->setObjectName("pushButton_7");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/Report.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(pushButton_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebarLayout->addItem(verticalSpacer);

        settingsButton = new QPushButton(sidebar);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/logout.jfif"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingsButton->setIcon(icon7);
        settingsButton->setIconSize(QSize(24, 24));

        sidebarLayout->addWidget(settingsButton);


        horizontalLayout->addWidget(sidebar);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topbar = new QFrame(frame);
        topbar->setObjectName("topbar");
        topbar->setMaximumSize(QSize(16777215, 40));
        topbar->setFrameShape(QFrame::Shape::StyledPanel);
        topbar->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(topbar);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(topbar);
        pushButton_3->setObjectName("pushButton_3");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/minus.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon8);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(topbar);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/maximize.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon9);

        horizontalLayout_2->addWidget(pushButton_2);

        close = new QPushButton(topbar);
        close->setObjectName("close");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        close->setIcon(icon10);

        horizontalLayout_2->addWidget(close);


        verticalLayout->addWidget(topbar);

        content = new QFrame(frame);
        content->setObjectName("content");
        content->setFrameShape(QFrame::Shape::StyledPanel);
        content->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(content);
        verticalLayout_4->setObjectName("verticalLayout_4");
        contentStackWidget = new QStackedWidget(content);
        contentStackWidget->setObjectName("contentStackWidget");
        homePage = new QWidget();
        homePage->setObjectName("homePage");
        gridLayout = new QGridLayout(homePage);
        gridLayout->setObjectName("gridLayout");
        mainChartFrame = new QFrame(homePage);
        mainChartFrame->setObjectName("mainChartFrame");
        mainChartLayout = new QVBoxLayout(mainChartFrame);
        mainChartLayout->setObjectName("mainChartLayout");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        mainChartTitle = new QLabel(mainChartFrame);
        mainChartTitle->setObjectName("mainChartTitle");

        hboxLayout->addWidget(mainChartTitle);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout->addItem(spacerItem);


        mainChartLayout->addLayout(hboxLayout);

        mainChartPlaceholder = new QGraphicsView(mainChartFrame);
        mainChartPlaceholder->setObjectName("mainChartPlaceholder");
        mainChartPlaceholder->setStyleSheet(QString::fromUtf8(""));

        mainChartLayout->addWidget(mainChartPlaceholder);


        gridLayout->addWidget(mainChartFrame, 0, 0, 1, 1);

        barChartFrame = new QFrame(homePage);
        barChartFrame->setObjectName("barChartFrame");
        barChartLayout = new QVBoxLayout(barChartFrame);
        barChartLayout->setObjectName("barChartLayout");
        barChartTitle = new QLabel(barChartFrame);
        barChartTitle->setObjectName("barChartTitle");

        barChartLayout->addWidget(barChartTitle);

        barChartPlaceholder = new QGraphicsView(barChartFrame);
        barChartPlaceholder->setObjectName("barChartPlaceholder");
        barChartPlaceholder->setStyleSheet(QString::fromUtf8(""));

        barChartLayout->addWidget(barChartPlaceholder);


        gridLayout->addWidget(barChartFrame, 0, 1, 1, 1);

        donutChartFrame = new QFrame(homePage);
        donutChartFrame->setObjectName("donutChartFrame");
        verticalLayout_5 = new QVBoxLayout(donutChartFrame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label = new QLabel(donutChartFrame);
        label->setObjectName("label");

        verticalLayout_5->addWidget(label);

        donutChartPlaceholder = new QGraphicsView(donutChartFrame);
        donutChartPlaceholder->setObjectName("donutChartPlaceholder");
        donutChartPlaceholder->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(donutChartPlaceholder);


        gridLayout->addWidget(donutChartFrame, 1, 0, 1, 1);

        verticalBarFrame = new QFrame(homePage);
        verticalBarFrame->setObjectName("verticalBarFrame");
        verticalLayout_6 = new QVBoxLayout(verticalBarFrame);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_2 = new QLabel(verticalBarFrame);
        label_2->setObjectName("label_2");

        verticalLayout_6->addWidget(label_2);

        verticalBarPlaceholder = new QGraphicsView(verticalBarFrame);
        verticalBarPlaceholder->setObjectName("verticalBarPlaceholder");
        verticalBarPlaceholder->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(verticalBarPlaceholder);


        gridLayout->addWidget(verticalBarFrame, 1, 1, 1, 1);

        contentStackWidget->addWidget(homePage);
        department = new QWidget();
        department->setObjectName("department");
        verticalLayout_10 = new QVBoxLayout(department);
        verticalLayout_10->setObjectName("verticalLayout_10");
        departmentTitle = new QLabel(department);
        departmentTitle->setObjectName("departmentTitle");

        verticalLayout_10->addWidget(departmentTitle);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        addDepartment = new QPushButton(department);
        addDepartment->setObjectName("addDepartment");

        horizontalLayout_5->addWidget(addDepartment);

        pushButton_8 = new QPushButton(department);
        pushButton_8->setObjectName("pushButton_8");

        horizontalLayout_5->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(department);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_5->addWidget(pushButton_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        departmentSearchLineEdit = new QLineEdit(department);
        departmentSearchLineEdit->setObjectName("departmentSearchLineEdit");

        horizontalLayout_5->addWidget(departmentSearchLineEdit);


        verticalLayout_10->addLayout(horizontalLayout_5);

        departmentsTableView = new QTableView(department);
        departmentsTableView->setObjectName("departmentsTableView");

        verticalLayout_10->addWidget(departmentsTableView);

        contentStackWidget->addWidget(department);
        doctor = new QWidget();
        doctor->setObjectName("doctor");
        verticalLayout_11 = new QVBoxLayout(doctor);
        verticalLayout_11->setObjectName("verticalLayout_11");
        docterTitle = new QLabel(doctor);
        docterTitle->setObjectName("docterTitle");

        verticalLayout_11->addWidget(docterTitle);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        addDoctorButton = new QPushButton(doctor);
        addDoctorButton->setObjectName("addDoctorButton");

        horizontalLayout_6->addWidget(addDoctorButton);

        editDoctorButton = new QPushButton(doctor);
        editDoctorButton->setObjectName("editDoctorButton");

        horizontalLayout_6->addWidget(editDoctorButton);

        deleteDoctorButton = new QPushButton(doctor);
        deleteDoctorButton->setObjectName("deleteDoctorButton");

        horizontalLayout_6->addWidget(deleteDoctorButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        doctorSearchLineEdit = new QLineEdit(doctor);
        doctorSearchLineEdit->setObjectName("doctorSearchLineEdit");

        horizontalLayout_6->addWidget(doctorSearchLineEdit);


        verticalLayout_11->addLayout(horizontalLayout_6);

        tableViewdoctor = new QTableView(doctor);
        tableViewdoctor->setObjectName("tableViewdoctor");

        verticalLayout_11->addWidget(tableViewdoctor);

        contentStackWidget->addWidget(doctor);
        patientsPage = new QWidget();
        patientsPage->setObjectName("patientsPage");
        verticalLayout_3 = new QVBoxLayout(patientsPage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        pageTitle_2 = new QLabel(patientsPage);
        pageTitle_2->setObjectName("pageTitle_2");
        pageTitle_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(pageTitle_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addPatientButton = new QPushButton(patientsPage);
        addPatientButton->setObjectName("addPatientButton");

        horizontalLayout_3->addWidget(addPatientButton);

        pushButton = new QPushButton(patientsPage);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);

        pushButton_4 = new QPushButton(patientsPage);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_3->addWidget(pushButton_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        PatientsSearchLineEdit = new QLineEdit(patientsPage);
        PatientsSearchLineEdit->setObjectName("PatientsSearchLineEdit");

        horizontalLayout_3->addWidget(PatientsSearchLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        patientsTableView = new QTableView(patientsPage);
        patientsTableView->setObjectName("patientsTableView");

        verticalLayout_3->addWidget(patientsTableView);

        contentStackWidget->addWidget(patientsPage);
        reportPage = new QWidget();
        reportPage->setObjectName("reportPage");
        label_84 = new QLabel(reportPage);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(10, 30, 111, 44));
        label_84->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        scrollArea_4 = new QScrollArea(reportPage);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setGeometry(QRect(0, 70, 741, 425));
        scrollArea_4->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        scrollArea_4->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #0d1117; /* \331\204\331\210\331\206 \330\247\331\204\330\256\331\204\331\201\331\212\330\251 \330\247\331\204\330\272\330\247\331\205\331\202 \330\254\330\257\330\247\331\213 \330\262\331\212 Figma */\n"
"    border: none;\n"
"}"));
        scrollArea_4->setWidgetResizable(true);
        scrollArea_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 741, 425));
        scrollAreaWidgetContents_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        scrollAreaWidgetContents_4->setAutoFillBackground(false);
        frame_26 = new QFrame(scrollAreaWidgetContents_4);
        frame_26->setObjectName("frame_26");
        frame_26->setGeometry(QRect(370, 230, 360, 150));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_26->sizePolicy().hasHeightForWidth());
        frame_26->setSizePolicy(sizePolicy);
        frame_26->setMinimumSize(QSize(360, 150));
        frame_26->setMaximumSize(QSize(360, 150));
        frame_26->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1a1f26; \n"
"    border-radius: 15px;       \n"
"    border: 1px solid #2d343d; \n"
"}\n"
"\n"
"QFrame:hover {\n"
"    background-color: #242b35;\n"
"    border: 1px solid #00f2ff; \n"
"}\n"
"\n"
""));
        frame_26->setFrameShape(QFrame::Shape::StyledPanel);
        frame_26->setFrameShadow(QFrame::Shadow::Raised);
        label_68 = new QLabel(frame_26);
        label_68->setObjectName("label_68");
        label_68->setGeometry(QRect(70, 110, 137, 20));
        label_68->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14\n"
"px;"));
        label_69 = new QLabel(frame_26);
        label_69->setObjectName("label_69");
        label_69->setGeometry(QRect(70, 80, 107, 20));
        label_69->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14px;"));
        label_70 = new QLabel(frame_26);
        label_70->setObjectName("label_70");
        label_70->setGeometry(QRect(70, 40, 263, 31));
        label_70->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"border: none;"));
        frame_27 = new QFrame(frame_26);
        frame_27->setObjectName("frame_27");
        frame_27->setGeometry(QRect(10, 40, 45, 45));
        frame_27->setMinimumSize(QSize(0, 0));
        frame_27->setMaximumSize(QSize(16777215, 16777215));
        frame_27->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        frame_27->setStyleSheet(QString::fromUtf8("background-color: black;\n"
""));
        frame_27->setFrameShape(QFrame::Shape::StyledPanel);
        frame_27->setFrameShadow(QFrame::Shadow::Raised);
        label_71 = new QLabel(frame_27);
        label_71->setObjectName("label_71");
        label_71->setGeometry(QRect(10, 10, 25, 25));
        label_71->setMinimumSize(QSize(0, 0));
        label_71->setMaximumSize(QSize(16777215, 16777215));
        label_71->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        label_71->setPixmap(QPixmap(QString::fromUtf8(":/img/work-time.png")));
        label_71->setScaledContents(true);
        btn_staff_download = new QPushButton(frame_26);
        btn_staff_download->setObjectName("btn_staff_download");
        btn_staff_download->setGeometry(QRect(310, 50, 29, 25));
        btn_staff_download->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: transparent;\n"
"    border: 2px solid transparent;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #00f2ff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #1f618d;\n"
"    background-color: rgba(180, 180, 180, 80);\n"
"}\n"
""));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/download1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_staff_download->setIcon(icon11);
        btn_staff_download->setIconSize(QSize(25, 25));
        frame_28 = new QFrame(scrollAreaWidgetContents_4);
        frame_28->setObjectName("frame_28");
        frame_28->setGeometry(QRect(0, 30, 360, 150));
        sizePolicy.setHeightForWidth(frame_28->sizePolicy().hasHeightForWidth());
        frame_28->setSizePolicy(sizePolicy);
        frame_28->setMinimumSize(QSize(360, 150));
        frame_28->setMaximumSize(QSize(3600, 150));
        frame_28->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1a1f26; \n"
"    border-radius: 15px;       \n"
"    border: 1px solid #2d343d; \n"
"}\n"
"\n"
"QFrame:hover {\n"
"    background-color: #242b35;\n"
"    border: 1px solid #00f2ff;\n"
"}\n"
"\n"
"\n"
""));
        frame_28->setFrameShape(QFrame::Shape::StyledPanel);
        frame_28->setFrameShadow(QFrame::Shadow::Raised);
        label_72 = new QLabel(frame_28);
        label_72->setObjectName("label_72");
        label_72->setGeometry(QRect(70, 110, 137, 20));
        label_72->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14\n"
"px;"));
        label_73 = new QLabel(frame_28);
        label_73->setObjectName("label_73");
        label_73->setGeometry(QRect(70, 80, 107, 20));
        label_73->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14px;"));
        label_74 = new QLabel(frame_28);
        label_74->setObjectName("label_74");
        label_74->setGeometry(QRect(70, 40, 261, 31));
        label_74->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"border: none;"));
        frame_29 = new QFrame(frame_28);
        frame_29->setObjectName("frame_29");
        frame_29->setGeometry(QRect(10, 40, 45, 45));
        frame_29->setMinimumSize(QSize(0, 0));
        frame_29->setMaximumSize(QSize(16777215, 16777215));
        frame_29->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        frame_29->setStyleSheet(QString::fromUtf8("background-color: black;\n"
""));
        frame_29->setFrameShape(QFrame::Shape::StyledPanel);
        frame_29->setFrameShadow(QFrame::Shadow::Raised);
        label_75 = new QLabel(frame_29);
        label_75->setObjectName("label_75");
        label_75->setGeometry(QRect(10, 10, 25, 25));
        label_75->setMinimumSize(QSize(0, 0));
        label_75->setMaximumSize(QSize(16777215, 16777215));
        label_75->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        label_75->setPixmap(QPixmap(QString::fromUtf8(":/img/patient.png")));
        label_75->setScaledContents(true);
        downloadMonthlyReport = new QPushButton(frame_28);
        downloadMonthlyReport->setObjectName("downloadMonthlyReport");
        downloadMonthlyReport->setGeometry(QRect(300, 50, 29, 25));
        downloadMonthlyReport->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: transparent;\n"
"    border: 2px solid transparent;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #00f2ff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #1f618d;\n"
"    background-color: rgba(180, 180, 180, 80);\n"
"}"));
        downloadMonthlyReport->setIcon(icon11);
        downloadMonthlyReport->setIconSize(QSize(25, 25));
        frame_30 = new QFrame(scrollAreaWidgetContents_4);
        frame_30->setObjectName("frame_30");
        frame_30->setGeometry(QRect(0, 230, 360, 150));
        sizePolicy.setHeightForWidth(frame_30->sizePolicy().hasHeightForWidth());
        frame_30->setSizePolicy(sizePolicy);
        frame_30->setMinimumSize(QSize(360, 150));
        frame_30->setMaximumSize(QSize(3600, 150));
        frame_30->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1a1f26; \n"
"    border-radius: 15px;       \n"
"    border: 1px solid #2d343d; \n"
"}\n"
"\n"
"QFrame:hover {\n"
"    background-color: #242b35;\n"
"    border: 1px solid #00f2ff; \n"
"}\n"
"\n"
""));
        frame_30->setFrameShape(QFrame::Shape::StyledPanel);
        frame_30->setFrameShadow(QFrame::Shadow::Raised);
        label_76 = new QLabel(frame_30);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(70, 110, 137, 20));
        label_76->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14\n"
"px;"));
        label_77 = new QLabel(frame_30);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(70, 80, 107, 20));
        label_77->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14px;"));
        label_78 = new QLabel(frame_30);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(70, 40, 261, 31));
        label_78->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"border: none;"));
        btn_financial = new QPushButton(frame_30);
        btn_financial->setObjectName("btn_financial");
        btn_financial->setGeometry(QRect(300, 50, 29, 25));
        btn_financial->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: transparent;\n"
"    border: 2px solid transparent;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #00f2ff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #1f618d;\n"
"    background-color: rgba(180, 180, 180, 80);\n"
"}"));
        btn_financial->setIcon(icon11);
        btn_financial->setIconSize(QSize(25, 25));
        frame_31 = new QFrame(frame_30);
        frame_31->setObjectName("frame_31");
        frame_31->setGeometry(QRect(10, 40, 45, 45));
        frame_31->setMinimumSize(QSize(0, 0));
        frame_31->setMaximumSize(QSize(16777215, 16777215));
        frame_31->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        frame_31->setStyleSheet(QString::fromUtf8("background-color: black;\n"
""));
        frame_31->setFrameShape(QFrame::Shape::StyledPanel);
        frame_31->setFrameShadow(QFrame::Shadow::Raised);
        label_79 = new QLabel(frame_31);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(10, 10, 25, 25));
        label_79->setMinimumSize(QSize(0, 0));
        label_79->setMaximumSize(QSize(16777215, 16777215));
        label_79->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        label_79->setPixmap(QPixmap(QString::fromUtf8(":/img/coin.png")));
        label_79->setScaledContents(true);
        frame_32 = new QFrame(scrollAreaWidgetContents_4);
        frame_32->setObjectName("frame_32");
        frame_32->setGeometry(QRect(370, 30, 360, 150));
        sizePolicy.setHeightForWidth(frame_32->sizePolicy().hasHeightForWidth());
        frame_32->setSizePolicy(sizePolicy);
        frame_32->setMinimumSize(QSize(360, 150));
        frame_32->setMaximumSize(QSize(3600, 150));
        frame_32->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1a1f26; \n"
"    border-radius: 15px;       \n"
"    border: 1px solid #2d343d; \n"
"}\n"
"\n"
"QFrame:hover {\n"
"    background-color: #242b35;\n"
"    border: 1px solid #00f2ff; \n"
"}\n"
"\n"
"\n"
"\n"
""));
        frame_32->setFrameShape(QFrame::Shape::StyledPanel);
        frame_32->setFrameShadow(QFrame::Shadow::Raised);
        label_80 = new QLabel(frame_32);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(70, 110, 141, 20));
        label_80->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14\n"
"px;"));
        label_81 = new QLabel(frame_32);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(70, 80, 132, 19));
        label_81->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: #808080;               \n"
"    font-size: 14px;"));
        label_82 = new QLabel(frame_32);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(70, 40, 276, 31));
        label_82->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"border: none;"));
        downloadDepartmentPerformance = new QPushButton(frame_32);
        downloadDepartmentPerformance->setObjectName("downloadDepartmentPerformance");
        downloadDepartmentPerformance->setGeometry(QRect(310, 50, 29, 25));
        downloadDepartmentPerformance->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: transparent;\n"
"    border: 2px solid transparent;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #00f2ff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #1f618d;\n"
"    background-color: rgba(180, 180, 180, 80);\n"
"}"));
        downloadDepartmentPerformance->setIcon(icon11);
        downloadDepartmentPerformance->setIconSize(QSize(25, 25));
        frame_33 = new QFrame(frame_32);
        frame_33->setObjectName("frame_33");
        frame_33->setGeometry(QRect(10, 40, 45, 45));
        frame_33->setMinimumSize(QSize(0, 0));
        frame_33->setMaximumSize(QSize(16777215, 16777215));
        frame_33->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        frame_33->setStyleSheet(QString::fromUtf8("background-color: black;\n"
""));
        frame_33->setFrameShape(QFrame::Shape::StyledPanel);
        frame_33->setFrameShadow(QFrame::Shadow::Raised);
        label_83 = new QLabel(frame_33);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(10, 10, 25, 25));
        label_83->setMinimumSize(QSize(0, 0));
        label_83->setMaximumSize(QSize(16777215, 16777215));
        label_83->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        label_83->setPixmap(QPixmap(QString::fromUtf8(":/img/pie-chart.png")));
        label_83->setScaledContents(true);
        pushButton_35 = new QPushButton(frame_32);
        pushButton_35->setObjectName("pushButton_35");
        pushButton_35->setGeometry(QRect(300, 260, 29, 25));
        pushButton_35->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        pushButton_35->setIcon(icon11);
        pushButton_35->setIconSize(QSize(25, 25));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);
        contentStackWidget->addWidget(reportPage);
        appointmentsPage = new QWidget();
        appointmentsPage->setObjectName("appointmentsPage");
        verticalLayout_12 = new QVBoxLayout(appointmentsPage);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        pageTitle = new QLabel(appointmentsPage);
        pageTitle->setObjectName("pageTitle");

        verticalLayout_9->addWidget(pageTitle);

        calendarWidget = new QCalendarWidget(appointmentsPage);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::FalklandIslands));

        verticalLayout_9->addWidget(calendarWidget);


        verticalLayout_12->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_6 = new QLabel(appointmentsPage);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font-size: 14pt; font-weight: bold;\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(label_6);

        appointmentsTableView = new QTableView(appointmentsPage);
        appointmentsTableView->setObjectName("appointmentsTableView");

        verticalLayout_8->addWidget(appointmentsTableView);


        verticalLayout_12->addLayout(verticalLayout_8);

        horizontalSpacer_3 = new QSpacerItem(712, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_12->addItem(horizontalSpacer_3);

        splitter = new QSplitter(appointmentsPage);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        addAppointmentButton = new QPushButton(splitter);
        addAppointmentButton->setObjectName("addAppointmentButton");
        addAppointmentButton->setMinimumSize(QSize(200, 0));
        splitter->addWidget(addAppointmentButton);
        update_appointment = new QPushButton(splitter);
        update_appointment->setObjectName("update_appointment");
        update_appointment->setMinimumSize(QSize(350, 0));
        update_appointment->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        splitter->addWidget(update_appointment);

        verticalLayout_12->addWidget(splitter);

        contentStackWidget->addWidget(appointmentsPage);

        verticalLayout_4->addWidget(contentStackWidget);


        verticalLayout->addWidget(content);


        horizontalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        contentStackWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hospital Management System", nullptr));
        toggleButton->setText(QCoreApplication::translate("MainWindow", "Hospital", nullptr));
        homeButton->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        patientsButton->setText(QCoreApplication::translate("MainWindow", "Patients", nullptr));
        doctorButton->setText(QCoreApplication::translate("MainWindow", "Doctors", nullptr));
        departmentButton->setText(QCoreApplication::translate("MainWindow", "Departments", nullptr));
        appointmentsButton->setText(QCoreApplication::translate("MainWindow", "Appointments", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Reborts", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "LogOut", nullptr));
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        close->setText(QString());
        mainChartTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p> New Patients</p></body></html>", nullptr));
        barChartTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#00f6ff;\">\342\255\220 </span> Consultations</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#00f6ff;\">\342\254\241 </span><span style=\" font-size:14pt; font-weight:700;\"> Departments</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#00f6ff;\">\342\232\231 </span><span style=\" font-size:14pt; font-weight:700;\"> Doctors</span></p></body></html>", nullptr));
        departmentTitle->setText(QCoreApplication::translate("MainWindow", "Department", nullptr));
        addDepartment->setText(QCoreApplication::translate("MainWindow", "Add New Department", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        departmentSearchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Department by Name or ID...", nullptr));
        docterTitle->setText(QCoreApplication::translate("MainWindow", "Doctors", nullptr));
        addDoctorButton->setText(QCoreApplication::translate("MainWindow", "Add New Doctor", nullptr));
        editDoctorButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        deleteDoctorButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        doctorSearchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Doctor by Name or ID...", nullptr));
        pageTitle_2->setText(QCoreApplication::translate("MainWindow", "Patients Management", nullptr));
        addPatientButton->setText(QCoreApplication::translate("MainWindow", "Add New Patient", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        PatientsSearchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Patients by Name or ID...", nullptr));
        label_84->setText(QCoreApplication::translate("MainWindow", "Reports", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "2026-03-25    1.5 MB", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "HR Report", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "Staff Attendance Report", nullptr));
        label_71->setText(QString());
        btn_staff_download->setText(QString());
        label_72->setText(QCoreApplication::translate("MainWindow", "2026-03-01    2.4 MB", nullptr));
        label_73->setText(QCoreApplication::translate("MainWindow", "Patient Statistics", nullptr));
        label_74->setText(QCoreApplication::translate("MainWindow", "Monthly Patient Report", nullptr));
        label_75->setText(QString());
        downloadMonthlyReport->setText(QString());
        label_76->setText(QCoreApplication::translate("MainWindow", "2026-03-28    3.2 MB", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "Financial Report", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "Financial Summary Q1", nullptr));
        btn_financial->setText(QString());
        label_79->setText(QString());
        label_80->setText(QCoreApplication::translate("MainWindow", "2026-03-15     1.8 MB", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "Department Analytics", nullptr));
        label_82->setText(QCoreApplication::translate("MainWindow", "Department Performance", nullptr));
        downloadDepartmentPerformance->setText(QString());
        label_83->setText(QString());
        pushButton_35->setText(QString());
        pageTitle->setText(QCoreApplication::translate("MainWindow", "Appointments Schedule", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Appointments", nullptr));
        addAppointmentButton->setText(QCoreApplication::translate("MainWindow", "New Appointment", nullptr));
        update_appointment->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
