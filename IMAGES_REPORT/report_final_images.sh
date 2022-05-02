#!/bin/bash

declare -a images=(lettre-L-cursive.pbm  deux-des-pleins.pbm Mister_Bean.pbm JoaquimHock-LesArbres.pbm Manara.pbm)
for image in ${images[@]}; do
    echo "/////////////////////////////////////////"
    echo $image
    ./../test_multi_contour $image
    gv $image.ps
    ./../test_simplification $image 10
    gv $image"_simple1.ps"
    ./../test_bezier $image 10
    gv $image"_curve.ps"
    ./../test_bezier_3 $image 10
    gv $image"_curve3.ps"
    echo "/////////////////////////////////////////"  
done






