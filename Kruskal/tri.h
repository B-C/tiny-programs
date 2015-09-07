/*********************************************************************
*
*	Algorithme du tri tas
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#ifndef TRI_H
#define TRI_H

#include "general.h"

#define swap(type,a,b) {type aux=a; a=b; b=aux;}

void triTas(Arete *liste, int taille);
void creationTas(Arete *liste, int taille);
void insertion(Arete *liste, int indice);
void percolation(Arete *liste, int indiceIntrus, int taille);

#endif

