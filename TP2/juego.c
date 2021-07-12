#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "test_de_personalidad.h"
#include "osos_contra_reloj.h"
#include "utiles.h"

const char TIEMPO = 'T';

int main(){
    juego_t juego;
    char jugada;
    char personalidad_detectada;
    srand((unsigned)time(NULL));

    test_de_personalidad(&personalidad_detectada);
    inicializar_juego(&juego,personalidad_detectada);
    mostrar_juego(juego);
    iniciar_cronometro();

    while(estado_juego(juego) != -1){
        printf("Que queres hacer? \n");
        printf("Arriba[W] Abajo[S] Izquierda[A] Derecha[D] Linterna[L] Vela[V] Bengala[E] Tiempo[T]\n");
        scanf(" %c%*[^\n]", &jugada);
        if(es_jugada_valida(jugada) == true){
        realizar_jugada(&juego,jugada);
        }
        system("clear");
        mostrar_juego(juego);
        if(es_jugada_valida(jugada) == false){
            printf("Ese caracter no es valido\n");
        }
        if(jugada == TIEMPO){
        printf("Tiempo transcurrido: %i segundos\n", (int)tiempo_actual());
        }
    }

    system("clear");
    printf("Tiempo que te tomo encontrar a chloe: %i segundos\n",(int)(detener_cronometro() + juego.personaje.tiempo_perdido));
    printf("Game Over\n");

    return 0;
}   