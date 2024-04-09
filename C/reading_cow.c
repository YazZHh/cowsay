#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[]){
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
    char param[]= "";
    fscanf(f, "%s", param);
    printf("%s\n", param);
}