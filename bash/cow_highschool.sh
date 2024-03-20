#/bin/bash

clear
for i in $(seq 1 $1)
do
    echo " ----"
    echo "< $(expr $i \* $i) >"     # On change simplement la valeur par elle même au carré
    echo " ----"
    echo "     \  ^__^"
    echo "      \ (oo)\_______"
    echo "        (__)\       )\/\\"
    echo "            ||----w |"
    echo "            ||     ||"
    sleep 1
    clear 
done

echo " ----"
echo "< $(expr $1 \* $1) >"
echo " ----"
echo "     \  ^__^"
echo "      \ (oo)\_______"
echo "        (__)\       )\/\\"
echo "         U  ||----w |"
echo "            ||     ||"