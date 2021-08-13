#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
* PRE: tope_polar y tope_panda deben estar inicializados, vector_polar y vector_panda deben ser vectores validos
* POST: Crea un tercer vector con la interseccion(Canciones que esten en los dos vectores) de canciones de los vectores 
vector_polar y vector_panda con su respectivo tope_final
*/
void interseccion_canciones(cancion_t vector_polar[MAX_CANCION], int tope_polar, cancion_t vector_panda[MAX_CANCION], int tope_panda
, cancion_t vector_final[MAX_CANCION],int* tope_final){
    int i = 0;
    int j = 0;
    (*tope_final) = 0;
    
    while((i < tope_polar) && (j < tope_panda)){
        if(strcmp(vector_polar[i].nombre,vector_panda[j].nombre) == 0){
            vector_final[(*tope_final)] = vector_polar[i];
            i++;
            j++;
            (*tope_final)++;
        }else if(strcmp(vector_polar[i].nombre,vector_panda[j].nombre) < 0){
            i++;
        }else{
            j++;
        }
    }
}


int main(){


    return 0;
}