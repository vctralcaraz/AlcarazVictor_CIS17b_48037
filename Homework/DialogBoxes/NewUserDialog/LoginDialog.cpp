#include <iostream>
using namespace std;

#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent)
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

    userLine->setFixedWidth(150);
    passLine->setFixedWidth(150);

    username->setBuddy(userLine);
    password->setBuddy(passLine);

    passLine->setEchoMode(QLineEdit::Password);

    QHBoxLayout *top = new QHBoxLayout;
    top->addWidget(username);
    top->addWidget(userLine);

    QHBoxLayout *mid = new QHBoxLayout;
    mid->addWidget(password);
    mid->addWidget(passLine);

    QHBoxLayout *bot = new QHBoxLayout;
    bot->addWidget(submit);
    bot->addWidget(cancel);

    QVBoxLayout *window = new QVBoxLayout;
    window->addLayout(top);
    window->addLayout(mid);
    window->addLayout(bot);
    window->addWidget(git);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(window);
    setLayout(mainLayout);

    setWindowTitle(tr("Login"));
    setFixedSize(sizeHint());
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
