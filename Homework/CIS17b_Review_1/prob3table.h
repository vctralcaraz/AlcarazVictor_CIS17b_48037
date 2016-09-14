#ifndef PROB3TABLE_H
#define PROB3TABLE_H

//system libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <QtCore>
using namespace std;

//base class
class Prob3Table
{
    protected:
        int rows;               //Number of rows in the table
        int cols;               //Number of cols in the table
        int *rowSum;            //RowSum array
        int *colSum;            //ColSum array
        int *table;             //Table array
        int grandTotal;         //Grand Total
        void calcTable(void);   //Calculate all the sums
    public:
        Prob3Table(char const *, int, int);   //Constructor
        ~Prob3Table();                  //Destructor
        const int *getTable(void) {return table;}
        const int *getRowSum(void) {return rowSum;}
        const int *getColSum(void) {return colSum;}
        int getGrandTotal(void) {return grandTotal;}
};

#endif // PROB3TABLE_H
