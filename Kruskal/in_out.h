/*********************************************************************
*
*	lecture/ecriture d'un fichier contenant un graphe
*
*					18.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#ifndef INOUT_H
#define INOUT_H

#include "general.h"

void lecture(int argc, char *argv[], Sommet **sommets, Arete **aretes,
	     int *nbSommets, int *nbAretes);

int poids(Sommet sommet1, Sommet sommet2);

void sauvegarde(Sommet *sommets,int nbSommets, Arete *abrCouvrant);

#endif
