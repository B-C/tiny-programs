#include "pos.h"

int Pos::nb()
{
    int s=0;
    if(nexts.size()==0)
        s=1;
    else
        for(unsigned int i=0 ; i<nexts.size() ; i++)
            s+=nexts[i]->nb();
    return s;
}
