#include <stdio.h>

#define MAX_COMIDAS 100
#define MAX_NOMBRE 50

const int maximo_veces_hecha = 7;

typedef struct comida{
    char nombre[MAX_NOMBRE];
    int cantidad_veces_hecha;
} comida_t;
/*
* PRE: inicio debe estar inicializado, tope debe estar inicializado,cantidad_comidas debe estar inicializado
* POST: devuelve la cantidad de comidas que puede cocinar
*/
int cantidad_comidas_cocinar(comida_t comidas[MAX_COMIDAS],int inicio, int tope, int cantidad_comidas){
    if(inicio < tope){
        if(comidas[inicio].cantidad_veces_hecha < maximo_veces_hecha){
            cantidad_comidas++;
        }
        return cantidad_comidas_cocinar(comidas, inicio+1, tope, cantidad_comidas);
    }
    
    return cantidad_comidas;
}

int alternativa(comida_t comidas[MAX_COMIDAS],int inicio, int tope){
    if(inicio < tope){
        if(comidas[inicio].cantidad_veces_hecha < maximo_veces_hecha){
            return 1 + alternativa(comidas,inicio+1,tope);
        }
        return alternativa(comidas,inicio+1,tope);
    }
    return 0;
}

int main(){
    
    comida_t comidas[MAX_COMIDAS];

    comidas[0].cantidad_veces_hecha = 3;
    comidas[1].cantidad_veces_hecha = 5;
    comidas[2].cantidad_veces_hecha = 10;
    comidas[3].cantidad_veces_hecha = 7;
    comidas[4].cantidad_veces_hecha = 6;
    comidas[5].cantidad_veces_hecha = 1;


    printf("Resultado: %i\n",cantidad_comidas_cocinar(comidas,0,6,0));

    printf("Resultado alternativo: %i\n",alternativa(comidas,0,6));

    return 0;
}