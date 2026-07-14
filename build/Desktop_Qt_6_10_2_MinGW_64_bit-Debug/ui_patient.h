/********************************************************************************
** Form generated from reading UI file 'patient.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_H
#define UI_PATIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Patient
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *topbar;
    QHBoxLayout *horizontalLayout;
    QLabel *pageTitle;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QFrame *formFrame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *ageLineEdit;
    QLabel *label_3;
    QComboBox *genderComboBox;
    QLabel *label_4;
    QLineEdit *phoneLineEdit;
    QLabel *label_5;
    QLineEdit *medicalHistoryLineEdit;
    QFrame *bottomBarFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;

    void setupUi(QDialog *Patient)
    {
        if (Patient->objectName().isEmpty())
            Patient->setObjectName("Patient");
        Patient->resize(450, 405);
        Patient->setStyleSheet(QString::fromUtf8("/* --- Thor Theme QSS --- */\n"
"\n"
"/* Main Window & Central Widget */\n"
"QMainWindow, QWidget#centralwidget, QDialog#Patient {\n"
"    background-color: #0D1117;\n"
"}\n"
"\n"
"/* --- Frame --- */\n"
"QWidget#frame\n"
"{\n"
"    background-color: transparent;\n"
"}\n"
"/* --- Sidebar --- */\n"
"QWidget#sidebar {\n"
"    background-color: #161B22;\n"
"    border-radius: 10px;\n"
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
"    border-radius: 8px;\n"
"}\n"
"QFrame#topbar QPushButton {\n"
"    background-color: t"
                        "ransparent;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"    text-align: center;\n"
"}\n"
"QFrame#topbar QPushButton:hover {\n"
"    background-color: #21262D;\n"
"}\n"
"QFrame#topbar QPushButton#closeButton:hover {\n"
"    background-color: #E81123;\n"
"}\n"
"\n"
"/*--- bottomBarFrame --*/\n"
"QFrame#bottomBarFrame {\n"
"    background-color: #161B22;\n"
"    border-radius: 8px;\n"
"}\n"
"/* --- Main Content Area --- */\n"
"QFrame#content, QStackedWidget > QWidget {\n"
"    background-color: #0D1117;\n"
"    border: none;\n"
"}\n"
"\n"
"/* General Page Titles */\n"
"QLabel#pageTitle {\n"
"    color: #E6EDF3;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* --- Form Specific --- */\n"
"QFrame#formFrame {\n"
"    background-color: #161B22;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"#formFrame QLabel {\n"
" color: #E6EDF3;\n"
" font-size: 11pt;\n"
" padding-bottom: 5px;\n"
"}\n"
"\n"
"/* --- Table View --- */\n"
"QTableView {\n"
"    background-color: #161B22;\n"
""
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
"/* --- Line Edit & ComboBox --- */\n"
"QLineEdit, QComboBox {\n"
"    background-color: #0D1117;\n"
"    border: 1px solid #21262D;\n"
"    border-radius: 5px;\n"
"    padding: 8px 10px;\n"
"    color: #E6EDF3;\n"
"    font-size: 10pt;\n"
"}\n"
"QLineEdit:focus, QComboBox:focus {\n"
"    border-color: #00F6FF;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:/img/chevron-down.svg); /* Ensure you have this icon */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
""
                        "QComboBox QAbstractItemView {\n"
"    background-color: #161B22;\n"
"    border: 1px solid #21262D;\n"
"    color: #E6EDF3;\n"
"    selection-background-color: #00F6FF;\n"
"    selection-color: #0D1117;\n"
"}\n"
"\n"
"/* --- Main Action Button --- */\n"
"QPushButton#saveButton {\n"
"    background-color: #00F6FF;\n"
"    color: #0D1117;\n"
"    border-radius: 5px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"}\n"
"QPushButton#saveButton:hover {\n"
"    background-color: #33fdff;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(Patient);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        topbar = new QFrame(Patient);
        topbar->setObjectName("topbar");
        topbar->setMaximumSize(QSize(16777215, 45));
        topbar->setFrameShape(QFrame::Shape::StyledPanel);
        topbar->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(topbar);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        pageTitle = new QLabel(topbar);
        pageTitle->setObjectName("pageTitle");

        horizontalLayout->addWidget(pageTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(topbar);
        closeButton->setObjectName("closeButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        closeButton->setIcon(icon);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addWidget(topbar);

        formFrame = new QFrame(Patient);
        formFrame->setObjectName("formFrame");
        formFrame->setFrameShape(QFrame::Shape::StyledPanel);
        formFrame->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(formFrame);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(15, 15, 15, 15);
        label = new QLabel(formFrame);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        nameLineEdit = new QLineEdit(formFrame);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameLineEdit);

        label_2 = new QLabel(formFrame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        ageLineEdit = new QLineEdit(formFrame);
        ageLineEdit->setObjectName("ageLineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, ageLineEdit);

        label_3 = new QLabel(formFrame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        genderComboBox = new QComboBox(formFrame);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderComboBox);

        label_4 = new QLabel(formFrame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        phoneLineEdit = new QLineEdit(formFrame);
        phoneLineEdit->setObjectName("phoneLineEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, phoneLineEdit);

        label_5 = new QLabel(formFrame);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        medicalHistoryLineEdit = new QLineEdit(formFrame);
        medicalHistoryLineEdit->setObjectName("medicalHistoryLineEdit");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, medicalHistoryLineEdit);


        verticalLayout->addWidget(formFrame);

        bottomBarFrame = new QFrame(Patient);
        bottomBarFrame->setObjectName("bottomBarFrame");
        bottomBarFrame->setMaximumSize(QSize(16777215, 50));
        bottomBarFrame->setFrameShape(QFrame::Shape::StyledPanel);
        bottomBarFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(bottomBarFrame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(bottomBarFrame);
        saveButton->setObjectName("saveButton");

        horizontalLayout_2->addWidget(saveButton);


        verticalLayout->addWidget(bottomBarFrame);


        retranslateUi(Patient);
        QObject::connect(closeButton, &QPushButton::clicked, Patient, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Patient);
    } // setupUi

    void retranslateUi(QDialog *Patient)
    {
        Patient->setWindowTitle(QCoreApplication::translate("Patient", "Patient Information", nullptr));
        pageTitle->setText(QCoreApplication::translate("Patient", "Patient Information", nullptr));
        closeButton->setText(QString());
        label->setText(QCoreApplication::translate("Patient", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("Patient", "Age:", nullptr));
        label_3->setText(QCoreApplication::translate("Patient", "Gender:", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("Patient", "Male", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("Patient", "Female", nullptr));

        label_4->setText(QCoreApplication::translate("Patient", "Phone:", nullptr));
        label_5->setText(QCoreApplication::translate("Patient", "Medical History:", nullptr));
        saveButton->setText(QCoreApplication::translate("Patient", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Patient: public Ui_Patient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_H
