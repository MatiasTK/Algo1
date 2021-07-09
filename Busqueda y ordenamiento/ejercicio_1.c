//                                          INCOMPLETO
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 50
#define MAX_COMIDA 50

typedef struct comida {
char nombre[MAX_NOMBRE];
bool es_vegana;
bool tiene_tacc;
int precio;
} comida_t;

void ordenar_por_insercion(comida_t comida[], int tope){

    int k;
    comida_t auxiliar;

    for(int i = 1; i < tope; i++){
        k = i;
        auxiliar = comida[i];
        while(k > 0 && strcmp(auxiliar.nombre, comida[k-1].nombre) > 0){
            comida[k] = comida[k-1];
            k--;
        }
        comida[k] = auxiliar;
    }
}

int buscar_hamburguesa(comida_t comida[MAX_COMIDA], int tope){
    int inicio = 0;
    int fin = tope-1;
    int centro;
    int posicion = -1;

    while(posicion == -1 && inicio <= fin){
        centro = (inicio + fin)/2;
        if(strcmp(comida[centro].nombre, "hamburguesa") == 0 ){
            posicion = centro;
        } else if(strcmp(comida[centro].nombre, "hamburguesa") > 0){
            fin = centro-1;
        } else {
            inicio = centro+1;
        }
    }
    return posicion;
}

int main(){

    comida_t comida[MAX_COMIDA];
    int tope = 0;
    ordenar_por_insercion(comida, tope);

    return 0;
}