#!/bin/bash
# Script qui encode avec code de césar en utilisant toute la table ascii des caractères imprimables et l'espace (donc les symboles et les chiffres aussi).
# IL FAUT ABSOLUMENT BACKSLASH LES " ET $ (Très important)

if [ $# -ne 2 ]
then
    echo "Erreur: mauvais nombre d'arguments"
    echo "Usage: $0 <décalage> <texte>"
    exit 1
fi 

decalage=$(expr $1 \% 96)   # On prend un décalage entre -95 et 95 seulement (après c'est périodique)
encrypted_msg=""

for i in $(seq 0 $(expr ${#2} - 1))
do
    char=${2:$i:1}                      # On récupère la lettre d'indice i 
    ascii_val=$(printf "%d" "'$char")   # On la converti en sa valeur dans la table ascii

    val=$(expr $ascii_val + $decalage)         # Ensuite on la décalle de la valeur de la clé fournie

    if [ $val -gt 126 ]                 # Petites corrections pour que l'on reste bien dans l'intervalle des caractères imprimables
    then
        val=$(expr 31 + $(expr $val - 126))
    elif [ $val -lt 32 ]
    then
        val=$(expr 127 - $(expr 32 - $val))
    fi

    encrypted_val=$(printf \\$(printf '%03o' $val))
    encrypted_msg=$(echo "$encrypted_msg$encrypted_val")    # On ajoute le caractère converti à la chaine de caractère finale

done

clear

# On affiche le haut de la boîte de dialogue
printf " "
for i in $(seq 1 $(expr ${#2} + 2))
do
    printf "_"
done
echo

# Puis on affiche le message chiffré
echo "< $2 >"

# Ensuite on affiche le bas de la boite de dialogue
printf " "
for i in $(seq 1 $(expr ${#2} + 2))
do
    printf "-"
done
echo

echo "    o   ^__^"
echo "     o  (--)\_______"
echo "        (__)\       )\/\\"
echo "            ||----w |"
echo "            ||     ||"

sleep 3
clear

# On affiche le haut de la boîte de dialogue
printf " "
for i in $(seq 1 $(expr ${#2} + 2))
do
    printf "_"
done
echo

# Puis on affiche le message chiffré
echo "< $encrypted_msg >"

# Ensuite on affiche le bas de la boite de dialogue
printf " "
for i in $(seq 1 $(expr ${#2} + 2))
do
    printf "-"
done
echo

echo "    \   ^__^"
echo "     \  ($1)\_______"
echo "        (__)\       )\/\\"
echo "            ||----w |"
echo "            ||     ||"