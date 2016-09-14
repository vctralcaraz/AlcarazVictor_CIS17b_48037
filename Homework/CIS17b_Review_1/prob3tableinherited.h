#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"

//inherited class (from Prob3Table)
class Prob3TableInherited : public Prob3Table
{
protected:
    int *augTable;
public:
    Prob3TableInherited(char const *, int, int);
    ~Prob3TableInherited();
    const int *getAugTable(void) {return augTable;}
};

#endif // PROB3TABLEINHERITED_H
