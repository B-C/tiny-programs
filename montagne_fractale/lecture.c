/*********************************************************************
*	
*	Montagne Fractale  lecture.c
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#include <stdio.h>

#include "lecture.h"

void lecture()
{
	FILE *fichier=fopen("config.dta","r");

	if(fichier!=NULL)
	{
		fscanf(fichier,"%*s%f%*s%f",&conf.largeur,&conf.longueur);
		fscanf(fichier,"%*s%d",&conf.nbIterations);
		fscanf(fichier,"%*s%f",&conf.hauteurMax);
		fscanf(fichier,"%*s%f",&conf.coteMontagne);
		fscanf(fichier,"%*s%f%f%f",&conf.positionSoleil.x,&conf.positionSoleil.y,&conf.positionSoleil.z);
		fscanf(fichier,"%*s%d%d",&conf.minS,&conf.maxS);
		fscanf(fichier,"%*s%d%d",&conf.minG,&conf.maxG);

		fclose(fichier);	
	}
	
	else
	{
		printf("\n#Pas de fichier de configuration\n");
		conf.largeur=480; conf.longueur=640;

		printf("\nCombien d'iterations ? (max 10)");
		scanf("%d",&conf.nbIterations);
		if(conf.nbIterations>10)
			conf.nbIterations=10;
			
		printf("\nPosition du soleil :");
		scanf("%f%f%f",&conf.positionSoleil.x,&conf.positionSoleil.y,&conf.positionSoleil.z);
		
		printf("\nHauteur maximum :");
		scanf("%f",&conf.hauteurMax);
		
		printf("\nLargeur de la Montagne :");
		scanf("%f",&conf.coteMontagne);
		
		printf("\n#Configuration de la découpe\n");
		printf("\nVariation position découpage de segment x2 (Pourcentage) :");
		scanf("%d%d",&conf.minS,&conf.maxS);
		printf("\nVariation position centre de gravité x2(Pourcentage) :");
		scanf("%d%d",&conf.minG,&conf.maxG);
		printf("\n\n");
	}	
}

