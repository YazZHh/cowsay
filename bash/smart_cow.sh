#!/bin/bash

nb_temp=0

for i in $(seq 0 $(expr ${#1} - 1))
do
    char=${1:$i:1}
    est_nb=false
    
    for j in $(seq 0 9)     # On teste si l'opérateur est un nombre et on trouve sa valeur en int (et non str)
    do
        if [ "$char" = "$j" ]
        then
            nb_temp=$(expr $nb_temp \* 10 + $j)
            est_nb=true
        fi
    done
    
    if [ "$est_nb" = false ]  # Si le caractère n'est pas un chiffre alors nécéssairement c'est un opérateur
    then
        mode=$char
        nb1=$nb_temp
        nb_temp=0
    fi
done

if [ "$mode" = "*" ]
then
    echo $(expr $nb1 \* $nb_temp)
elif [ "$mode" = "/" -a $nb_temp = "0" ]
then
    echo Erreur de division par 0 !
else
    echo $(expr $nb1 $mode $nb_temp)
fi

# il reste à faire un affichage propre avec la vache