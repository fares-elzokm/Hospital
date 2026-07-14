/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *frame;
    QFrame *frame_3;
    QLabel *label_2;
    QFrame *frame_2;
    QLabel *label_3;
    QLineEdit *txt_email;
    QPushButton *btn_login;
    QLineEdit *txt_password;
    QLabel *label;
    QFrame *frame_4;
    QPushButton *btn_close;
    QPushButton *btn_min;
    QWidget *layoutWidget;
    QHBoxLayout *_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(800, 501);
        frame = new QFrame(Login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, 0, 450, 800));
        frame->setStyleSheet(QString::fromUtf8("border-top-left-radius: 40px; \n"
"    \n"
"    /* \330\252\330\255\330\257\331\212\330\257 \330\247\331\204\330\261\331\203\331\206 \330\247\331\204\330\263\331\201\331\204\331\212 \331\212\331\205\331\212\331\206 */\n"
"    border-bottom-left-radius: 40px;\n"
"    /* \330\250\330\247\331\202\331\212 \330\247\331\204\330\243\330\261\331\203\330\247\331\206 (\330\247\331\204\330\264\331\205\330\247\331\204) \331\207\330\252\331\201\330\266\331\204 0 \330\271\330\264\330\247\331\206 \330\252\330\250\331\202\331\211 \330\255\330\247\330\257\330\251 */\n"
"    border-top-right-radius: 0px;\n"
"    border-bottom-right-radius: 0px;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(9, -1, 441, 501));
        frame_3->setMaximumSize(QSize(999999, 999999));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: #161B22;"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-10, 60, 471, 371));
        label_2->setStyleSheet(QString::fromUtf8("    border-top-left-radius: 40px;\n"
"    border-bottom-left-radius: 40px;"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/LogoFinal.png")));
        label_2->setScaledContents(true);
        frame_2 = new QFrame(Login);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(439, -1, 361, 501));
        frame_2->setMaximumSize(QSize(999999, 999999));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #0D1117;\n"
"border-top-right-radius: 40px;\n"
"    border-bottom-right-radius: 40px;\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 90, 221, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: #E6EDF3;\n"
"    font-family: \"Inter\", \"Segoe UI\", sans-serif;\n"
"    font-size: 14px; /* \330\247\331\204\330\255\330\254\331\205 \330\247\331\204\330\252\331\202\330\261\331\212\330\250\331\212 \331\201\331\212 \330\247\331\204\330\265\331\210\330\261\330\251 */\n"
"    font-weight: 400;\n"
""));
        txt_email = new QLineEdit(frame_2);
        txt_email->setObjectName("txt_email");
        txt_email->setGeometry(QRect(20, 170, 301, 41));
        txt_email->setStyleSheet(QString::fromUtf8("background-color: #161B22;\n"
"border: 1px solid #21262D;\n"
"    border-radius: 12px;\n"
"    padding: 12px;\n"
"    color: #E6EDF3;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"border: 2px solid #21262D;"));
        btn_login = new QPushButton(frame_2);
        btn_login->setObjectName("btn_login");
        btn_login->setGeometry(QRect(20, 330, 301, 41));
        btn_login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"    background-color: #047481;\n"
"    border: 1px solid #21262D;\n"
"    border-radius: 15px;\n"
"    font-weight: bold;\n"
"    font-size: 18px;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"    background-color: #1E6CC5;\n"
"}"));
        txt_password = new QLineEdit(frame_2);
        txt_password->setObjectName("txt_password");
        txt_password->setGeometry(QRect(20, 250, 301, 41));
        txt_password->setStyleSheet(QString::fromUtf8("background-color: #161B22;\n"
"border: 1px solid #21262D;\n"
"    border-radius: 12px;\n"
"    padding: 12px;\n"
"    color: #E6EDF3;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"border: 2px solid #21262D;"));
        txt_password->setEchoMode(QLineEdit::EchoMode::Password);
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 60, 251, 31));
        label->setStyleSheet(QString::fromUtf8("font-family: \"Segoe UI\", sans-serif;\n"
"color: rgb(255, 249, 248);\n"
"font-size: 30px"));
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 0, 361, 41));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame#frame_4 {\n"
"background-color: #161B22;\n"
"\n"
"   border-top-right-radius: 40px; /* \330\247\331\204\330\262\330\247\331\210\331\212\330\251 \330\247\331\204\331\204\331\212 \330\243\331\206\330\252 \330\271\330\247\331\212\330\262\331\207\330\247 */\n"
"    border-top-left-radius: 0px;   /* \330\250\330\247\331\202\331\212 \330\247\331\204\330\262\331\210\330\247\331\212\330\247 \330\256\331\204\331\204\331\212\331\207\330\247 0 \331\204\331\210 \331\205\330\264 \330\271\330\247\331\212\330\262\331\207\330\247 \331\205\330\257\331\210\330\261\330\251 */\n"
"   border-bottom-right-radius: 0px;\n"
"    border-bottom-left-radius: 0px;\n"
"}"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        btn_close = new QPushButton(frame_4);
        btn_close->setObjectName("btn_close");
        btn_close->setGeometry(QRect(310, 10, 31, 21));
        btn_close->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"image: url(:/img/x.svg);\n"
"    }\n"
"    QPushButton:hover {\n"
"    background-color: #ff0000; \n"
"    }"));
        btn_close->setIconSize(QSize(20, 20));
        btn_min = new QPushButton(frame_4);
        btn_min->setObjectName("btn_min");
        btn_min->setGeometry(QRect(280, 0, 21, 41));
        btn_min->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"image: url(:/img/minus.svg);\n"
"\n"
"    }\n"
"    QPushButton:hover {\n"
"background-color: #161B22;\n"
"    }"));
        btn_min->setInputMethodHints(Qt::InputMethodHint::ImhDialableCharactersOnly|Qt::InputMethodHint::ImhDigitsOnly|Qt::InputMethodHint::ImhEmailCharactersOnly|Qt::InputMethodHint::ImhFormattedNumbersOnly|Qt::InputMethodHint::ImhLatinOnly|Qt::InputMethodHint::ImhLowercaseOnly|Qt::InputMethodHint::ImhUppercaseOnly|Qt::InputMethodHint::ImhUrlCharactersOnly);
        btn_min->setIconSize(QSize(18, 18));
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        _2 = new QHBoxLayout(layoutWidget);
        _2->setObjectName("_2");
        _2->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(Login);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Login", " login to your account to continuo", nullptr));
        txt_email->setText(QString());
        txt_email->setPlaceholderText(QCoreApplication::translate("Login", "Email", nullptr));
        btn_login->setText(QCoreApplication::translate("Login", "Login", nullptr));
        txt_password->setText(QString());
        txt_password->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        label->setText(QCoreApplication::translate("Login", "Welcome Back", nullptr));
        btn_close->setText(QString());
        btn_min->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
