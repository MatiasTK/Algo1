#include <stdio.h>              
//                                                          VECTOR = ARREGLO = ARRAY
const int MAX_CUMPLES = 100;
const int REGALOS_INICIO = 3;
const int EDAD = 8;

/*
* Pre: recibe vector regalos, su tope previamente iniciado y edad menor a MAX_CUMPLES
* Post: Inicia el vector con la cantidad de regalos a las chicas
*/
void inicializar_regalos(int regalos_cumple[MAX_CUMPLES], int* tope, int EDAD){
    for(int i=0; i <= EDAD; i++){
        regalos_cumple[i] = REGALOS_INICIO + i;
        (*tope)++;
    }
}

/*
* Pre: recibe un vector iniciado con su correspondiente tope
* Post: Devuelve la cantidad total de regalos que tienen las chicas en el momento
*/
int total_regalos(int regalos_cumple[MAX_CUMPLES], int tope){
    int total_regalos = 0;
    for(int i=0; i < tope; i++){
        total_regalos = total_regalos + regalos_cumple[i];
    }
    return total_regalos;
}

int main(){

    int regalos_cumple[MAX_CUMPLES];
    int tope = 0;
    inicializar_regalos(regalos_cumple, &tope, EDAD);
    int regalos_totales = total_regalos(regalos_cumple, tope);

    printf("La cantidad de regalos que tienen las chicas hasta ahora son: %i \n", regalos_totales);

    return 0;
}