/*********************************************************************
*
*					17.11.09
*
*					Bertrand CHAZOT
*
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lecture.h"

void lecture(int argc, char *argv[], Sommet **sommets, Arete **aretes,int *nbSommets, int *nbAretes)
{
	int compteur=0,i,j;
	char caracCourant='a',caracPrecedent;
	int buff; //pour données inutile dans fscanf
	
    	FILE *fichier=NULL;
	char nom[TAILLE_NOM_FICHIER];


	if (argc>1)
        	fichier=fopen(argv[1],"r");

	while (fichier==NULL)
	{
		printf("Nom du fichier ?\n\t");
		scanf("%s",nom);
		fichier=fopen(nom,"r");
	}

	fscanf(fichier,"%d",nbSommets);
	
	
// on compte le nombre de lignes du fichier 
	
	do
	{
		caracPrecedent=caracCourant;
		caracCourant=fgetc(fichier);
		if(caracCourant=='\n'&&caracPrecedent!='\n')// pour ne pas compter les lignes vides
			compteur++;
	}
	while(caracCourant!=EOF);
			
	compteur--;//on ne compte pas la première ligne(*nbSommets)
	
	fseek(fichier,2,SEEK_SET);
	
	(*sommets)=(Sommet*)malloc((*nbSommets+1)*sizeof(Sommet));//sommets indexé à partir de 1
	
	if(compteur==(*nbSommets))
	// 2 cas (fonction du type de fichier)
	{
		for(i=1 ; i<=(*nbSommets) ; i++)
			fscanf(fichier,"%lf%lf",&(*sommets)[i].x,&(*sommets)[i].y);
	
		*nbAretes=(compteur*(compteur-1))/2;//le graphe est complet
		(*aretes)=(Arete *)malloc((*nbAretes+1)*sizeof(Arete));// idem aretes indexé a partir de 1
		
		compteur=1;
		
		for(i=1 ; i<(*nbSommets) ; i++)
			for(j=i+1 ; j<=(*nbSommets) ; j++)
			{
				(*aretes)[compteur].origine=i;
				(*aretes)[compteur].extremite=j;
				(*aretes)[compteur].poids=poids((*sommets)[i],(*sommets)[j]);
				compteur++;
			}	
	}	
	
	else
	{
		for(i=1 ; i<=(*nbSommets) ; i++)
			fscanf(fichier,"%d%lf%lf",&buff,&(*sommets)[i].x,&(*sommets)[i].y);
		
		*nbAretes=compteur-(*nbSommets);
		(*aretes)=(Arete *)malloc((*nbAretes+1)*sizeof(Arete));
		
		for(i=1 ; i<=(*nbAretes) ; i++)
			fscanf(fichier,"%d%d%lf",&(*aretes)[i].origine,&(*aretes)[i].extremite,&(*aretes)[i].poids);

	}
	
	fclose(fichier);	
}


int poids(Sommet sommet1, Sommet sommet2)
{
	return sqrt(pow(sommet1.x-sommet2.x,2)+pow(sommet1.y-sommet2.y,2));
}


