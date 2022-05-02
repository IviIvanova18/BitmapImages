#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "image.h"
#include "geom2d.h"


typedef struct Pixel_Point_
{
    Pixel color;
    Point p;

}Pixel_Point;

typedef enum { North, East, South, West } Orientation;

typedef struct {
  Point p;
  Orientation o;
}Robot;

/* initialiser le robot r en position (x,y) et orientation o */
void initialize_Robot(Robot *r, Point p,Orientation o);

/* faire avancer le robot d'une case */
void move(Robot *r);

/* faire tourner le robot à gauche */
void turn_left(Robot *r);

/* faire tourner le robot à droite */
void turn_right(Robot *r);

/* recupere la position de la case du robot */
void position(Robot *r, Point *p);

/* recupere la position en abscisse de la case du robot */
int abscisse(Robot *r);

/* recupere la position en ordonnee de la case du robot */
int ordonnee(Robot *r);

/* recupere l'orientation du robot */
Orientation orient(Robot *r);

/*On appelle la fonction value_of_pixel afin d’obtenir les valeurs des pixels p_r et p_l. 
*Si le pixel gauche est noir, le robot tourne à gauche (turn_left(r)) 
*sinon si le pixel droite est blanc le robot tourne à droit(turn_right(r)). 
*La nouvelle orientation du robot est retournée.
*/
Orientation new_orientation(Point p,Image I,Robot *r);

/* recupere la position de la case devant le robot */
void position_devant(Robot *r, int *x, int *y);

/*Retourner la valeur du pixel de la case qui se trouve à gauche (p_l) et à droite(p_r) 
*de la case courante du robot par rapport à la orentation de robot
*/
void value_of_pixel(Image I,Robot *r,Pixel*p_r,Pixel*p_l,Point p);

void value_of_pixel_right(Image I,Robot *r,Pixel*p_r,Point p);

#endif
