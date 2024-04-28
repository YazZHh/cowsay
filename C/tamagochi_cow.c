// たまごち牛。ｃ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BYEBYELIFE 0
#define LIFESUCKS 1
#define LIFEROCKS 2

void update(){
    printf("\033[H\033[J");
}

void dessiner_vache(int etat){
    char yeux[2]="^^";
    char langue=' ';
    if (etat == LIFESUCKS){
        strcpy(yeux, "--");
        printf(" ___________\n");
        printf("< Lifesucks >\n");
        printf(" -----------\n");
    } else if (etat == BYEBYELIFE){
        strcpy(yeux, "xx"); langue='U';
        printf(" ____________\n");
        printf("< Byebyelife >\n");
        printf(" ------------\n");
    } else if (etat == LIFEROCKS){
        printf(" ___________\n");
        printf("< Liferocks >\n");
        printf(" -----------\n");
    }
    printf("     \\  ^__^\n");
    printf("      \\ (%s)\\_______\n", yeux);
    printf("        (__)\\       )\\/\\\n");
    printf("         %c  ||----w |\n", langue);
    printf("            ||     ||\n");
}

int stock=5;
int fitness=5;

void stock_update(int lunchfood){
    int crop = (rand() % 6) - 3;    // On s'assure d'une génération aléatoire sur [-3;3]
    stock = (stock-lunchfood)+crop;
    if (stock < 0)
        stock = 0;
    else if (stock > 10)
        stock = 10;
}

void fitness_update(int lunchfood){
    int digestion = -(rand() % 3);  // Génération aléatoire sur [-3;0]
    fitness = (fitness+lunchfood)+digestion;
    if (fitness < 0)
        fitness = 0;
    else if (fitness > 10)
        fitness = 10;
}

int main(int argc, char* argv[]){
    return 0;
    // dessiner_vache(BYEBYELIFE);
}