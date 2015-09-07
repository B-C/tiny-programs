/*********************************************************************
*
*	lecture d'un fichier contenant un graphe
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#ifndef LECTURE_H
#define LECTURE_H

#include "general.h"

void lecture(int argc, char *argv[], Sommet **sommets, Arete **aretes,int *nbSommets, int *nbAretes);

int poids(Sommet sommet1, Sommet sommet2);

#endif
