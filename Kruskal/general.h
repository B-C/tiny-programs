/*********************************************************************
*
*	Structures et définitions globales
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#ifndef GENERAL_H
#define GENERAL_H

#define TAILLE_NOM_FICHIER 30

typedef struct Arete Arete;
typedef struct Sommet Sommet;

struct Arete
{
	int origine, extremite;
	double poids;
};

struct Sommet
{
	double x,y;
};

#endif
