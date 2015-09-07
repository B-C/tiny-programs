/*********************************************************************
*	
*	Montagne Fractale  affichage.h
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "general.h"

void montagne();
/* 
 * Fonction appelant decoupPlan pour remplir la display list. Elle redécoupe 
 * chaque quadrilatère de plan en deux triangles, leur attribue une couleur en
 * fonction de leur altitude et calcule leur vecteur normal, nécessaire pour la
 * gestion de la luminosité grâce à des fonctions auxiliaires
 *																			  */

void vertexColor(GLfloat x, GLfloat y, GLfloat z);
/*
 * Associe une couleur en fonction de la hauteur
 *																			  */

void init();
/*
 * Initialisation de la fenêtre
 *																			  */

void affichage();
/*
 * Affichage de la display list
 *																			  */

void reshape(int w, int h);
/*
 * Appelée lors du déplacement/redimensionnement de la fenêtre
 *																			  */

void creationDisplayList();

void triangle(Point3d a, Point3d b, Point3d c);
/*
 * Gestion de chaque polygone (couleur, vecteur normal)
 *																			  */

void clavier(unsigned char touche, int x, int y);
/*
 * Gestion d'évènements : rotation de la montagne ...
 *																			  */
 
void clavierSpecial(int touche, int x, int y);
/*
 * Gestion d'évènements
 *																			  */

Point3d prodVect(Point3d a, Point3d b,Point3d c);
/*
 * Produit vectoriel de AB et AC
 *																			  */

#endif

