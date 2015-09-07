/*********************************************************************
*	
*	Montagne Fractale  general.h
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#ifndef GENERAL_H
#define GENERAL_H

#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

//#define BASIC // Si définie, gestion des couleurs plus basique (moins d'effets)

typedef struct Point3d Point3d;
struct Point3d
{
	GLfloat x,y,z;
};

typedef struct Configuration Configuration;
struct Configuration
{
	GLfloat largeur,longueur;

	int nbIterations;
	GLfloat hauteurMax;
	GLfloat coteMontagne;
	Point3d positionSoleil;
	int minS, maxS;
	int minG, maxG;
};

// Variables globales
Configuration conf;
GLuint laMontagne;//display list


#endif

