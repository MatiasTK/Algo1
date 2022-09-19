#include <stdio.h>
#include <stdbool.h>
#include "solucion.h"

typedef struct mensaje {
    bool tiene_palabras_de_colegio;
    int cantidad_de_palabras;
    int cantidad_de_respuestas;
    bool autor_sospechoso;
} mensaje_t;

int indice_de_probabilidad_de_copia(mensaje_t mensaje){
    int probabilidad = 5;

    if(mensaje.tiene_palabras_de_colegio == true){
        probabilidad = probabilidad + 2;
    } else {
        probabilidad = probabilidad - 2;
    }

    if(mensaje.cantidad_de_palabras > 50){
        probabilidad = probabilidad + 2;
    } else {
        probabilidad = probabilidad - 1;
    }

    if(mensaje.cantidad_de_respuestas > 3){
        probabilidad = probabilidad + 2;
    }

    if(mensaje.autor_sospechoso == true){
        probabilidad = probabilidad + 3;
    } else {
        probabilidad = probabilidad - 1;
    }

    return probabilidad;
}