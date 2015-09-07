/*********************************************************************
*	
*	Montagne Fractale  decoupage.h
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#ifndef DECOUPAGE_H
#define DECOUPAGE_H

#include "general.h"



Point3d** decoupPlan(int nbIterations, Point3d min, Point3d max);
/*
 * Fonction qui crée et initialise la matrice plan, puis qui appelle la fonction
 * decoupe.
 *																			  */

void decoupe(Point3d **plan,int minI, int maxI,int minJ, int maxJ);
/*
 * Fonction récursive qui découpe le plan et attribue une hauteur à chaque point
 *																			  */

Point3d pointDeSeg(Point3d A,Point3d B);
/*
 * Elle retourne un point situé sur le segment [A,B], à proximité du milieu du
 * segment (décalé d'une distance aléatoire, dépendant de conf)
 *																			  */

Point3d pointDeQuad(Point3d A,Point3d B,Point3d D);
/*
 * Retourne le centre de gravité de ABCD (approximé par un parallélogramme)  
 * légèrement déplacé
 *																			  */
 
GLfloat hauteur(Point3d a, Point3d b);
/*
 * Retourne une hauteur z dépendant de la hauteur de A et B, de la pente de AB,
 * de conf et d'une variable aléatoire.
 *																			  */

GLfloat hauteurCentre(Point3d a, Point3d b, Point3d c, Point3d d);
/*
 * Retourne une hauteur z qui dépend de la surface de ABCD,de la moyenne des
 * hauteurs de A, B, C, D, de conf ainsi que d'une variable aléatoire
 *																			  */

GLfloat surface(Point3d a, Point3d b, Point3d c, Point3d d);

GLfloat aireTriangle(Point3d a, Point3d b, Point3d c);

GLfloat borne(GLfloat a);
/*
 * Vérifie que a est dans [0,conf.hauteurMax], le modifie sinon
 * 																			  */

#endif

