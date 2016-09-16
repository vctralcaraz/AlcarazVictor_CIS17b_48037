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

    //adding everything to augTable
    int j = 0;      //table index
    int k = 0;      //rowSum index
    int m = 0;      //colSum index
    int count = 0;  //counter per row
    int newSize = (rows + 1) * (cols + 1);
    for(int i = 0; i < newSize; i++)
    {
        if(i >= rows * (cols +1))
        {
            augTable[i] = colSum [m++];
        }
        else
        {
            count++;
            augTable[i] = table[j++];
            if(count == 6)
            {
                augTable[++i] = rowSum[k++];
                count = 0;
            }
        }
    }
    
    augTable[newSize - 1] = grandTotal;
}

Prob3TableInherited::~Prob3TableInherited()
{
    delete [] augTable;
}