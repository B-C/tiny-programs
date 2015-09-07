/*********************************************************************
*
*	Huffman
*	-------
*					
*
*					Bertrand CHAZOT
*
************************************************************************/

#ifndef ALGO_H
#define ALGO_H

typedef struct noeud Noeud;

struct noeud
{
	char carac;
	struct noeud *fg, *fd;
};

typedef Noeud* Arbre;

int codage(char *fichier);
int decodage(char *fichier);

int tableauHuffman(char code[][14]);
Arbre arbreHuffman();
Arbre creatNoeud();
void destruct(Arbre abr);

int codeCarac(FILE *fichierCode, char carac, char code[][14]);

FILE* save();

#endif
