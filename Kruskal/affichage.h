/*********************************************************************
*
*	Affichage d'un graphe
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "general.h"

#define MARGE 10
#define RAYON 5
#define NOIR 0

void affichage(Sommet *sommets,Arete *arbreCouvrant,int nbSommets);

void dimension(Sommet *sommets, Sommet *min, Sommet *max,int nbSommets);

void wait(int n);

#endif

