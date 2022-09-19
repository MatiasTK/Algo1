#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "test_de_personalidad.h"
#include "osos_contra_reloj.h"
#include "utiles.h"

void test_de_personalidad(char* personalidad_detectada);

void inicializar_juego(juego_t* juego , char tipo_personaje);

int estado_juego(juego_t juego);

void mostrar_juego(juego_t juego);

void realizar_jugada(juego_t* juego, char jugada);

bool es_jugada_valida(char jugada);


int main(){

    char jugada;
    
    srand((unsigned)time(NULL));

    juego_t juego;
    char personalidad_detectada;
    test_de_personalidad(&personalidad_detectada);
    system("clear");

    inicializar_juego(&juego,personalidad_detectada);
    estado_juego(juego);

    mostrar_juego(juego);
    printf("Que queres hacer? \n");
    printf("Arriba[W] Abajo[S] Izquierda[A] Derecha[D] Linterna[L] Vela[V] Bengala[E] Tiempo[T]\n");
    scanf(" %c%*[^\n]", &jugada);
    system("clear");
    realizar_jugada(&juego, jugada);
    mostrar_juego(juego);
    es_jugada_valida(jugada);

    while(estado_juego(juego) != -1){
        printf("Que queres hacer? \n");
        printf("Arriba[W] Abajo[S] Izquierda[A] Derecha[D] Linterna[L] Vela[V] Bengala[E] Tiempo[T]\n");
        scanf(" %c%*[^\n]", &jugada);

        realizar_jugada(&juego,jugada);
        system("clear");
        mostrar_juego(juego);
        printf("Tiempo perdido: %i segundos\n ", (int)juego.personaje.tiempo_perdido);
    //PANEL CONTROL
        for(int i = 0; i < 3; i++){
            printf(" %c cantidad: %i || ", juego.personaje.mochila[i].tipo, juego.personaje.mochila[i].movimientos_restantes);
        }
        printf("\nHerramienta encendida? %i\n", juego.personaje.elemento_en_uso);
        // printf("Tiempo transcurrido: %i segundos\n", (int)tiempo_actual());
        printf("Ultimo movimiento? %c\n", juego.personaje.ultimo_movimiento);
    }

    return 0;
}