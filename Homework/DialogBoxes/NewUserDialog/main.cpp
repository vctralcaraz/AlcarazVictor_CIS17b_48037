#include <QApplication>
#include "LoginDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog *login = new LoginDialog;
//    login->setStyleSheet("background-image: url(./animeSchool.jpg);");
    login->show();

    return a.exec();
}
