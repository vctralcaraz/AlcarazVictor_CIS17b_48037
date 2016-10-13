#include "surveydialog.h"



SurveyDialog::SurveyDialog(QWidget *parent) : QWidget(parent)
{
    QLabel *survDia = new QLabel(tr("Pick a Survey to participate in: "));
    QLabel *surv1   = new QLabel(tr("Movies"));
    QLabel *surv2   = new QLabel(tr("Games"));
    QLabel *surv3   = new QLabel(tr("TV"));
    QLabel *surv4   = new QLabel(tr("School Subjects"));
    QLabel *surv5   = new QLabel(tr("Career Choices"));

    QPushButton *button1 = new QPushButton(tr("GO!"));
    QPushButton *button2 = new QPushButton(tr("GO!"));
    QPushButton *button3 = new QPushButton(tr("GO!"));
    QPushButton *button4 = new QPushButton(tr("GO!"));
    QPushButton *button5 = new QPushButton(tr("GO!"));

    QHBoxLayout *one = new QHBoxLayout;
    one->addWidget(surv1);
    one->addWidget(button1);

    QHBoxLayout *two = new QHBoxLayout;
    two->addWidget(surv2);
    two->addWidget(button2);

    QHBoxLayout *three = new QHBoxLayout;
    three->addWidget(surv3);
    three->addWidget(button3);

    QHBoxLayout *four = new QHBoxLayout;
    four->addWidget(surv4);
    four->addWidget(button4);

    QHBoxLayout *five = new QHBoxLayout;
    five->addWidget(surv5);
    five->addWidget(button5);

    QVBoxLayout *dlog = new QVBoxLayout;
    dlog->addWidget(survDia);
    dlog->addLayout(one);
    dlog->addLayout(two);
    dlog->addLayout(three);
    dlog->addLayout(four);
    dlog->addLayout(five);

    setLayout(dlog);

}
