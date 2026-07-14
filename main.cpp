#include <QApplication>
#include <QCursor>
#include <QPixmap>
#include <QDebug>
#include <login.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet(
        "QMainWindow, QDialog#Patient, QDialog#AppointmentDialog, QStackedWidget {"
        "   background-color: #161B22;"
        "}"

        "QMessageBox {"
        "   background-color: #F0F0F0;"
        "}"
        "QMessageBox QLabel {"
        "   color: #000000;"
        "   font-size: 14px;"
        "}"
        "QMessageBox QPushButton {"
        "   background-color: #E1E1E1;"
        "   color: #000000;"
        "   padding: 5px 15px;"
        "   border-radius: 4px;"
        "   min-width: 80px;"
        "}"
        );

    QPixmap originalCursorPixmap(":/img/cursor.png");

    if (originalCursorPixmap.isNull()) {
        qDebug() << "Error: Could not load cursor image.";
    }

    int newCursorWidth = 16;
    int newCursorHeight = 16;

    QPixmap scaledCursorPixmap = originalCursorPixmap.scaled(newCursorWidth, newCursorHeight,
                                                             Qt::KeepAspectRatio,
                                                             Qt::SmoothTransformation);

    QCursor customCursor(scaledCursorPixmap);
    a.setOverrideCursor(customCursor);

    Login w;
    w.show();

    int result = a.exec();

    a.restoreOverrideCursor();

    return result;
}