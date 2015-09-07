/*********************************************************************
*	
*	Montagne Fractale  materiaux.c
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#ifndef BASIC

#include "materiaux.h"

void materiaux(GLfloat couleur[4],GLfloat shininess)
{
	GLfloat noir[4] = {0,0,0,1};
	GLfloat blanc [4] = {1, 1, 1, 1.0};
	
	glMaterialfv (GL_FRONT, GL_AMBIENT_AND_DIFFUSE, couleur);
	if(shininess)
		glMaterialfv (GL_FRONT, GL_SPECULAR, blanc);
	else
		glMaterialfv (GL_FRONT, GL_SPECULAR, noir);
		
	glMaterialf (GL_FRONT, GL_SHININESS, shininess);
}

void eau()
{
	GLfloat bleu [4] = {0.2, 0.4, 1, 1.0};
	materiaux(bleu,50);
}

void plaine()
{
	GLfloat vert[4] = {0,0.4,0, 1.0};
	materiaux(vert,0);
}

void roche()
{
	GLfloat marron [4] = {0.4,0.2,0, 1.0};
	materiaux(marron,0);
}

void rocheGrise()
{
	GLfloat gris [4] = {0.4,0.4,0.4, 1.0};
	materiaux(gris,0);
}

void neige()
{
	GLfloat blanc [4] = {1, 1, 1, 1.0};
	materiaux(blanc,20);
}

#endif

