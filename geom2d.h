#ifndef _GEOM2D_H_
#define _GEOM2D_H_

typedef struct Vector_{
    double x,y;
}Vector;

typedef struct Point_
{
    double x,y;
}Point;

typedef struct Segment_
{
    Point P1;
    Point P2;
}Segment;

/*Types courbe bezier degrée 2 et 3 utilisés dans TACHE7*/
typedef struct CourbeBezier_2_
{
    Point C0;
    Point C1;
    Point C2;
    
}CourbeBezier_2;

typedef struct CourbeBezier_3_
{
    Point C0;
    Point C1;
    Point C2;
    Point C3;
    
}CourbeBezier_3;

/*Créer un point P avec 2 paramètres de type double. 
*retourne le point P
*/
Point set_point(double x, double y);


/* Additionne les 2 points P1 et P2 en additionnant les p.x’s et p.y’s ou p est un point quelconque.
*Utilise set_point afin d’établir le point de retour et de point est retourné.
*/
Point add_points(Point P1, Point P2);

/*Soustraction de deux points P1 et P2*/
Point substract_point(Point P1, Point P2);

/* Trouve le point P qui est le  bipoint des deux points passés en paramètre.
*Retourne le point P.
*/
Vector vect_bipoint(Point A,Point B);

/*Définit un Point P dont les valeurs de x et y sont A.x*a et A.y*a respectivement.
Retourne le point P
*/
Point int_product(Point A, double a);

/*Définit un Point P dont les valeurs de x et y sont A.x/a et A.y/a respectivement.
*Retourne le point P
*/
Point int_division(Point A, double a);

/*Retourne le produit scalaire de deux vecteurs*/
double scalar_product(Vector A, Vector B);

double euclidean_norm(Vector A);

/*Retourne la distance entre les deux points A et B.*/
double distance_points(Point A, Point B);

void find_line(Point A, Point B);

void printPoint(Point P);

void printVector(Vector V);

double distance_point_to_line(Point P, Segment S);



#endif
