/*********************************************************************
*
*	Huffman
*	-------
*					
*
*					Bertrand CHAZOT
*
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algo.h"

#define TAILLE_NOM_FICHIER 30

void destruct(Arbre abr);

int codage(char *fichier)
{
    	FILE *fichierLu=fopen(fichier,"r");
    	FILE *fichierCode=NULL;
	char code[256][14];
	int noError=1,fini=0;

	if(fichierLu==NULL)
		noError=0;
	else
	{
		if(tableauHuffman(code))
		{
			fichierCode=save();

			while(!fini)
				fini=codeCarac(fichierCode,fgetc(fichierLu),code);
				
			fclose(fichierCode);
		}
		fclose(fichierLu);
	}
	
	return noError;
}


int decodage(char *fichier)
{
    	FILE *fichierDecode,*fichierCode=fopen(fichier,"r");
    	Arbre abrH,abrCourant;
	int noError=1,i,fini=0;
	char octetCourant;


	if(fichierCode==NULL)
		noError=0;
	else
	{
		abrH=arbreHuffman();
		
		if(abrH!=NULL)
		{
			fichierDecode=save();
		
			abrCourant=abrH;
			
			while(!fini)
			{
				octetCourant=fgetc(fichierCode);
				for(i=1 ; (i<=8)&&(!fini) ; i++)
				{
					if((octetCourant>>(8-i))&1)//on lit un 1
						abrCourant=abrCourant->fd;
					else	
						abrCourant=abrCourant->fg;				
					
					if(abrCourant->fg==NULL)//pas de fils->caractere
					{
						if(abrCourant->carac==0)
							fini=1;
						else
						{
							fprintf(fichierDecode,"%c",abrCourant->carac);
							abrCourant=abrH;
						}
					}
				
				}
			
			}
			destruct(abrH);
		}		
		
		fclose(fichierCode);
	}
	
	return noError;
}

int tableauHuffman(char code[][14])
{
    	FILE *fichier=fopen("huff256.cod","r");
    	int i,noError=1;
	


	if (fichier==NULL)
	{	
        	printf("Erreur : table huff256.cod non presente.\n\n");
        	noError=0;
        }
	else
	{
		fscanf(fichier,"%*d");
	
		for(i=0 ; i<256 ; i++)
		{
			fscanf(fichier,"%*d%s",code[i]);
		}
		fclose(fichier);
	}
	
	return noError;
}

Arbre arbreHuffman()
{
	Arbre abrH=NULL, abrCourant;
    	FILE *fichier=fopen("huff256.cod","r");
    	int i,j;
    	char codeCourant[14];


	if (fichier==NULL)
        	printf("Erreur : table huff256.cod non presente.\n\n");
	else
	{
		abrH=creatNoeud();
		
		fscanf(fichier,"%*d");
		
		for(i=0 ; i<256 ; i++)
		{
			fscanf(fichier,"%*d%s",codeCourant);
			
			abrCourant=abrH;

			for(j=0 ; j<strlen(codeCourant) ; j++)
			{	
				if(abrCourant->fg==NULL)//arbre complet
				{
					abrCourant->fg=creatNoeud();
					abrCourant->fd=creatNoeud();
				}			
				if(codeCourant[j]=='0')
					abrCourant=abrCourant->fg;				
				else
					abrCourant=abrCourant->fd;
			}
			abrCourant->carac=(char)i;
		}
		fclose(fichier);
		
	}

	return abrH;
}

int codeCarac(FILE *fichierCode, char carac, char code[][14])
{
	static int compteur=0;
	static char octetCourant=0;
	int i,fini=0;

	if(carac==EOF)
	{
		fini=1;
		carac=0;
	}
	
	for(i=0 ; i<strlen(code[(int)carac]) ; i++)
	{
		octetCourant=octetCourant<<1;
		compteur++;
		
		if(code[(int)carac][i]=='1')
			octetCourant++;
		
		if(compteur==8)
		{
			fputc(octetCourant,fichierCode);
			compteur=0;
		}
	}
	
	if(fini&&compteur)
		fputc(octetCourant<<(8-compteur),fichierCode);



	return fini;
}

Arbre creatNoeud()
{
	Arbre new=(Arbre)malloc(sizeof(Noeud));
	
	new->fg=NULL;
	new->fd=NULL;
	return new;
}

void destruct(Arbre abr)
{
	if(abr!=NULL)
	{
		destruct(abr->fg);
		destruct(abr->fd);
		free(abr);
	}
}

FILE* save()
{
	FILE *fichier=NULL;
	char nom[TAILLE_NOM_FICHIER];
	
	while (fichier==NULL)
	{
		printf("Ou sauvegarder ?\n");
		scanf("%s",nom);

		fichier=fopen(nom,"r");

		if (fichier!=NULL)
		{
			fclose(fichier);
			printf("Ce fichier existe deja.\n");
			fichier=NULL;
		}
		else
				fichier=fopen(nom,"w");
	}

	return fichier;
}



