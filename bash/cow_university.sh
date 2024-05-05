#/bin/bash

nb=1
der_nb=0

clear
while [ $nb -lt $1 ]
do
    prem=1                                  # On suppose que le nombre est premier
    for i in $(seq 2 $(expr $nb - 1))       # Et on va ensuite tester de le diviser avec tous les nombres de 2 à lui-même -1
    do
        if [ $(expr $nb \% $i) -eq 0 ]      # Si il est divisible par au moins un des nombres alors il n'est pas premier
        then
            prem=0
        fi
    done

    if [ $prem -eq 1 ]                      # On l'affiche si il est premier
    then
        echo " ----"
        echo "< $nb >"
        echo " ----"
        echo "     \  ^__^"
        echo "      \ (oo)\_______"
        echo "        (__)\       )\/\\"
        echo "            ||----w |"
        echo "            ||     ||"
        sleep 1
        clear
        der_nb=$nb
    fi

    nb=$(expr $nb + 1)
done

echo " ----"
echo "< $der_nb >"      # On affiche à la fin le dernier nombre premier trouvé inférieur à l'argument donné
echo " ----"
echo "     \  ^__^"
echo "      \ (oo)\_______"
echo "        (__)\       )\/\\"
echo "         U  ||----w |"
echo "            ||     ||"