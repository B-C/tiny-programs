/*********************************************************************
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#include <stdio.h>
#include <graphique.h>

#include "affichage.h"

void affichage(Sommet *sommets,Arete *arbreCouvrant,int nbSommets)
{
    	int i;
	Sommet min, max;
  
	dimension(sommets, &min, &max,nbSommets);
  
	Initialisation_Graphique(min.x-MARGE,min.y-MARGE,max.x+MARGE,max.y+MARGE);
	
	//tracé des sommets
	
	for(i=1 ; i<=nbSommets ; i++)
		Cercle(sommets[i].x,sommets[i].y,RAYON,NOIR);
  
	//tracé des aretes
	
	for(i=0 ; i<(nbSommets-1) ; i++)
	{
		wait(15000);
		Trait(sommets[arbreCouvrant[i].origine].x, 
		      sommets[arbreCouvrant[i].origine].y,
		      sommets[arbreCouvrant[i].extremite].x, 
		      sommets[arbreCouvrant[i].extremite].y,(i%13)+1);
	}
  
	fflush(stdin);
	getchar();
	Fin_Graphique();
	
}

void dimension(Sommet *sommets, Sommet *min, Sommet *max,int nbSommets)
{
	int i;
	
	(*min)=sommets[1];
	(*max)=sommets[1];
	
	for(i=2 ; i<=nbSommets ; i++)
	{
		if(sommets[i].x<(*min).x)
			(*min).x=sommets[i].x;
		
		if(sommets[i].y<(*min).y)
			(*min).y=sommets[i].y;
			
		if(sommets[i].x>(*max).x)
			(*max).x=sommets[i].x;
			
		if(sommets[i].y>(*max).y)
			(*max).y=sommets[i].y;
	}
}

void wait(int n)
{
	int j,k;
	
	for(j=0 ; j<n ; j++)
		for(k=0 ; k<n ; k++);
}			

