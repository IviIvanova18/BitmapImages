#include "robot.h"
#include "geom2d.h"
#include "contour.h"
#include <math.h>
#include <assert.h>

#ifndef _COURBE_BEZIER_H
#define _COURBE_BEZIER_H

///////////////////////////////////
// Courbes de Bézier de degré 2 ///
//////////////////////////////////
typedef struct CourbeBezier_2_Node_
{
	CourbeBezier_2 courbe;
	struct CourbeBezier_2_Node_ *next_courbe;
}CourbeBezier_2_Node;

typedef struct  List_CourbeBezier_2_
{
	unsigned int count;
	CourbeBezier_2_Node *head;
	CourbeBezier_2_Node *tail;
}List_CourbeBezier_2;

///////////////////////////////////
// Courbes de Bézier de degré 3 ///
//////////////////////////////////
typedef struct CourbeBezier_3_Node_
{
	CourbeBezier_3 courbe;
	struct CourbeBezier_3_Node_ *next_courbe;
}CourbeBezier_3_Node;

typedef struct  List_CourbeBezier_3_
{
	unsigned int count;
	CourbeBezier_3_Node *head;
	CourbeBezier_3_Node *tail;
}List_CourbeBezier_3;


/*Courbes de Bezier de degre 2*/
CourbeBezier_2_Node *create_element_Courbe_Bezier_2(CourbeBezier_2 c);
List_CourbeBezier_2 create_List_Courbe_Bezier_2_vide();
List_CourbeBezier_2 add_element_Courbe_Bezier_2(List_CourbeBezier_2* L, CourbeBezier_2 e);
List_CourbeBezier_2 concatener_List_Courbe_Bezier_2(List_CourbeBezier_2 L1, List_CourbeBezier_2 L2);

/*Courbes de Bezier de degre 3*/
CourbeBezier_3_Node *create_element_Courbe_Bezier_3(CourbeBezier_3 c);
List_CourbeBezier_3 create_List_Courbe_Bezier_3_vide();
List_CourbeBezier_3 add_element_Courbe_Bezier_3(List_CourbeBezier_3* L, CourbeBezier_3 e);
List_CourbeBezier_3 concatener_List_Courbe_Bezier_3(List_CourbeBezier_3 L1, List_CourbeBezier_3 L2);


/*Simplification de contour par Courbes de Bezier de degre 2*/
/* Calcule le point C0,C1 et C2 de la courbe de Bezier 3*/
CourbeBezier_2 approx_bezier2(Tableau_Point *cont, int j1,int j2);
/*Calcule la distance entre un point Pj et la courbe de Bézier2*/
double distance_point_Bezier(Point P,CourbeBezier_2 courbe,double ti);
List_CourbeBezier_2 simplification_douglas_peucker_bezier2(Tableau_Point cont,int j1,int j2,double d);
void write_curve_bezier_in_eps(FILE* fileOut,List_CourbeBezier_3 *L,Image I);
/* Convertit une courbe de bézier de degré 2 en 3*/
CourbeBezier_3 courbeBezierFrom2to3(CourbeBezier_2 bezier2);
/* Convertit tous les éléments de la liste de courbe de béziers 2 en des courbes de béziers 3 et retourne cette nouvelle liste.*/
List_CourbeBezier_3 degreeElevationfrom2To3(List_CourbeBezier_2 *list);
/* Calcule le point de contrôle C1 obtenue en simplifiant une séquence de points cont par une courbe de bézier de degré 2*/
Point calculate_C1_bezier(Tableau_Point*cont,int j1,int j2,int n);


/*Simplification de contour par Courbes de Bezier de degre 3*/
/* Calcule le point C0,C1,C2 et C3 de la courbe de Bezier 3
*/
CourbeBezier_3 approx_bezier3(Tableau_Point *cont, int j1,int j2);
/* Additioner tous les points entre indices 1 et n-1
Le parametre bool point indique si on calcule point C1 ou point C2
si point==true on calcule C1 sinon on clacule C2*/
Point sum_points(Tableau_Point *cont,int n,int j1,bool flag);
List_CourbeBezier_3 simplification_douglas_peucker_bezier3(Tableau_Point cont,int j1,int j2,double d);
/*Calcule un point c_t quelconque du courbe de bézier */
Point calculate_Ct_3(CourbeBezier_3 B, double t);
/*Calcule la distance entre un point Pj et la courbe de BézierB*/
double distance_point_bezier3(Point Pj, CourbeBezier_3 B, double ti);
/* Ecrire courbe de Bezier dans un fichier de format EPS*/
void write_all_courbe_bezier_eps(FILE* f,Image I, List_Multiple_Contours contours,int d);

#endif