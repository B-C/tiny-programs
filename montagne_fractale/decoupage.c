/*********************************************************************
*	
*	Montagne Fractale  decoupage.c
*   -----------------
*										02.01.10
*
*										Bertrand CHAZOT
*
*********************************************************************/

#include <math.h>
#include "decoupage.h"

Point3d** decoupPlan(int nbIterations, Point3d min, Point3d max)
{
	int i, n=((1<<nbIterations)+1);
	Point3d **plan;
	
	// allocation dynamique
	plan=(Point3d **) malloc(n*sizeof(Point3d *));

	for(i=0 ; i<n ; i++)
		plan[i]=(Point3d *)malloc(n*sizeof(Point3d));

	// initialisation
	plan[0][0]=min;
	plan[n-1][n-1]=max;
	plan[n-1][0].x=min.x; plan[n-1][0].y=max.y,plan[n-1][0].z=0;
	plan[0][n-1].x=max.x; plan[0][n-1].y=min.y,plan[0][n-1].z=0;
	
	// appel de la fonction auxiliaire	
	decoupe(plan,0,n-1,0,n-1);
	
	return plan;
}

void decoupe(Point3d **plan,int minI, int maxI, int minJ, int maxJ)
{
	int milieuI=(maxI+minI)/2, milieuJ=(maxJ+minJ)/2;

	// gestion du découpage du plan et de la hauteur
	
	if(minJ==0)//si on est "en haut"
	{
		plan[milieuI][minJ]=pointDeSeg(plan[minI][minJ],plan[maxI][minJ]);
		plan[milieuI][maxJ].z=hauteur(plan[minI][maxJ],plan[maxI][maxJ]);
	}

	if(minI==0)//si on est "à gauche"
	{
		plan[minI][milieuJ]=pointDeSeg(plan[minI][minJ],plan[minI][maxJ]);
		plan[minI][milieuJ].z=hauteur(plan[minI][minJ],plan[minI][maxJ]);
	}
	
	plan[milieuI][maxJ]=pointDeSeg(plan[minI][maxJ],plan[maxI][maxJ]);
	plan[maxI][milieuJ]=pointDeSeg(plan[maxI][minJ],plan[maxI][maxJ]);
	
	plan[milieuI][milieuJ]=pointDeQuad(plan[minI][minJ],plan[maxI][minJ],plan[minI][maxJ]);
					  
	
	plan[milieuI][maxJ].z=hauteur(plan[minI][maxJ],plan[maxI][maxJ]);
	plan[maxI][milieuJ].z=hauteur(plan[maxI][minJ],plan[maxI][maxJ]);
	
	plan[milieuI][milieuJ].z=hauteurCentre(plan[minI][minJ],plan[maxI][minJ],plan[maxI][maxJ],plan[minI][maxJ]);
	
	// appels récursifs		
	if((maxI-minI)>2)	
	{			
		decoupe(plan,minI,milieuI,minJ,milieuJ);//partie haut gauche
		decoupe(plan,milieuI,maxI,minJ,milieuJ);//partie haut droite
		decoupe(plan,minI,milieuI,milieuJ,maxJ);//partie bas gauche
		decoupe(plan,milieuI,maxI,milieuJ,maxJ);//partie bas droite
	}
}

Point3d pointDeSeg(Point3d A,Point3d B)
{
	Point3d nouveau=A;
	GLfloat k=((GLfloat)((rand() % (conf.maxS - conf.minS + 1)) + conf.minS))/100.0;
	//k appartient à [MIN/100, MAX/100]<[0,1]

	nouveau.x+=k*(B.x-A.x);
	nouveau.y+=k*(B.y-A.y);// point A translaté de AB pondéré par k

	return nouveau;
}

Point3d pointDeQuad(Point3d A,Point3d B,Point3d D)
{
	Point3d nouveau;
	GLfloat k=((GLfloat)((rand() % (conf.maxG - conf.minG + 1)) + conf.minG))/100.0;
	GLfloat l=((GLfloat)((rand() % (conf.maxG - conf.minG + 1)) + conf.minG))/100.0;

	nouveau=A;
	
	nouveau.x+=k*(D.x-A.x)+l*(B.x-A.x);
	nouveau.y+=k*(D.y-A.y)+l*(B.y-A.y);
		
	return nouveau;
}

GLfloat hauteur(Point3d a, Point3d b)
{
	GLfloat deltaH,longeur,k;
	
	deltaH=abs(a.z-b.z);
	longeur=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));	
	
	k=((GLfloat)((rand() % 2001) -1000))/1000;//[-1,1]

	return borne(((a.z+b.z)/2+k*(deltaH/longeur)));//dépend de la pente
}

GLfloat hauteurCentre(Point3d a, Point3d b, Point3d c, Point3d d)
{
	GLfloat s,k;
	
	s=surface(a,b,c,d);

	k=((GLfloat)((rand() % 2001) -1000))/1000;//[-1,1]
	
	return borne((a.z+b.z+c.z+d.z)/4+k/4*sqrt(s));;
}

GLfloat surface(Point3d a, Point3d b, Point3d c, Point3d d)
{
	return aireTriangle(a,b,c)+aireTriangle(a,c,d);
}

GLfloat aireTriangle(Point3d a, Point3d b, Point3d c)
{
	return 0.5*abs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}

GLfloat borne(GLfloat a)
{
	if(a<0)
		a=0;
	else if(a>conf.hauteurMax)
		a=conf.hauteurMax;

	return a;
}


