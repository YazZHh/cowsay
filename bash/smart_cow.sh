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
    
    if [ "$est_nb" = false ]    # Si le caractère n'est pas un chiffre alors nécéssairement c'est un opérateur
    then
        mode=$char
        nb1=$nb_temp
        nb_temp=0
    fi
done

if [ "$mode" = "*" ]        # On doit gérer le cas de la multiplication différemment car * est un métacaractère
then
    res=$(expr $nb1 \* $nb_temp)
elif [ "$mode" = "/" -a $nb_temp = "0" ]        # On fait attention au cas de la division par 0 !
then
    echo Erreur de division par 0 !
    exit 1
else
    res=$(expr $nb1 $mode $nb_temp)
fi

if [ ${#res} -eq 1 ]    # Juste un petit fix, si jamais le résultat est un seul chiffre, on ajoute un 0 devant pour ne pas décaler le dessin ascii de la vache
then
    res=$(echo 0$res)   # Une variante serait de mettre un espace au lieu du 0 mais je trouve que ca rend mieux avec un 0 plutôt qu'avec un espace
fi

$calcul=$(echo $nb1 $mode $nb_temp)

printf " "
for i in $(seq 1 $(expr ${#calcul} + 2))
do
    printf "_"
done
echo

echo "< $calcul >"

printf " "
for i in $(seq 1 $(expr ${#calcul} + 2))
do
    printf "-"
done
echo

echo "     \  ^__^"
echo "      \ ($res)\_______"
echo "        (__)\       )\/\\"
echo "            ||----w |"
echo "            ||     ||"