#include <stdio.h>

const int DISTANCIA_INICIAL = 200;

typedef struct juego
{
int distancia;
int pan_pie;
char pan_inicial;
int queso_pie;
char queso_inicial;
char ultima_jugada;
} juego_t;

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

int main(){

    juego_t jueguito; 

    inicializar_juego(&jueguito);

    while(jueguito.distancia > 0){
        jugar_turno(&jueguito);
    }

    printf("Gano %c \n", jueguito.ultima_jugada);

    return 0;
}