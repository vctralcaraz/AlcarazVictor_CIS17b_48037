#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>
#include <QString>
//#include <QImage>
//#include <QBrush>
#include <QPixmap>
#include <QPalette>
#include <QtGui>

class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = 0);
    void checkLineEdits();
    void prntAll();

private:
    QString uName;
    QString pass;
    QLabel *username;
    QLabel *password;
    QLineEdit *userLine;
    QLineEdit *passLine;
    QPushButton *submit;
    QPushButton *cancel;
    QPushButton *git;

private slots:
    void enableSubmitButton();
    void setUser();
    void website();
};

#endif // LOGINDIALOG_H
