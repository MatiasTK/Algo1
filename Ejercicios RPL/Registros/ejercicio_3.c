#include <stdio.h>
#include "solucion.h"
const int CAMBIAR_SIGNO = (-1);

typedef struct punto {
	int x;
	int y;
} punto_t;

int distancia_entre_puntos(punto_t primer_punto, punto_t segundo_punto) {

    int resta_x = primer_punto.x - segundo_punto.x;
    int resta_y = primer_punto.y - segundo_punto.y;

    if(resta_x < 0){
        resta_x = (resta_x * CAMBIAR_SIGNO);
    }
    if(resta_y < 0){
        resta_y = (resta_y * CAMBIAR_SIGNO);
    }

	int distancia = (resta_x + resta_y);

    return distancia;
}   