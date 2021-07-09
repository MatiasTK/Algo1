#include <stdio.h>
#include "ejercicio_1_lib.h"

const int DISTANCIA_INICIAL = 200;

void inicializar_juego(juego_t* jueguito){

    (*jueguito).distancia = DISTANCIA_INICIAL;

    printf("Pan, decime el largo de tu pie: ");
    scanf("%i", &((*jueguito).pan_pie));

    printf("Pan, decime tu inicial: ");
    scanf(" %c", &((*jueguito).pan_inicial));

    printf("Queso, decime el largo de tu pie: ");
    scanf("%i",&((*jueguito).queso_pie));

    printf("Queso, decime tu inicial: ");
    scanf(" %c",&((*jueguito).queso_inicial));

}

void jugar_turno(juego_t* jueguito){

    (*jueguito).distancia -= (*jueguito).pan_pie;
    (*jueguito).ultima_jugada = (*jueguito).pan_inicial;

    if((*jueguito).distancia > 0){
    (*jueguito).distancia = (*jueguito).distancia - (*jueguito).queso_pie;
    (*jueguito).ultima_jugada = (*jueguito).queso_inicial;
    }

}
/*
void jugar_pan(){
                                    EJ: si yo no defino esto en el .h es una funcion privada
}
*/
