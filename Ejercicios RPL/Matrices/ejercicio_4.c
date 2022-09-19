#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
// Aca van las constantes

int personas_bajo_efecto(int grupos[MAX_FILAS][MAX_COLUMNAS], int tope_fila, int tope_columna) {

    int total_personas = 0;

    for(int i = 0; i < tope_fila;i++){
        for(int j = 0; j < tope_columna; j++){
            total_personas = total_personas + grupos[i][j];
        }
    }

    if(grupos[MAX_FILAS][MAX_COLUMNAS] == 0){
        total_personas = 0;
    }

    return total_personas;
}
