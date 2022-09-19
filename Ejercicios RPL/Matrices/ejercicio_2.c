#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

const char ARBOL = 'A';
const char VACIO = 'B';

int cantidad_arboles(char parque[MAX_FILAS][MAX_COLUMNAS]) {

    int contador_arbol = 0;

    for(int i = 0; i < MAX_FILAS; i++){
        for(int j = 0; j < MAX_COLUMNAS; j++){
            if(parque[i][j] == ARBOL){
                contador_arbol++;
            }
        }
    }
    return contador_arbol;

}