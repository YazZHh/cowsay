#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void update(){
    printf("\033[H\033[J");
}

void gotoxy(int x, int y){
    printf("\033[%d;%dH", y, x);
}

void afficher_vache(int type, int x, int y, char* eyes){
    gotoxy(x, y);

    if (type == 1){
        printf("^__^");
        gotoxy(x, y+1);
        printf("(%c%c)\\_______", eyes[0], eyes[1]);
        gotoxy(x, y+2);
        printf("(__)\\       )\\/\\");
        gotoxy(x, y+3);
        printf("    ||----w |");
        gotoxy(x, y+4);
        printf("    ||     ||");
    }
    else if (type == 0){
        printf("^__^");
        gotoxy(x, y+1);
        printf("(%c%c)\\_______", eyes[0], eyes[1]);
        gotoxy(x, y+2);
        printf("(__)\\       )\\/\\");
        gotoxy(x, y+3);
        printf("    /\\----w \\");
        gotoxy(x, y+4);
        printf("   /  \\   /  \\");
    }
    
}

void afficher_poteau(int x, int y){
    int hauteur=y;
    gotoxy(x, hauteur);
    printf("__");
    hauteur++;
    while (hauteur<y+5){
        gotoxy(x, hauteur);
        printf("||");
        hauteur++;
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    update();
    char eyes[15]="oo";
    int rainbow=0;
    // for (int i=1; i<argc; i++){
    //     if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0)
    //         strcpy(eyes, argv[i+1]);
    //     else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--rainbow") == 0)
    //         rainbow=1;
    // }
    int decalage=50;
    int mode=0;
    // for (int i=0; i<16; i++){
    //     gotoxy(i*i, i);
    //     printf("O");
    // }
    // printf("\n");

    afficher_vache(1, 50, 6, "^^");
    afficher_poteau(30, 6);
    while (decalage>-1){
        afficher_vache(mode, decalage, 6, eyes);
        afficher_poteau(30, 6);
        if (mode == 1)
            mode=0;
        else
            mode=1;
        decalage--;
        usleep(100000); // On attend 100ms
        update();

    }

}
