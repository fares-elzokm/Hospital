/********************************************************************************
** Form generated from reading UI file 'doctor.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTOR_H
#define UI_DOCTOR_H

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

class Ui_Doctor
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
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBoxDepartment;
    QComboBox *comboBoxGender;
    QLineEdit *lineEditAge;
    QLineEdit *lineEditName;
    QFrame *bottomBarFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;

    void setupUi(QDialog *Doctor)
    {
        if (Doctor->objectName().isEmpty())
            Doctor->setObjectName("Doctor");
        Doctor->resize(400, 324);
        Doctor->setStyleSheet(QString::fromUtf8("QMainWindow, QWidget#centralwidget, QDialog#Doctor {\n"
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
"    background-color: transparent;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding:"
                        " 5px;\n"
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
"    border: 1px solid #21262D;\n"
"    border-radius: 8px;\n"
"    gridlin"
                        "e-color: #21262D;\n"
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
"QComboBox QAbstractItemView {\n"
"    background-color: #161B22;\n"
"   "
                        " border: 1px solid #21262D;\n"
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
        verticalLayout = new QVBoxLayout(Doctor);
        verticalLayout->setObjectName("verticalLayout");
        topbar = new QFrame(Doctor);
        topbar->setObjectName("topbar");
        topbar->setMaximumSize(QSize(16777213, 45));
        topbar->setFrameShape(QFrame::Shape::StyledPanel);
        topbar->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(topbar);
        horizontalLayout->setObjectName("horizontalLayout");
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

        formFrame = new QFrame(Doctor);
        formFrame->setObjectName("formFrame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(formFrame->sizePolicy().hasHeightForWidth());
        formFrame->setSizePolicy(sizePolicy);
        formFrame->setFrameShape(QFrame::Shape::StyledPanel);
        formFrame->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(formFrame);
        formLayout->setObjectName("formLayout");
        label = new QLabel(formFrame);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        label_2 = new QLabel(formFrame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_2);

        label_3 = new QLabel(formFrame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_3);

        label_4 = new QLabel(formFrame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(6, QFormLayout::ItemRole::SpanningRole, label_4);

        comboBoxDepartment = new QComboBox(formFrame);
        comboBoxDepartment->setObjectName("comboBoxDepartment");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, comboBoxDepartment);

        comboBoxGender = new QComboBox(formFrame);
        comboBoxGender->addItem(QString());
        comboBoxGender->addItem(QString());
        comboBoxGender->setObjectName("comboBoxGender");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, comboBoxGender);

        lineEditAge = new QLineEdit(formFrame);
        lineEditAge->setObjectName("lineEditAge");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEditAge);

        lineEditName = new QLineEdit(formFrame);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditName);


        verticalLayout->addWidget(formFrame);

        bottomBarFrame = new QFrame(Doctor);
        bottomBarFrame->setObjectName("bottomBarFrame");
        bottomBarFrame->setFrameShape(QFrame::Shape::StyledPanel);
        bottomBarFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(bottomBarFrame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(bottomBarFrame);
        saveButton->setObjectName("saveButton");

        horizontalLayout_2->addWidget(saveButton);


        verticalLayout->addWidget(bottomBarFrame, 0, Qt::AlignmentFlag::AlignBottom);


        retranslateUi(Doctor);

        QMetaObject::connectSlotsByName(Doctor);
    } // setupUi

    void retranslateUi(QDialog *Doctor)
    {
        Doctor->setWindowTitle(QCoreApplication::translate("Doctor", "Dialog", nullptr));
        pageTitle->setText(QCoreApplication::translate("Doctor", "TextLabel", nullptr));
        closeButton->setText(QString());
        label->setText(QCoreApplication::translate("Doctor", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("Doctor", "Age:", nullptr));
        label_3->setText(QCoreApplication::translate("Doctor", "Gender:", nullptr));
        label_4->setText(QCoreApplication::translate("Doctor", "Department:", nullptr));
        comboBoxGender->setItemText(0, QCoreApplication::translate("Doctor", "Male", nullptr));
        comboBoxGender->setItemText(1, QCoreApplication::translate("Doctor", "Female", nullptr));

        saveButton->setText(QCoreApplication::translate("Doctor", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Doctor: public Ui_Doctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOR_H
