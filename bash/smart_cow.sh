#!/bin/bash

nb_temp=0

for i in $(seq 0 $(expr ${#1} - 1))
do
    char=${1:$i:1}

    est_nb=false                # On suppose de base que le caractère n'est pas un nombre
    for j in $(seq 0 9)     
    do
        if [ "$char" = "$j" ]                       # S'il match avec un caractère de 0 à 9,
        then
            nb_temp=$(expr $nb_temp \* 10 + $j)     # On "l'ajoute" au début du nombre calculé
            est_nb=true
        fi
    done
    
    if [ "$est_nb" = false ]    # Si le caractère n'est pas un chiffre alors nécessairement c'est un opérateur
    then
        mode=$char              # On définit le mode comme l'opération mathématique
        nb1=$nb_temp            # Et on stocke le premier nombre trouvé dans une variable
        nb_temp=0
    fi
done
# La boucle va jusqu'à la fin donc va parcourir le second nombre et le stocker dans nb_temp


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
    res=$(echo 0$res)   # Une variante serait de mettre un espace au lieu du 0 mais nous trouvons que ça rend mieux avec un 0 plutôt qu'avec un espace
fi

# $calcul=$(echo $nb1 $mode $nb_temp)
calcul=$(echo "$nb1 $mode $nb_temp =")

# Pour finir on affiche la boîte de dialogue comme pour crazy_cow.sh
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