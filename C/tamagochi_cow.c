// たまごち牛。ｃ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BYEBYELIFE 0
#define LIFESUCKS 1
#define LIFEROCKS 2

void dessiner_vache(int etat){
    char* yeux="^^";
    char langue=' ';
    if (etat == LIFESUCKS)
        strcpy(yeux, "--");
    else if (etat == BYEBYELIFE)
        strcpy(yeux, "xx");
        langue='U';
    printf("        ^__^\n");
    printf("        (%s)\\_______\n", yeux);
    printf("        (__)\\       )\\/\\\n");
    printf("         %c  ||----w |\n", langue);
    printf("            ||     ||\n");
}

int stock=5;
int fitness=5;

void stock_update(int lunchfood){
    int crop = (rand() % 6) - 3;    // On s'assure d'une génération aléatoire sur [-3;3]
    stock = (stock-lunchfood)+crop;
}

void fitness_update(int lunchfood){
    int digestion = -(rand() % 3);  // Génération aléatoire sur [-3;0]
    fitness = (fitness+lunchfood)+digestion;
}

int main(int argc, char* argv[]){
    return 0;
}