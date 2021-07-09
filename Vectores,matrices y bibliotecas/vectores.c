#include "vectores.h"
#include <stdio.h>

void imprimir_vector_de(int vector[], int tope){

    int i;

    for(i = 0; i < tope; i++){
    printf("%i\n", vector[i]);       
    }
}
void inicializar_arreglo_de(int v[], int tope){

    int i;
    i = 0;
    while(i < tope){
        v[i] = i+1;
        i++;
    }
}
