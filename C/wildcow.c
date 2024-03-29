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

void afficher_vache(int type, int decalage, char* eyes){
    char dec[256];
    for (int i=0; i<decalage; i++)
        dec[i]='-';
    dec[decalage]='\0';
    
    printf("'%s'\n", dec);

    if (type == 1){
        printf("%s^__^\n", dec);
        printf("%s(%c%c)\\_______\n", dec, eyes[0], eyes[1]);
        printf("%s(__)\\       )\\/\\\n", dec);
        printf("%s    ||----w |\n", dec);
        printf("%s    ||     ||\n", dec);
    }
    else if (type == 0){
        printf("%s^__^\n", dec);
        printf("%s(%c%c)\\_______\n", dec, eyes[0], eyes[1]);
        printf("%s(__)\\       )\\/\\\n", dec);
        printf("%s    /\\----w \\\n", dec);
        printf("%s   /  \\   /  \\\n", dec);
    }
    
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
    int decalage=3;
    int mode=0;
    while (decalage>-1){
        afficher_vache(mode, decalage, eyes);

        if (mode == 1)
            mode=0;
        else
            mode=1;

        decalage--;
        usleep(100000); // On attend 100ms
        update();

    }

}
