/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on September 1, 2016, 11:53 PM
 * Purpose: 
 */

// System Libraries

// User Libraries
#include "Prob3TableInherited.h"

// Global Constants

// Function Prototypes

// Execution

int main(int argc, char** argv) {
    
    int rows=5;
    int cols=6;
    
    Prob3TableInherited tab("Problem3.txt",rows,cols);
    const int *naugT = tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++)
	{
		for(int j=0;j<=cols;j++)
		{
			cout<<augT[i*(cols+1)+j]<<" ";
		}
		cout<<endl;
	}
    
    return 0; // Exit
}

