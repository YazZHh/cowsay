# Compte rendu projet Cowsay
### de Valicourt - Nonis

## Partie Bash

#### 1-2)
Les deux premier scripts, cow_kindergarten.sh et cow_primaryschool.sh, il s'agit juste de faire une boucle simple et d'afficher une dernière fois la vache avec la langue qui pend.

#### 3)
cow_highschool.sh est globalement toujours aussi simple que les deux premiers, on va juste cette fois-ci afficher les nombres 1,2,4... jusqu'à n² avec n donné en argument, comme demandé.

*un exemple d'affichage final avec la commande `./cow_highschool 7`* :
```
 ----
< 49 >
 ----
     \  ^__^
      \ (oo)\_______
        (__)\       )\/\
         U  ||----w |
            ||     ||
```

#### 4)
Pour cow_college.sh, on reste encore une fois sur une boucle dont on va à la fin calculer le chiffre suivant de la suite de fibonacci.
La boucle s'arrête dès que le nombre dépasse le chiffre donné en argument, et affiche encore la vache avec la langue qui pend, avec le dernier chiffre de la suite inférieur au chiffre donné.

#### 5)
Dans cow_university.sh, on va faire une boucle qui parcours les entiers de 1 à n-1 avec n donné en argument du script, et pour chacun de ces entiers on va supposer qu'ils sont premiers, puis on va entrer dans une seconde boucle qui va tester si le reste de la division entière de l'entier avec tous les nombres de 0 à (cet entier - 1).
Si une seule des divisions donne en reste 0, alors cet entier ne sera pas affiché, si toutefois aucun des nombres ne le divise, alors on l'affiche, et on le stocke dans une variable pour plus tard l'afficher si c'était le dernier nombre premier de 0 à n-1.

*voici un **extrait** du script cow_university.sh* :
```bash
while [ $nb -lt $1 ]
do
    prem=1                              # On suppose que le nombre est premier
    for i in $(seq 2 $(expr $nb - 1))   # Et on va ensuite tester de le diviser avec tous les nombres de 2 à lui-même -1
    do
        if [ $(expr $nb \% $i) -eq 0 ]  # Si il est divisible par au moins un des nombres alors il n'est pas premier
        then
            prem=0
        fi
    done

    if [ $prem -eq 1 ]                  # On l'affiche si il est premier
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
```

#### 6)
Pour smart_cow.sh, on a réalisé une boucle qui va parcourir la chaîne de caractère donnée en argument : on récupère le caractère avec `char=${1:$i:1}` avec `i` l'index du caractère dans la chaîne. On suppose ensuite que le caractère n'est pas un nombre (donc un opérateur), puis on teste son égalité avec les caractères des chiffres (de "0" à "9"), s'il match avec l'un des chiffres alors on prends (le chiffre précédemment trouvé)*10 + le chiffre trouvé, on forme alors ainsi de suite le nombre donné.

```bash
nb_temp=0

for i in $(seq 0 $(expr ${#1} - 1))
do
    char=${1:$i:1}

    est_nb=false            # On suppose que le caractère n'est pas un nombre
    for j in $(seq 0 9)     
    do
        if [ "$char" = "$j" ]   # Si il match avec un caractère de 0 à 9,
        then
            nb_temp=$(expr $nb_temp \* 10 + $j)     # On "l'ajoute" au début du nombre calculé
            est_nb=true
        fi
    done
...(suite)
```

Maintenant si le caractère n'est pas un chiffre alors c'est forcément un opérateur, on va alors stocker l'opérateur dans une variable, et le nombre précédemment trouvé dans une autre variable, et mettre à zéro la variable qui stock le chiffre dans la première boucle.

```bash
...
if [ "$est_nb" = false ]    # C'est nécéssairement c'est un opérateur
    then
        mode=$char      # On définit le mode comme l'opération mathématique
        nb1=$nb_temp    # Et on stock le premier nombre trouvé dans une variable
        nb_temp=0
    fi
done
```

La boucle principale va continuer et stocker dans `nb_temp` le second nombre jusqu'à finir la chaîne de caractère entrée en paramètres.
Il ne reste donc plus qu'à faire notre calcul, et afficher le tout, mais avant ça il faut faire attention à la multiplication, représentée par `*`, car c'est un métacaractère donc il faut ajouter un antislash avant pour faire le calcul avec `expr`. Il faut aussi faire attention au cas où l'utilisateur rentre un calcul avec une division par 0, si tel est le cas on affiche un message d'erreur sans afficher la vache avec le calcul effectué

