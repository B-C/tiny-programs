/*********************************************************************
*	
*	Montagne Fractale  materiaux.h
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#ifndef MATERIAUX_H
#define MATERIAUX_H

#ifndef BASIC

#include "general.h"

void materiaux(GLfloat couleur[4],GLfloat shininess);
/*
 * Gère la façon dont réagit chaque matériau à la lumière
 *																			  */

void eau();
void plaine();
void roche();
void rocheGrise();
void neige();

#endif

#endif

