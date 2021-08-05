#include <stdio.h>

#define MAX_FILA 10
#define MAX_COLUMNA 10

typedef struct pieza {
    int fil;
    int col;
    int id;
} pieza_t;

void armar_rompecabezas(int matriz[MAX_FILA][MAX_COLUMNA], int tope_fila, int tope_columna){
    pieza_t pieza;

    for(int i = 0; i < tope_fila; i++){
        for(int j = 0; j < tope_columna; j++){
            if(i == pieza.fil && j == pieza.col){
                matriz[i][j] == pieza.id;
            }
        }
    }
}   

int main(){


    return 0;
}