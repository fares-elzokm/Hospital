/********************************************************************************
** Form generated from reading UI file 'appointmentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTDIALOG_H
#define UI_APPOINTMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AppointmentDialog
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelButton;
    QLabel *data;
    QLabel *doctor;
    QLabel *department;
    QDateEdit *dateEdit;
    QComboBox *comboBoxDept;
    QComboBox *comboBoxDoctor;
    QLabel *Patient;
    QComboBox *comboBoxPatient;
    QLabel *label;
    QComboBox *comboBoxStatus;

    void setupUi(QDialog *AppointmentDialog)
    {
        if (AppointmentDialog->objectName().isEmpty())
            AppointmentDialog->setObjectName("AppointmentDialog");
        AppointmentDialog->resize(439, 491);
        AppointmentDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame = new QFrame(AppointmentDialog);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 441, 491));
        frame->setStyleSheet(QString::fromUtf8("background-color: #161B22;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 420, 401, 49));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #161B22;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(292, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        saveButton = new QPushButton(frame_2);
        saveButton->setObjectName("saveButton");
        saveButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"background-color: #00F6FF;"));

        horizontalLayout_2->addWidget(saveButton);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(0, 0, 441, 51));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: #0D1117;"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName("horizontalLayout");
        label_10 = new QLabel(frame_3);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_10);

        horizontalSpacer_2 = new QSpacerItem(207, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(frame_3);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setStyleSheet(QString::fromUtf8(":hover {\n"
"    background-color: #FF4444;    /* \330\256\331\204\331\201\331\212\330\251 \330\255\331\205\330\261\330\247\330\241 \330\265\330\261\331\212\330\255\330\251 */\n"
"\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        cancelButton->setIcon(icon);

        horizontalLayout->addWidget(cancelButton);

        data = new QLabel(frame);
        data->setObjectName("data");
        data->setGeometry(QRect(70, 360, 49, 16));
        data->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        doctor = new QLabel(frame);
        doctor->setObjectName("doctor");
        doctor->setGeometry(QRect(40, 160, 71, 20));
        doctor->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        department = new QLabel(frame);
        department->setObjectName("department");
        department->setGeometry(QRect(20, 230, 91, 20));
        department->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(120, 350, 241, 41));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: #161B22;\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"Segoe UI\";"));
        comboBoxDept = new QComboBox(frame);
        comboBoxDept->setObjectName("comboBoxDept");
        comboBoxDept->setGeometry(QRect(120, 220, 241, 41));
        comboBoxDept->setStyleSheet(QString::fromUtf8("background-color: #161B22;\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"Segoe UI\";"));
        comboBoxDoctor = new QComboBox(frame);
        comboBoxDoctor->setObjectName("comboBoxDoctor");
        comboBoxDoctor->setGeometry(QRect(120, 150, 241, 41));
        comboBoxDoctor->setStyleSheet(QString::fromUtf8("background-color: #161B22;\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"Segoe UI\";"));
        Patient = new QLabel(frame);
        Patient->setObjectName("Patient");
        Patient->setGeometry(QRect(50, 90, 61, 21));
        Patient->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        comboBoxPatient = new QComboBox(frame);
        comboBoxPatient->setObjectName("comboBoxPatient");
        comboBoxPatient->setGeometry(QRect(120, 80, 241, 41));
        comboBoxPatient->setStyleSheet(QString::fromUtf8("background-color: #161B22;\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"Segoe UI\";"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 290, 61, 27));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        comboBoxStatus = new QComboBox(frame);
        comboBoxStatus->setObjectName("comboBoxStatus");
        comboBoxStatus->setGeometry(QRect(120, 290, 241, 41));
        comboBoxStatus->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        retranslateUi(AppointmentDialog);

        QMetaObject::connectSlotsByName(AppointmentDialog);
    } // setupUi

    void retranslateUi(QDialog *AppointmentDialog)
    {
        AppointmentDialog->setWindowTitle(QCoreApplication::translate("AppointmentDialog", "Dialog", nullptr));
        saveButton->setText(QCoreApplication::translate("AppointmentDialog", "Save", nullptr));
        label_10->setText(QCoreApplication::translate("AppointmentDialog", "AppointmentDialog", nullptr));
        cancelButton->setText(QString());
        data->setText(QCoreApplication::translate("AppointmentDialog", "Date:", nullptr));
        doctor->setText(QCoreApplication::translate("AppointmentDialog", "    Doctor:", nullptr));
        department->setText(QCoreApplication::translate("AppointmentDialog", "Department:", nullptr));
        Patient->setText(QCoreApplication::translate("AppointmentDialog", " Patient:", nullptr));
        label->setText(QCoreApplication::translate("AppointmentDialog", "Status:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppointmentDialog: public Ui_AppointmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTDIALOG_H
