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
    // for (int i=1; i<argc; i++){
    //     if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0)
    //         strcpy(eyes, argv[i+1]);
    //     else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--rainbow") == 0)
    //         rainbow=1;
    // }

    update();
    char eyes[15]="^^";
    int abscisse_vache=38;
    int abscisse_poteau=30;
    int sol=8;
    int hauteur_vache=sol;
    int mode=0;

    // afficher_vache(mode, abscisse_vache, sol, "^^");
    // afficher_poteau(30, sol);
    while (abscisse_vache>-1){
        afficher_vache(mode, abscisse_vache, hauteur_vache, eyes);
        afficher_poteau(abscisse_poteau, sol);

        if (mode == 1)
            mode=0;
        else
            mode=1;
        abscisse_vache--;

        if (abscisse_vache - abscisse_poteau > -3 && abscisse_vache - abscisse_poteau < 5){     // La montée du saut
            mode=0;
            hauteur_vache--;
            strcpy(eyes, "\\/");
        }
        else if (abscisse_vache - abscisse_poteau < -11 && abscisse_vache - abscisse_poteau > -19){     // La redescente
            mode=0;
            hauteur_vache++;
            strcpy(eyes, "\\/");
        }
        else
            strcpy(eyes, "^^");
        
        if (abscisse_vache - abscisse_poteau >= -11 && abscisse_vache - abscisse_poteau <= -3){
            mode=0;
            strcpy(eyes, "00");
        }

        // if 



        usleep(100000); // On attend 100ms
        update();

    }

}
