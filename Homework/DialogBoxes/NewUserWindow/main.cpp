#include <QApplication>
#include <QMainWindow>
#include "LoginDialog.h"

LoginDialog *login;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login = new LoginDialog();
    login->show();
    return a.exec();
}
