#include <stdio.h>

#define MAX_FILA 10
#define MAX_COLUMNA 10

typedef struct ficha {
    int id_ficha;
    int id_ficha_derecha;
    int id_ficha_izquierda;
    int id_ficha_arriba;
    int id_ficha_abajo;
} ficha_t;

int fichas_borde(int matriz[MAX_FILA][MAX_COLUMNA], int tope_fila, int tope_columna){

    ficha_t ficha;

    int deberian_estar_borde = 0;

    for(int i = 0; i < tope_fila; i++){
        for(int j = 0; j < tope_columna; j++){
            if(ficha.id_ficha == matriz[i][j]){
                if(ficha.id_ficha_arriba == -1){
                    if(matriz[i-1][j] != -1){
                        deberian_estar_borde++;
                    }
                }else if(ficha.id_ficha_abajo == MAX_FILA+1){
                    if(matriz[i+1][j] != MAX_FILA+1){
                        deberian_estar_borde++;
                    }
                }else if(ficha.id_ficha_izquierda == -1){
                    if(matriz[i][j-1] != -1){
                        deberian_estar_borde++;
                    }
                }else if(ficha.id_ficha_derecha == MAX_COLUMNA+1){
                    if(matriz[i][j+1] != MAX_COLUMNA+1){
                        deberian_estar_borde++;
                    }
                }
            }
        }
    }

}