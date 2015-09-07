/*********************************************************************
*	
*	Montagne Fractale  affichage.c
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#include "affichage.h"
#include "decoupage.h"
#include "lecture.h"

#include "materiaux.h"

void  montagne()
{
	int i,n=(1<<conf.nbIterations)+1,j;
	Point3d min,max;
	
	// Initialisation
	min.x=-conf.coteMontagne; min.y=-conf.coteMontagne; min.z=0;
	max.x=conf.coteMontagne; max.y=conf.coteMontagne; min.z=0;
	
	// Découpage du plan et calcul des hauteurs
	Point3d **matriceMontagne=decoupPlan(conf.nbIterations, min, max);

	// Création des Polygones
	glBegin(GL_TRIANGLES);
		for(j=0 ; j<n-1 ; j++)
		{
			for(i=0 ; i<n-1 ; i++)
			{
				triangle(matriceMontagne[i][j+1],matriceMontagne[i+1][j],matriceMontagne[i][j]);
				triangle(matriceMontagne[i+1][j+1],matriceMontagne[i+1][j],matriceMontagne[i][j+1]);
	      	}
		}
	glEnd();
	
	// Libération de la mémoire
	for(i=0 ; i<n ; i++)
	{
		free(matriceMontagne[i]);
	}
	free(matriceMontagne);
}

#ifdef BASIC

void vertexColor(GLfloat x, GLfloat y, GLfloat z)
{
	if(z<conf.hauteurMax/15)
		glColor3ub(51,102,255);
	else if(z<conf.hauteurMax/6)
		glColor3ub(0,102,0);
	else if(z<conf.hauteurMax/3)
		glColor3ub(102,51,0);
	else if(z< conf.hauteurMax/2.5)
		glColor3ub(0.4,0.4,0.4);
	else
		glColor3ub(255,255,255);
		
	glVertex3d(x,y,z);
}

#else

void vertexColor(GLfloat x, GLfloat y, GLfloat z)
{
	if(z<conf.hauteurMax/15)
		eau();
	else if(z<conf.hauteurMax/6)
		plaine();
	else if(z<conf.hauteurMax/3)
		roche();
	else if(z< conf.hauteurMax/2.5)
		rocheGrise();
	else
		neige();
			
	glVertex3d(x,y,z);
}

#endif

void init()
{
	GLfloat ambient [4] = {0.5, 0.5, 0.5, 1.0};
	GLfloat blanc [4] = {1,1,1,1};
	
	GLfloat light_position[]={conf.positionSoleil.x,conf.positionSoleil.y,conf.positionSoleil.z,0};

	glClearColor(0.4,0.8,1,1);// création du ciel
	glShadeModel(GL_SMOOTH);//dégradé de couleur pour le modèle

	// Configuration du "soleil" LIGHT0
	glLightfv(GL_LIGHT0, GL_POSITION,light_position);
	glLightfv (GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, blanc);

	#ifdef BASIC
	glEnable(GL_COLOR_MATERIAL);	
	#endif
	glEnable(GL_NORMALIZE);//normalisation des vecteurs normaux
	glEnable(GL_LIGHTING);//on active la lumière
	glEnable(GL_LIGHT0);//on active la source lumineuse 0
	glEnable(GL_DEPTH_TEST);//pour que ce qui est devant s'affiche devant
	
	// Creation de l'objet montagne
	creationDisplayList();
}

void affichage(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glCallList(laMontagne);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,conf.longueur/conf.largeur,1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(15,20,15,0,0,0,0,0,1);
}

void creationDisplayList()
{
	laMontagne=glGenLists(1);
	
	glNewList(laMontagne, GL_COMPILE);
		montagne();
	glEndList();
}

void triangle(Point3d a, Point3d b, Point3d c)
{
	Point3d normal=prodVect(a,b,c);
	
	glNormal3d(normal.x,normal.y,normal.z);
	vertexColor(a.x,a.y,2*a.z);
	vertexColor(b.x,b.y,2*b.z);
	vertexColor(c.x,c.y,2*c.z);
}

void clavier(unsigned char touche, int x, int y)
{
	switch(touche)
	{
	case 'r':
	case 'R'://on calcule une nouvelle montagne
		glDeleteLists(laMontagne,1);
		creationDisplayList();
		glutPostRedisplay();
		break;
	case 'x':
	case 'X':
		glRotatef(5,1.0,0.0,0.0);
		glutPostRedisplay();
		break;
	case 'y':
	case 'Y':
		glRotatef(5,0.0,1.0,0.0);
		glutPostRedisplay();
		break;
	case 'z':
	case 'Z':
		glRotatef(5,0.0,0.0,1.0);
		glutPostRedisplay();
		break;
	case 'i':
	case 'I':
		glLoadIdentity();
		gluLookAt(15,20,15,0,0,0,0,0,1);
		glutPostRedisplay();		
		break;
	case 27://echap
		exit(0);
		break;
	}	
}
		
void clavierSpecial(int touche, int x, int y)
{
	switch(touche)
	{
	case GLUT_KEY_PAGE_UP :	
		if(conf.nbIterations<10)
		{
			conf.nbIterations++;
			glDeleteLists(laMontagne,1);
			creationDisplayList();
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_PAGE_DOWN :
		if(conf.nbIterations>0)
		{
			conf.nbIterations--;
			glDeleteLists(laMontagne,1);
			creationDisplayList();
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_HOME ://on calcule une nouvelle montagne + relecture des conditions de départ
		glDeleteLists(laMontagne,1);
		lecture();
		creationDisplayList();
		glutPostRedisplay();
		break;
	}	
}

Point3d prodVect(Point3d a, Point3d b,Point3d c)
{
	Point3d AB,AC,normal,z;

	z.x=0;z.y=0;z.z=1;
	AB.x=b.x-a.x;AB.y=b.y-a.y;AB.z=b.z-a.z;
	AC.x=c.x-a.x;AC.y=c.y-a.y;AC.z=c.z-a.z;

	normal.x=AB.y*AC.z-AB.z*AC.y;
	normal.y=AB.z*AC.x-AB.x*AC.z;
	normal.z=AB.x*AC.y-AB.y*AC.x;

	return normal;
}

