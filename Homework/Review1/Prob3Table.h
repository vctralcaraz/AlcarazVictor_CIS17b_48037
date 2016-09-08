/* 
 * File:   Prob3Table.h
 * Author: Victor Alcaraz
 * Created on September 1, 2016, 11:54 PM
 * Purpose: Classification of Prob3Table
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

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
        Prob3Table(char *, int, int);   //Constructor then Destructor
        ~Prob3Table() {delete [] table; delete [] rowSum; delete [] colSum;}
        const int *getTable(void) {return table;}
        const int *getRowSum(void) {return rowSum;}
        const int *getColSum(void) {return colSum;}
        int getGrandTotal(void) {return grandTotal;}
};

class Prob3TableInherited : public Prob3Table
{
protected:
    int *augTable;
public:
    Prob3TableInherited(char *, int, int);
    ~Prob3TableInherited() {delete [] augTable;}
    const int *getAugTable(void) {return augTable;}
};

#endif /* PROB3TABLE_H */

