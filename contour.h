#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "robot.h"
#include "image.h"
#include "geom2d.h"
#include "sequence_point.h"


void save_position(Point p);

/*Parcourt l’image I jusqu’à trouver le pixel initial 
    qui est définit comme étant le premier pixel noir avec un pixel blanc à son Nord. 
*/
Point find_initial_pixel(Image I);

/*Checher contour dans l'image I*/
void find_contour(Image I,Image *M,int *countToWhites,int *countSegments,Point initial_pixel,List_Multiple_Contours* multi_contours);

/* créer l’image M en appelant la fonction image_mask(I), 
    On définit ensuite deux Pixel_Point p1 et p2.
    On parcourt l’image afin d'avoir la couleur du pixel courant et celle de son pixel voisin N. Si celui-ci est BLANC et que la couleur de p1 soit NOIR on marque le pixel à l’indice (x,y) de l’image M comme NOIR et on incremente le count passé en paramètre.
    L’image masque M est retourné.
*/
Image create_image_mask(Image I,int *countBlacks);

/*Checher plusieurs contour dans l'image I*/
List_Multiple_Contours find_multiple_contour(Image I,FILE *file,FILE *file_eps,bool file_main);

/*Ecrire chaque contour dans un fichier {nom_de_image}.contour et on convertit celui-là en un fichier {nom_de_image}.eps.*/
void write_in_files(Image I,List_Multiple_Contours multi_contours, FILE* file, FILE* file_eps);

/*Simplifie un tableau de points (cont) avec le methode de simplificationde Douglas Peucker*/
List_Segments simplification_douglas_peucker(Tableau_Point cont,int j1,int j2,double distance);

/*Ecrire la liste de segments (L) dans une fichier*/
void write_List_Segments_to_eps(FILE*file_eps,List_Segments L);

/*Utilise la fonction simplification_douglas_peucker afin de simplifier la liste de contours. 
Puis on écrit cette liste de segments simplifiés avec la fonction, write_List_Segments_to_eps dans un fichier eps*/
void write_all_simple_segments_eps(Image I,List_Multiple_Contours contours,FILE *file_simple_eps_1,double d);
