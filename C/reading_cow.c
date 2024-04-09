#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void dessiner_vache(){
    printf("     \\  ^__^\n");
    printf("      \\ (oo)\\_______\n");
    printf("        (__)\\       )\\/\\\n");
    printf("            ||----w |\n");
    printf("            ||     ||\n");
}

void dessiner_bulle(char* message){
    int longueur = strlen(message);
    printf(" ");
    for (int i=0; i<longueur+2; i++)
        printf("_");
    printf("\n");
    printf("< %s >\n ", message);
    for (int i=0; i<longueur+2; i++)
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
    char msg[]="";
    fscanf(f, "%s", msg);
    dessiner_bulle(msg);
    dessiner_vache();
}