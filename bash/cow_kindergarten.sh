#/bin/bash

clear
for i in $(seq 1 10)    # Simple boucle qui va boucler de 1 à 10 inclus et affichera la vache avec le nombre
do
    echo " ----"
    echo "< $i >"
    echo " ----"
    echo "     \  ^__^"
    echo "      \ (oo)\_______"
    echo "        (__)\       )\/\\"    # On oublie pas de mettre un \ avant le dernier \ sinon cela désactive le guillemet
    echo "            ||----w |"
    echo "            ||     ||"
    sleep 1
    clear 
done

# On affiche une dernière fois la vache, qui cette fois-ci tire la langue
echo " ----"
echo "< 10 >"
echo " ----"
echo "     \  ^__^"
echo "      \ (oo)\_______"
echo "        (__)\       )\/\\"
echo "         U  ||----w |"
echo "            ||     ||"