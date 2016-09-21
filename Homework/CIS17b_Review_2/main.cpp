#include <QCoreApplication>
#include <QApplication>
#include <QLabel>
#include "prob3tableinherited.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);

    int rows=5;
    int cols=6;

    Prob3TableInherited tab("Problem3.txt",rows,cols);
    const int *naugT = tab.getTable();
    QString Qrows;

    //adding values to the string array
    char temp[10];
    int size = rows * cols;
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        itoa(naugT[i],temp,10);
        Qrows += temp;
        Qrows += ' ';
        count++;
        if(count == cols)
        {
            Qrows += "<br>";
            count = 0;
        }
    }
    Qrows += "<br><br>";

//    for(int i=0;i<rows;i++)
//    {
//        for(int j=0;j<cols;j++)
//        {
//            //naugT[i*cols+j];
//        }
//        cout<<endl;
//    }
//    cout<<endl;

    const int *augT=tab.getAugTable();
//    for(int i=0;i<=rows;i++)
//    {
//        for(int j=0;j<=cols;j++)
//        {
//            cout<<augT[i*(cols+1)+j]<<" ";
//        }
//        cout<<endl;
//    }
    int nSize = (cols + 1) * (rows + 1);
    for(int i = 0; i < nSize; i++)
    {
        itoa(augT[i],temp,10);
        Qrows += temp;
        Qrows += ' ';
        count++;
        if(count == (cols + 1))
        {
            Qrows += "<br>";
            count = 0;
        }
    }

    QLabel *label = new QLabel(Qrows);
    label->show();

//    return 0;
    return a.exec();
}
