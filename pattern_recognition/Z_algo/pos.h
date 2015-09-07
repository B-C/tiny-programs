#ifndef POS_H
#define POS_H

#include <vector>
#include <iostream>
using namespace std;

/**
  * Used when there is wildcard
  * The goal is to a tree
  * A path from the root to a leaf contains the position of each subpatern in T
  */

struct Pos
{
    int indice, size;
    vector<Pos*> nexts;
    Pos(int ind, int _size):indice(ind),size(_size){}

    void addNext(Pos* next)
    {
        if(next->indice>=indice+size)
            nexts.push_back(next);
    }
    int nb();
};

#endif // POS_H
