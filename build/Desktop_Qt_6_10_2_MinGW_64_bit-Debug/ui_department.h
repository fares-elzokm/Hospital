/********************************************************************************
** Form generated from reading UI file 'department.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENT_H
#define UI_DEPARTMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Department
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *topbar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pageTitle;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QFrame *formFrame;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *nameComboBox;
    QLabel *label_2;
    QComboBox *statusComboBox;
    QFrame *bottomBarFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;

    void setupUi(QDialog *Department)
    {
        if (Department->objectName().isEmpty())
            Department->setObjectName("Department");
        Department->resize(400, 300);
        Department->setStyleSheet(QString::fromUtf8("QMainWindow, QWidget#centralwidget, QDialog#Department {\n"
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
"    padd"
                        "ing: 5px;\n"
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
"    gri"
                        "dline-color: #21262D;\n"
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
""
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
        verticalLayout = new QVBoxLayout(Department);
        verticalLayout->setObjectName("verticalLayout");
        topbar = new QFrame(Department);
        topbar->setObjectName("topbar");
        topbar->setMaximumSize(QSize(16777215, 45));
        topbar->setFrameShape(QFrame::Shape::StyledPanel);
        topbar->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(topbar);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pageTitle = new QLabel(topbar);
        pageTitle->setObjectName("pageTitle");

        horizontalLayout_2->addWidget(pageTitle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(topbar);
        pushButton_2->setObjectName("pushButton_2");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addWidget(topbar);

        formFrame = new QFrame(Department);
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

        nameComboBox = new QComboBox(formFrame);
        nameComboBox->addItem(QString());
        nameComboBox->addItem(QString());
        nameComboBox->addItem(QString());
        nameComboBox->addItem(QString());
        nameComboBox->setObjectName("nameComboBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameComboBox);

        label_2 = new QLabel(formFrame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        statusComboBox = new QComboBox(formFrame);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName("statusComboBox");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, statusComboBox);


        verticalLayout->addWidget(formFrame);

        bottomBarFrame = new QFrame(Department);
        bottomBarFrame->setObjectName("bottomBarFrame");
        bottomBarFrame->setFrameShape(QFrame::Shape::StyledPanel);
        bottomBarFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(bottomBarFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(bottomBarFrame);
        saveButton->setObjectName("saveButton");

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addWidget(bottomBarFrame);


        retranslateUi(Department);

        QMetaObject::connectSlotsByName(Department);
    } // setupUi

    void retranslateUi(QDialog *Department)
    {
        Department->setWindowTitle(QCoreApplication::translate("Department", "Dialog", nullptr));
        pageTitle->setText(QCoreApplication::translate("Department", "Patient Information", nullptr));
        pushButton_2->setText(QString());
        label->setText(QCoreApplication::translate("Department", "Name:", nullptr));
        nameComboBox->setItemText(0, QCoreApplication::translate("Department", "Emergency Department", nullptr));
        nameComboBox->setItemText(1, QCoreApplication::translate("Department", "Maternity Department", nullptr));
        nameComboBox->setItemText(2, QCoreApplication::translate("Department", "Pediatrics Department", nullptr));
        nameComboBox->setItemText(3, QCoreApplication::translate("Department", "Surgery Department", nullptr));

        label_2->setText(QCoreApplication::translate("Department", "Status:", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("Department", "Maternity", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("Department", "Pediatrics", nullptr));
        statusComboBox->setItemText(2, QCoreApplication::translate("Department", "Women", nullptr));
        statusComboBox->setItemText(3, QCoreApplication::translate("Department", "Surgery", nullptr));
        statusComboBox->setItemText(4, QCoreApplication::translate("Department", "Internal Medicine", nullptr));

        saveButton->setText(QCoreApplication::translate("Department", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Department: public Ui_Department {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENT_H
