#/bin/bash

fibo_0=0
fibo_1=1
fibo_n=0

clear
while [ $fibo_n -lt $1 ]
do
    echo " ----"
    echo "< $fibo_n >"
    echo " ----"
    echo "     \  ^__^"
    echo "      \ (oo)\_______"
    echo "        (__)\       )\/\\"
    echo "            ||----w |"
    echo "            ||     ||"
    sleep 1
    clear
    fibo_0=$fibo_1
    fibo_1=$fibo_n
    fibo_n=$(expr $fibo_0 + $fibo_1)

done

echo " ----"
echo "< $fibo_1 >"  # On affiche fibo_1 qui est la dernière valeur de fibo_n a être en dessous du chiffre passé en argument
echo " ----"
echo "     \  ^__^"
echo "      \ (oo)\_______"
echo "        (__)\       )\/\\"
echo "         U  ||----w |"
echo "            ||     ||"