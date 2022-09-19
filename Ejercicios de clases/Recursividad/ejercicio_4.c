#include <stdio.h>

#define MAX_FILAS 4
#define MAX_COLUMNAS 4

typedef struct coordenada {
int fil;
int col;
} coordenada_t;

typedef struct pozo {
int profundidad;
coordenada_t proximo_pozo;
} pozo_t;

int cantidad_movimientos(pozo_t terreno[MAX_FILAS][MAX_COLUMNAS], coordenada_t pozo_actual){

    int fila_siguiente = terreno[pozo_actual.fil][pozo_actual.col].proximo_pozo.fil;
    int columna_siguiente = terreno[pozo_actual.fil][pozo_actual.col].proximo_pozo.col;

    if(fila_siguiente == pozo_actual.fil && columna_siguiente == pozo_actual.col){
        return 0;
    }

    return 1 + cantidad_movimientos(terreno, terreno[pozo_actual.fil][pozo_actual.col].proximo_pozo);

}

int main(){

    return 0;
}