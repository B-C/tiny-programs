/***********************************************************************
*   Algorithme de Kruskal
*   ---------------------
*					18.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "in_out.h"
#include "kruskal.h"
#include "affichage.h"

int main(int argc, char *argv[])
{
	int nbSommets,nbAretes;
	Sommet *sommets=NULL;
	Arete *aretes=NULL, *arbreCouvrant=NULL;
	
	lecture(argc,argv,&sommets,&aretes,&nbSommets,&nbAretes);

	arbreCouvrant=kruskal(nbAretes,nbSommets,aretes);

	free(aretes);
	
	affichage(sommets,arbreCouvrant,nbSommets);
	
	sauvegarde(sommets,nbSommets,arbreCouvrant);	
	
	free(arbreCouvrant);
	free(sommets);

	return 0;
}

