#include <stdio.h>
//                             TENGO QUE RECORRER EL VECTOR DE ID FICHA Y VER SI ARRIBA TIENE POR EJEMPLO EL ID_FICHA_ARRIBA

#define MAX_FILA 10
#define MAX_COLMUNA 10

typedef struct ficha {
    int id_ficha;
    int id_ficha_derecha;
    int id_ficha_izquierda;
    int id_ficha_arriba;
    int id_ficha_abajo;
} ficha_t;

int fichas_borde(int matriz[MAX_FILA][MAX_COLMUNA], int tope_fila, int tope_columna){
    ficha_t ficha;
    int contador_desordenadas = 0;

    for(int i = 0; i < tope_fila; i++){
        for(int j = 0; j < tope_columna; j++){
            if(ficha.id_ficha == matriz[i][j]){
                if(matriz[i-1][j] >= 0 && matriz[i-1][j] != ficha.id_ficha_arriba){
                    contador_desordenadas++;
                }else if(matriz[i+1][j] < MAX_FILA && matriz[i+1][j] != ficha.id_ficha_abajo){
                    contador_desordenadas++;
                }else if(matriz[i][j-1] >= 0 && matriz[i][j-1] != ficha.id_ficha_izquierda){
                    contador_desordenadas++;
                }else if(matriz[i][j+1] < MAX_COLMUNA && matriz[i][j+1] != ficha.id_ficha_derecha){
                    contador_desordenadas++;
                }
            }
        }
    }

    return contador_desordenadas;
}