#include <iostream>
using namespace std;

#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent) : QGraphicsView(parent)
{
    username = new QLabel;
    password = new QLabel;

    username->setText(tr("Username: "));
    password->setText(tr("Password: "));

    submit = new QPushButton(tr("Submit"));
    cancel = new QPushButton(tr("Cancel"));
    git = new QPushButton(tr("Rogue GitHub"));

    submit->setDefault(true);
    submit->setEnabled(false);

    userLine = new QLineEdit;
    passLine = new QLineEdit;

    connect(userLine, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableSubmitButton()));
    connect(passLine, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableSubmitButton()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(submit, SIGNAL(clicked()), this, SLOT(setUser()));
    connect(git, SIGNAL(clicked()), this, SLOT(website()));

    username->setBuddy(userLine);
    password->setBuddy(passLine);

    passLine->setEchoMode(QLineEdit::Password);

    // set widget backgrounds transparent
    username->setAttribute(Qt::WA_TranslucentBackground);
    password->setAttribute(Qt::WA_TranslucentBackground);
    submit->setAttribute(Qt::WA_TranslucentBackground);
    cancel->setAttribute(Qt::WA_TranslucentBackground);
    git->setAttribute(Qt::WA_TranslucentBackground);

    // initializing and setting the scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,400,301);

    // setting the background
    setBackgroundBrush(QBrush(QImage(":/images/Login_Background.jpg")));
    setScene(scene);

    // setting the size of the screen
    setFixedSize(400,301);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // setting the title for the window
    setWindowTitle(tr("Login"));

    // adding the widgets to the scene
    scene->addWidget(username);
    scene->addWidget(userLine);
    scene->addWidget(password);
    scene->addWidget(passLine);
    scene->addWidget(submit);
    scene->addWidget(cancel);
    scene->addWidget(git);

    // setting the placement of each widget
    //                   ( X,Y  , W,H )
    username->setGeometry(95,100,50,20);
    userLine->setGeometry(150,100,150,20);
    password->setGeometry(95,125,50,20);
    passLine->setGeometry(150,125,150,20);
    submit->setGeometry(95,150,100,20);
    cancel->setGeometry(200,150,100,20);
    git->setGeometry(95,175,205,25);
}

void LoginDialog::enableSubmitButton()
{
    bool ok = !userLine->text().isEmpty()
           && !passLine->text().isEmpty();
    submit->setEnabled(ok);
}

void LoginDialog::setUser()
{
    uName = userLine->text();
    pass = passLine->text();
    prntAll();
}

void LoginDialog::prntAll()
{
    string temp1 = uName.toStdString();
    string temp2 = pass.toStdString();
    cout << "Username: " << temp1 << endl;
    cout << "Password: " << temp2 << endl;
}

void LoginDialog::website()
{
    QDesktopServices::openUrl(QUrl("https://github.com/espinozahector/CIS17B_Rogue_Game"));
}
