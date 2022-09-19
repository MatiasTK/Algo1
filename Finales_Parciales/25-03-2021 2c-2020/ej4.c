#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
                                // CREO QUE ESTA MAL -> ME HACE MUCHO RUIDO
#define MAX_CONTRASENIAS 200

//Union de vectores -> Hago un nuevo vector con las contraseñas sin repetir y si miden menos de 10
void unir_contrasenias(char vector_tom[MAX_CONTRASENIAS],int tope_tom, char vector_jerry[MAX_CONTRASENIAS], int tope_jerry, char vector_final[MAX_CONTRASENIAS], int* tope_final){
    int i = 0;
    int j = 0;
    (*tope_final) = 0;

    while(i < tope_tom && j < tope_jerry){
        if(strcmp(vector_tom[i],vector_jerry[j]) <= 0){
            if(strlen(vector_tom[i]) < 10){
                vector_final[*tope_final] = vector_tom[i];
                (*tope_final)++;
                i++;
            }
        }else{
            if(strlen(vector_jerry[j]) < 10){
                vector_final[*tope_final] = vector_jerry[j];
                (*tope_final)++;
                j++;
            }
        }
    }
}

bool probado(char vector_final[MAX_CONTRASENIAS],int tope_final, char contrasenias_probadas[MAX_CONTRASENIAS]){
    int j = 0;
    for(int i = 0; i < tope_final; i++){
        if(strcmp(vector_final[i],contrasenias_probadas[j]) == 0){
            return true;
        }
    }
    j++;
    return false;
}
