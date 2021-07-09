#include <stdbool.h>
#define MAX_FILAS 30
#define MAX_COLUMNAS 25
const char BLUE = 'B';
const char QUESO = 'Q';
const char VACIO = '-';

bool mover(char mansion[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int nueva_fila, int nueva_columna) {
    if(mansion[nueva_fila][nueva_columna] == QUESO || nueva_fila > tope_filas || nueva_columna > tope_columnas){
        return false;
    } else {
        for(int i = 0; i < tope_filas; i++){
            for(int j = 0; j < tope_columnas; j++){
                if(mansion[i][j] == BLUE){
                    mansion[i][j] = VACIO;
                }
            }
        }
        mansion[nueva_fila][nueva_columna] = BLUE; 
        return true;
    }
}
