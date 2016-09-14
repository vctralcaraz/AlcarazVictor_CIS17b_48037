/*
 * File:   Prob3TableInherited.cpp
 * Author: Victor Alcaraz
 * Created on September 12, 2016, 10:33 PM
 * Purpose:
 */

#include "Prob3TableInherited.h"

Prob3TableInherited::Prob3TableInherited(char const *file, int row, int col) :
                     Prob3Table(file, row, col)
{
    //declare augTable as dynamic array
    int size = ((rows + 1) * (cols + 1));
    augTable = new int[size];

    //initialize dynamic array to 0
    for(int i = 0; i < size; i++)
    {
        augTable[i] = 0;
    }

    //set table and sums to augTable
    int j = 0; //for sums array index
    int k = 0; //for table array index (from base class)
    int index = 0; //last know index for augTable
    int count = 0; //count number of output
    int nSize = rows * (cols + 1);
    for(int i = 0; i < nSize; i++)
    {
        count++;
        if(count == 7)
        {
            if(i == (nSize))
            {
                augTable[i++] = table[k];
                augTable[i] = rowSum[j];
                break;
            }
            augTable[i++] = rowSum[j++];
            count = 1;
        }
        if(i != nSize)
        {
            augTable[i] = table[k++];
            index = i;
        }
    }

    augTable[nSize] = rowSum[j];
    nSize--;

    //adding cols to augTable
    for(int i = 0; i < cols + 1; i++)
    {
        augTable[nSize++] = colSum[i];
    }

    augTable[((rows + 1) * (cols + 1))] = grandTotal;
}

Prob3TableInherited::~Prob3TableInherited()
{
    delete [] augTable;
}
