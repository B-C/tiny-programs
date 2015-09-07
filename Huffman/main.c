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

#include "algo.h"

int main(int argc,char **argv)
{
	int error=0;

	if(argc>2)
	{
		if(argv[1][0]=='c')
			error=!codage(argv[2]);
			
		else if(argv[1][0]=='d')
			error=!decodage(argv[2]);
		else
			error=1;
	}
	else
		error=1;
		
	if(error)
		printf("Syntaxe incorecte : \n\t   d fichier_a_decoder\n\tou c fichier_a_coder\n\n");

	return 0;
}

