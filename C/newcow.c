#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void afficher_vache(char* eyes, int rainbow){
    char *rouge = "\033[0m";
    char *vert = "\033[0m";
    char *jaune = "\033[0m";
    char *cyan = "\033[0m";
    char *violet = "\033[0m";

    if (rainbow) {
        rouge = "\033[31m";
        vert = "\033[32m";
        jaune = "\033[33m";
        cyan = "\033[36m";
        violet = "\033[35m";
    }

    printf("%s     \\  ^__^\n", rouge);
    printf("%s      \\ (%c%c)\\_______\n", vert, eyes[0], eyes[1]);
    printf("%s        (__)\\       )\\/\\\n", jaune);
    printf("%s            ||----w |\n", cyan);
    printf("%s            ||     ||%s\n", violet, "\033[0m");
}

int main(int argc, char* argv[]){

    char eyes[15]="oo";
    int rainbow=0;
    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0)
            strcpy(eyes, argv[i+1]);
        else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--rainbow") == 0)
            rainbow=1;
    }
    afficher_vache(eyes, rainbow);
}
