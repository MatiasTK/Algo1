#include <stdio.h>
#include "ejercicio_1_lib.h"

int main(){

    juego_t jueguito; 

    inicializar_juego(&jueguito);

    while(jueguito.distancia > 0){
        jugar_turno(&jueguito);
    }

    printf("Gano %c \n", jueguito.ultima_jugada);

    return 0;
}