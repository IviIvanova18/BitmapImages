# MAP401-Projet logiciel
## Vectorisation et simpification d'image bitmap
## Installation
make clean 
make 

## Usage
### TACHE 5

Données en entrée : ./test_multi_contour nom_de_fichier(format PBM)

Résultats en sortie : deux fichiers :
1. nom_de_fichier_en_entre.contour : 
première ligne nombre de contours
nombre de segments de chaque contour suivi de points du contour courant

2. nom_de_fichier_en_entre.ps
Suite de contours au format EPS.

### TACHE 6

Données en entrée : ./test_simplification {nom_de_fichier(format PBM)} {distance-seuil}

Résultats en sortie :  nom_de_fichier_en_entre_simple1.ps 
Séquence de contours simplifiés suivant la distance seuil d transformé en format EPS 

Sortie standard : 
Le nombre total de segments des contours de la simplification avec d = {distance-seuil}: {Nombre de segments}

### TACHE 7-1

Données en entrée : ./test_bezier {nom_de_fichier(format PBM)} {distance-seuil}

Résultats en sortie :  nom_de_fichier_en_entre_curve.ps 
Séquence de contours simplifiés par courbe de Bézier de degré 2  suivant la distance seuil d transformé en format EPS 

Sortie standard : 
Nombre de courbe de bézier est:{Nombre de Bézier Degré 2}

### TACHE 7-2

Données en entrée : ./test_bezier_3 {nom_de_fichier(format PBM)} {distance-seuil}

Résultats en sortie :  nom_de_fichier_en_entre_curve3.ps 
Séquence de contours simplifiés par courbe de Bézier de degré 3  suivant la distance seuil d transformé en format EPS 

## Remarks 
Des fichier tests sont dans deux dossier appelés : IMAGES_REPORT et TACHE8_IMAGES
