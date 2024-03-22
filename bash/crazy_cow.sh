#!/bin/bash
# Script qui encode avec code de césar en utilisant toute la table ascii des caractères imprimables et l'espace (donc les symboles et les chiffres aussi).
# IL FAUT ABSOLUMENT BACKSLASH LES " ET $ (Très important)

if [ $# -ne 2 ]
then
    echo "Erreur: mauvais nombre d'arguments"
    echo "Usage: $0 <décalage> <texte>"
    exit 1
fi 

encrypted_msg=""

for i in $(seq 0 $(expr ${#2} - 1))
do
    char=${2:$i:1}                      # On récupère la lettre d'indice i 
    ascii_val=$(printf "%d" "'$char")   # On la converti en sa valeur dans la table ascii

    val=$(expr $ascii_val + $1)         # Ensuite on la décalle de la valeur de la clé fournie

    if [ $val -gt 126 ]                 # Petites corrections pour que l'on reste bien dans l'intervalle des caractères imprimables
    then
        val=$(expr $val \% 127 + 32)
    elif [ $val -lt 32 ]
    then
        val=$(expr 127 - $(expr 32 - $val))
    fi

    encrypted_val=$(printf \\$(printf '%03o' $val))
    encrypted_msg=$(echo "$encrypted_msg$encrypted_val")    # On ajoute le caractère converti à la chaine de caractère finale

done

echo "$encrypted_msg"   # Plus qu'à afficher le message chiffré