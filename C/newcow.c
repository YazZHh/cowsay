#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void afficher_vache(char* eyes){
    printf("     \\  ^__^\n");
    printf("      \\ (%c%c)\\_______\n", eyes[0], eyes[1]);
    printf("        (__)\\       )\\/\\\n");
    printf("            ||----w |\n");
    printf("            ||     ||\n");
}

int main(int argc, char* argv[]){
    char eyes[15] = "oo";
    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0)
            strcpy(eyes, argv[i+1]);
    }
    afficher_vache(eyes);
}
