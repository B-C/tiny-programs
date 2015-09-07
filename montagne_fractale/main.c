/*********************************************************************
*	
*	Montagne Fractale  main.c
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#include <time.h>

#include "affichage.h"
#include "general.h"
#include "lecture.h"

int main(int argc, char **argv)
{
	// Initialisation du LCG
	srand(time(NULL));

	// Lecture des conditions de départ
	lecture();
	
	// Initialisation de GLUT
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(conf.longueur,conf.largeur);
	glutInitWindowPosition(10,10);
	glutCreateWindow(argv[0]);
	
	// Initialisation d'OpenGL
	init();
	
	// Callbacks
	glutReshapeFunc(reshape);
	glutKeyboardFunc(clavier);
	glutSpecialFunc(clavierSpecial);
	glutDisplayFunc(affichage);
	glutMainLoop();
	
	return 0;
}
