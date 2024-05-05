#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void update(){
    printf("\033[H\033[J");
}

void gotoyx(int y, int x){
    printf("\033[%d;%dH", y, x);
}

void afficher_vache(char* eyes, int rainbow, int nb_tail){
    char *rouge = "\033[0m";
    char *vert = "\033[0m";
    char *jaune = "\033[0m";
    char *cyan = "\033[0m";
    char *violet = "\033[0m";

    if (rainbow) {              // On applique les couleurs si l'option rainbow est donnée
        rouge = "\033[31m";
        vert = "\033[32m";
        jaune = "\033[33m";
        cyan = "\033[36m";
        violet = "\033[35m";
    }

    printf("%s     \\  ^__^\n", rouge);
    printf("%s      \\ (%c%c)\\_______\n", vert, eyes[0], eyes[1]);
    printf("%s        (__)\\       )\\/\\", jaune);
    for (int i=0; i<nb_tail; i++)                           // Application du paramètre tail
        printf("/\\");
    printf("\n");
    printf("%s            ||----w |\n", cyan);
    printf("%s            ||     ||%s\n", violet, "\033[0m");
}

int main(int argc, char* argv[]){
    char eyes[15]="oo";
    int rainbow=0;
    int nb_tail=0;

    for (int i=1; i<argc; i++){

        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0)           // Gestion du paramètre eyes
            strcpy(eyes, argv[i+1]);

        else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--rainbow") == 0)   // Gestion du paramètre rainbow
            rainbow=1;

        else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--tail") == 0){     // Gestion du paramètre tail
            char* str_nb_tail=argv[i+1];
            int i=0;
            while (str_nb_tail[i] != '\0'){                             // Conversion de la valeur donnée de char* en int
                nb_tail = nb_tail * 10 + (str_nb_tail[i] - '0');
                i++;
            }
        }
    }
    afficher_vache(eyes, rainbow, nb_tail);
    return 0;
}