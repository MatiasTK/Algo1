#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_ORDENADO 10
#define MAX_DESORDENADO 10

void insertar_ordenado(int vector_ordenado[MAX_ORDENADO], int* tope, int inserto){
    int i = (*tope);
    while(i > 0 && vector_ordenado[i-1] > inserto){
        vector_ordenado[i] = vector_ordenado[i -1];
        i--;
    }
    vector_ordenado[i] = inserto;
    (*tope)++;
}

void insertar_desordenado(int vector_desordenado[MAX_DESORDENADO], int* tope, int inserto){
    vector_desordenado[(*tope)] = inserto;
    (*tope)++;
}

void eliminar_ordenado(int vector_ordenado[MAX_ORDENADO], int* tope, int elimino){
    int i = 0;
    bool encontre = false;
    int posicion = 0;
    while(i < (*tope) && !encontre){
        if(vector_ordenado[i] == elimino){
            encontre = true;
            posicion = i;
        }
        i++;
    }
    if(encontre){
        for(int j = posicion; j < (*tope); j++){
            vector_ordenado[j]=vector_ordenado[j+1];
        }
        (*tope)--;
    }
}

void eliminar_desordenado(int vector_desordenado[MAX_DESORDENADO], int* tope, int elimino){
    bool encontre = false;
    int i = 0;
    while(i < (*tope) && !encontre){
        if(vector_desordenado[i] == elimino){
            encontre = true;
        }
        i++;
    }
vector_desordenado[i-1] = vector_desordenado[(*tope)-1];
(*tope)--;
}

int main(){

    int tope_ordenado = 5;
    int vector_ordenado[MAX_ORDENADO] = {1,0,5,7,12};
    int insertar = 9;
    insertar_ordenado(vector_ordenado,&tope_ordenado,insertar);
    printf("Vector ordenado:");
    for(int i = 0; i < tope_ordenado; i++){
        printf(" %i", vector_ordenado[i]);
    }
    printf("\n");

    int vector_desordenado[MAX_DESORDENADO]= {1,9,7,2,5,0,8};
    int tope_desordenado = 7;
    insertar_desordenado(vector_desordenado,&tope_desordenado,insertar);
    printf("Vector desordenado:");
    for(int i = 0; i < tope_desordenado; i++){
        printf(" %i", vector_desordenado[i]);
    }
    printf("\n");

    int elimino = 5;
    eliminar_ordenado(vector_ordenado,&tope_ordenado,elimino);
    printf("Elimino 5 del vector ordenado(y donde ya se inserto el 9):");
    for(int i = 0; i < tope_ordenado; i++){
        printf(" %i", vector_ordenado[i]);
    }
    printf("\n");
    
    eliminar_desordenado(vector_desordenado,&tope_desordenado,elimino);
    printf("Elimino 5 del vector desordenado(y donde ya se inserto el 9):");
    for(int i = 0; i < tope_desordenado; i++){
        printf(" %i", vector_desordenado[i]);
    }
    printf("\n");

}