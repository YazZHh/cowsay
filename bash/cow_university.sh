#/bin/bash

nb=1
der_nb=0

clear
while [ $nb -lt $1 ]
do
    prem=1
    for i in $(seq 2 $(expr $nb - 1))       # On va bien vérifier que tout les nombres de 2 au nombre testé (sauf lui) ne divisent pas celui-ci
    do
        if [ $(expr $nb \% $i) -eq 0 ]
        then
            prem=0
        fi
    done

    if [ $prem -eq 1 ]                      # Et si c'est le cas, on l'affiche
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