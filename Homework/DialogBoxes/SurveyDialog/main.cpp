#include "surveydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SurveyDialog *survey = new SurveyDialog;
    survey->show();

    return a.exec();
}
