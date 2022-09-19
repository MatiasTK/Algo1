#include <stdio.h>
#include <string.h>

#define SANDIA "Sandia"
#define CEREZA "Cereza"
#define LIMON "Limon"

#define MARRON "Marron"

#define MAX_SABOR 10
#define MAX_COLOR 5
#define MAX_CARAMELOS 100

typedef struct caramelo {
    int radio;
    char sabor[MAX_SABOR];
    char color[MAX_COLOR];
} caramelo_t;

const int DIAMETRO_MAX = 10;

int podra_comer(caramelo_t caramelos[MAX_CARAMELOS],int inicio, int tope){

    int diametro = (caramelos[inicio].radio * 2);

    if(inicio < tope){
        if(diametro < DIAMETRO_MAX){
            if(strcmp(caramelos[inicio].sabor,SANDIA) == 0 || strcmp(caramelos[inicio].sabor,CEREZA) == 0|| strcmp(caramelos[inicio].sabor,LIMON) == 0){
                if(strcmp(caramelos[inicio].color,MARRON) != 0){
                return 1 + podra_comer(caramelos,inicio+1,tope);
                }
            }
        }
        return podra_comer(caramelos,inicio+1,tope);
    }
    return 0;
}


int main(){

    caramelo_t caramelos[MAX_CARAMELOS];
    caramelos[0].radio = 2;
    strcpy(caramelos[0].sabor,"Cereza");
    strcpy(caramelos[0].color,"Rojo");
    caramelos[1].radio = 5;
    strcpy(caramelos[1].sabor,"Sandia");
    strcpy(caramelos[1].color,"Verde");
    caramelos[2].radio = 3;
    strcpy(caramelos[2].sabor,"Limon");
    strcpy(caramelos[2].color,"Marron");

    printf("Resultado: %i",podra_comer(caramelos,0,3));

    return 0;
}