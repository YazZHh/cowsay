#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void update(){
    printf("\033[H\033[J");
}

void dessiner_vache(char car){
    printf("     \\  ^__^\n");
    printf("      \\ (oo)\\_______\n");
    printf("        (__)\\       )\\/\\\n");
    printf("         %c  ||----w |\n", car);
    printf("            ||     ||\n");
}

void dessiner_bulle(char* message){
    int longueur = strlen(message);

    printf(" ");                        // On dessine d'abord le haut de la bulle de texte,
    for (int i=0; i<longueur+2; i++)
        printf("_");
    printf("\n");
    
    printf("< %s >\n", message);       // puis les côtés,

    printf(" ");
    for (int i=0; i<longueur+2; i++)    // et ensuite le bas.
        printf("-");
    printf(" \n");
}

int main(int argc, char* argv[]){
    FILE* f;
    if (argc == 2){
        f=fopen(argv[1], "r");
        if (f==NULL){
            printf("Erreur lors de l'ouverture du fichier !\n");
            return 1;
        }
    } else {
        f=stdin;
    }
    
    char* msg=malloc(256*sizeof(char));
    char car;
    int i=0;
    msg[i]='\0';

    while (!feof(f)){
        fscanf(f, "%c", &car);

        if (car == '\n')        // Gestion du cas où le caractère est un retour à la ligne
            car=' ';            // On le remplace par un espace pour éviter les bugs d'affichage

        update();
        dessiner_bulle(msg); dessiner_vache(car);
        sleep(1);

        msg[i]=car;
        msg[i+1]='\0';
        i++;
    }
    fclose(f);
    return 0;
}