/*********************************************************************
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#include "tri.h"

void triTas(Arete *liste, int taille)
{
    int i;

    creationTas(liste,taille);

    for (i=taille ; i>=2 ; i--)
    {
        swap(Arete,liste[1],liste[i]);
        percolation(liste,1,i-1);
    }
}

void creationTas(Arete *liste, int taille)
{
    int i;

    for (i=2 ; i<=taille ; i++)
        insertion(liste,i);
}

void insertion(Arete *liste, int indice)
{
    int i=indice;
    Arete pivot=liste[indice];

    while (i>=2 && pivot.poids>liste[i/2].poids)
    {
        liste[i]=liste[i/2]; // on descend liste[i/2]
        i/=2;
    }
    liste[i]=pivot;
}

void percolation(Arete *liste, int indiceIntrus, int taille)
{
    int fini=0, i=indiceIntrus, indiceMax;
    Arete intrus=liste[indiceIntrus];

    while (!fini && 2*i<=taille)
    {
        if (2*i==taille)
            indiceMax=taille;
        else if(liste[2*i].poids>=liste[2*i+1].poids)
                indiceMax=2*i;
            else
                indiceMax=2*i+1;

        if(intrus.poids<liste[indiceMax].poids)
        {
            liste[i]=liste[indiceMax]; // on remonte Max
            i=indiceMax;
        }
        else
            fini=1;
    }
    liste[i]=intrus;
 }

