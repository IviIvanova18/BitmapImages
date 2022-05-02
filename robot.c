#include "robot.h"

/* initialiser le robot r en position (x,y) et orientation o */
void initialize_Robot(Robot *r, Point p,Orientation o) {
  r->p.x = p.x;
  r->p.y = p.y;
  r->o = o;
  
}

/* faire avancer le robot d'une case */
void move(Robot *r) {
  switch (r->o) {
  case North:
    r->p.y = r->p.y - 1;
    break;
  case East:
    r->p.x = r->p.x + 1;
    break;
  case South:
    r->p.y = r->p.y + 1;
    break;
  case West:
    r->p.x = r->p.x - 1;
    break;
  }
}

/* faire tourner le robot à gauche */
void turn_left(Robot *r) {
  switch (r->o) {
  case North:
    r->o = West;
    break;
  case East:
    r->o = North;
    break;
  case South:
    r->o = East;
    break;
  case West:
    r->o = South;
    break;
  }
}

/* faire tourner le robot à droite */
void turn_right(Robot *r) {
  switch (r->o) {
  case North:
    r->o = East;
    break;
  case East:
    r->o = South;
    break;
  case South:
    r->o = West;
    break;
  case West:
    r->o = North;
    break;
  }
}

/* recupere la position de la case du robot */
void position(Robot *r, Point *p) {
  p->x = r->p.x;
  p->y = r->p.y;
}


/* recupere l'orientation du robot */
Orientation orient(Robot *r) { return r->o; }

/*Retourner la valeur du pixel de la case qui se trouve à gauche (p_l) et à droite(p_r) 
*de la case courante du robot par rapport à la orentation de robot
*/
void value_of_pixel(Image I,Robot *r,Pixel*p_r,Pixel*p_l,Point p){
  int x = p.x;
  int y = p.y;
  //printf("initial pos is %f %f with orient %u\n", r->p.x, r->p.y,r->o);
  
  switch (r->o) {
  case 0:
    *p_r = get_pixel_image(I,x+1,y);
    *p_l = get_pixel_image(I,x,y);
    break;
  case 1:
    *p_r = get_pixel_image(I,x+1,y+1);
    *p_l = get_pixel_image(I,x+1,y);
    break;
  case 2:
    *p_r = get_pixel_image(I,x,y+1);
    *p_l = get_pixel_image(I,x+1,y+1);
    break;
  case 3:
    *p_r = get_pixel_image(I,x,y);
    *p_l = get_pixel_image(I,x,y+1);
    break;
  }

}

/*Retourne  la valeur de pixel au Nord de pixel p_r*/
void value_of_pixel_north(Image I,Robot *r,Pixel*p_r,Point p){
  int x = p.x;
  int y = p.y;
    
  switch (r->o) {
  case 0:
    *p_r = get_pixel_image(I,x+1,y);
    break;
  case 1:
    *p_r = get_pixel_image(I,x+1,y+1);
    break;
  case 2:
    *p_r = get_pixel_image(I,x,y+1);
    break;
  case 3:
    *p_r = get_pixel_image(I,x,y);
    break;
  }

}

Orientation new_orientation(Point p,Image I,Robot *r){
  Pixel p_r;
  Pixel p_l; 
  value_of_pixel(I,r,&p_r,&p_l,p);
  if(p_l == NOIR){
    turn_left(r);
  }else if(p_r == BLANC){
    turn_right(r);
  }
  return(r->o);

}