```bash
if [ "$mode" = "*" ]    # On doit gérer le cas de la multiplication différemment car * est un métacaractère
then
    res=$(expr $nb1 \* $nb_temp)
elif [ "$mode" = "/" -a $nb_temp = "0" ]    # On fait attention au cas de la division par 0 !
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
```
*exemples d'exécution* :
```bash
suka@suka:~/code/cowsay/bash$ ./smart_cow.sh "6+13"
 __________
< 6 + 13 = >
 ----------
     \  ^__^
      \ (19)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
suka@suka:~/code/cowsay/bash$ ./smart_cow.sh "16*48"
 ___________
< 16 * 48 = >
 -----------
     \  ^__^
      \ (768)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
suka@suka:~/code/cowsay/bash$ ./smart_cow.sh "376-135"
 _____________
< 376 - 135 = >
 -------------
     \  ^__^
      \ (241)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
suka@suka:~/code/cowsay/bash$ ./smart_cow.sh "57/11"
 ___________
< 57 / 11 = >
 -----------
     \  ^__^
      \ (05)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
suka@suka:~/code/cowsay/bash$ ./smart_cow.sh "35/0"
Erreur de division par 0 !
```

#### 7)

Pour le dernier script bash crazy_cow.sh, on a décidé de partir sur un chiffrement de césar, en utilisant donc la table ascii. C'était compliqué mais on est parvenu à le faire fonctionner. Il faut simplement impérativement backslash les guillemets et les dollars sinon il risque d'y avoir des problèmes.

On vérifie premièrement que l'utilisateur exécute le script avec deux arguments : un entier pour le décalage, et la chaîne de caractère qu'il veut chiffrer. Puis pour chaque caractère de la chaîne, on va simplement le convertir en sa valeur dans la table ascii avec `ascii_val=$(printf "%d" "'$char")`. On additionne cette valeur avec le décalage donné avec `val=$(expr $ascii_val + $decalage)`, puis on fais attention à ce qu'il soit dans l'intervalle des caractère imprimables de la table ascii (espace compris).

```bash
if [ $val -gt 126 ]                         # 126 étant la borne supérieure
    then
        val=$(expr 31 + $(expr $val - 126))
    elif [ $val -lt 32 ]                    # et 32 la borne inférieure
    then
        val=$(expr 127 - $(expr 32 - $val))
    fi
```

Ensuite on ajoute le caractère chiffré à la chaîne de caractère du message chiffré :

```bash
encrypted_val=$(printf \\$(printf '%03o' $val))
encrypted_msg=$(echo "$encrypted_msg$encrypted_val")    # sorte de concaténation
```

Il ne reste plus qu'a faire la même opération sur toute la chaîne de caractère passée en paramètre et on obtient la chaîne chiffrée avec le décalage souhaité.

Pour bien finir le tout, lorsqu'on exécute le script avec des arguments, la vache va d'abord penser au texte brut, puis au bout de 2 secondes va dire le texte chiffré avec le décalade dans ses yeux *(voir le script pour plus de détails)*

```
suka@suka:~/code/cowsay/bash$ ./crazy_cow.sh 6 "Bonjour tout le monde !"
 _________________________
( Bonjour tout le monde ! )
 -------------------------
    o   ^__^
     o  (--)\_______
        (__)\       )\/\
            ||----w |
            ||     ||

*clear*
 _________________________
< Hutpu{x&zu{z&rk&sutjk&' >
 -------------------------
    \   ^__^
     \  (06)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
```

À savoir que l'opération inverse est totalement possible : 

```
suka@suka:~/code/cowsay/bash$ ./crazy_cow.sh -6 "Hutpu{x&zu{z&rk&sutjk&'"
  _________________________
( Hutpu{x&zu{z&rk&sutjk&' )
 -------------------------
    o   ^__^
     o  (--)\_______
        (__)\       )\/\
            ||----w |
            ||     ||

*clear*
 _________________________
< Bonjour tout le monde ! >
 -------------------------
    \   ^__^
     \  (-6)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
```