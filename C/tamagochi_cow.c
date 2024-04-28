// たまごち牛。ｃ
#include <stdio.h>
#include <string.h>

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

int stock_update(int stock, int lunchfood, int crop){
    return (stock-lunchfood)+crop;
}

int fitness_update(int fitness, int lunchfood, int digestion){
    return (fitness+lunchfood)+digestion;
}

int main(int argc, char* argv[]){
    return 0;
}