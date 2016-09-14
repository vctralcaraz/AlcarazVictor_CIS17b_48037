/*
 * File:   Prob3Table.cpp
 * Author: Victor Alcaraz
 * Created on September 2, 2016, 12:01 AM
 * Purpose:
 */
#include "Prob3Table.h"

Prob3Table::Prob3Table(char const *file, int row, int col)
{
//    cout << "Initializing..." << endl << endl;
    //initialize variables
    ifstream fin;

    //initialize rows and cols
    rows = row;
    cols = col;
    grandTotal = 0;

//    cout << "row: " << row << endl;
//    cout << "col: " << col << endl;
    //open file
    fin.open(file);

    //check if the file was properly opened
    if(fin.fail())
    {
        cout << "There was an error opening the file\n";
        exit(1);
    }

    //declare dynamic arrays
    int size = cols * rows;
    table = new int[size];
    rowSum = new int[rows];
    colSum = new int[cols];


    //initialize all arrays to 0
    for(int i = 0; i < size; i++)
    {
        table[i] = 0;
    }

    for(int i = 0; i < rows; i++)
    {
        rowSum[i] = 0;
    }

    for(int i = 0; i < cols; i++)
    {
        colSum[i] = 0;
    }

//    cout << "setting base table..." << endl << endl;
    //reading from a file and storing values to array
    char temp;
    string temp2 = "";
    int i = 0;
    int count = 0;
    int tCount = 0; //test total number of input numbers
    while(!fin.eof())
    {
        fin >> temp;
        count++;
        temp2 += temp;

        if(count == 3)
        {
            int temp = atoi(temp2.c_str());
            table[i] = temp;
            i++;
            temp2 = "";
            count = 0;
            tCount++;

        }
    }
//    cout << "Total number of variables: " << tCount << endl;
//    cout << "outputting base table..." << endl;
//    for(int j = 0; j < size; j++)
//    {
//        if(j % cols == 0) cout << endl;
//        cout << table[j] << ' ';
//    }
//    cout << endl;

//    cout << "done outputting base table..." << endl << endl;
    fin.close();

//    cout << "calculating table..." << endl;
    calcTable();
//    cout << "done calculating..." << endl;
}

Prob3Table::~Prob3Table()
{
//    cout << "deleting base dynamic variables... " << endl;
    delete [] table;
    delete [] rowSum;
    delete [] colSum;
//    cout << "done deleting base variables... " << endl;
}


void Prob3Table::calcTable(void)
{
    int size = cols * rows;

    //getting the sum of rows
    int sum = 0; //sum of each row
    int k = 0;   //sum array index
    for(int i = 0; i < size; i++)
    {
        if(i % cols == 0 && i != 0)
        {
            rowSum[k++] = sum;
            sum = 0;
        }
        sum += table[i];

        if(i == size - 1)
        {
            rowSum[k] = sum;
        }
    }

//    cout << "grand total: " << grandTotal << endl;
//    for(int i = 0; i < rows; i++)
//    {
//        cout << rowSum[i] << ' ';
//    }
//    cout << endl;

    //getting the sum of the cols
    sum = 0; //sum of each col
    int j = 0;   //sum array index
    for(int i = 0; i < cols; i++)
    {
        for(int k = 0; k < rows; k++)
        {
            sum += table[i + (k * cols)];
        }

        colSum[++j] = sum;
        sum = 0;
    }

//    cout << "outputting colSum... " << endl;
//    for(int i = 0; i < cols; i++)
//    {
//        cout << colSum[i] << ' ';
//    }
//    cout << endl;
}
