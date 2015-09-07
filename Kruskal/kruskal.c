/*********************************************************************
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#include <stdlib.h>

#include "kruskal.h"
#include "tri.h"

Arete* kruskal(int nbAretes, int nbSommets, Arete aretes[])
{
	Arete *arbreCouvrant=(Arete*)malloc((nbSommets-1)*sizeof(Arete));
	//tableau des composantes connexes
	int *cC=(int*)malloc((nbSommets+1)*sizeof(int));
	int aux,i,compteurA=0,compteurAC=0;

	for(i=1 ; i<=nbSommets ; i++)
		cC[i]=i;
	
	triTas(aretes,nbAretes);

	while( compteurAC<nbSommets-1)
	{
		if(cC[aretes[compteurA].origine]!=cC[aretes[compteurA].extremite])
		{
			arbreCouvrant[compteurAC]=aretes[compteurA];
			compteurAC++;		
			
			aux=cC[aretes[compteurA].extremite];
			
			for( i=1 ; i<=nbSommets ; i++)
				if(cC[i]==aux)
					cC[i]=cC[aretes[compteurA].origine];
		}
		compteurA++;
	}
	free(cC);
	return arbreCouvrant;
}

