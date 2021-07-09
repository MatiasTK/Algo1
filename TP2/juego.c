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

        //PANEL DE CONTROL
        for(int i = 0; i < juego.personaje.cantidad_elementos; i++){
            printf("Herramienta: %c, Movimientos restantes: %i\n",juego.personaje.mochila[i].tipo, juego.personaje.mochila[i].movimientos_restantes);
        }
        printf("Posicion herramienta en uso %i\n", juego.personaje.elemento_en_uso);
        printf("Tiempo perdido: %i\n", (int)juego.personaje.tiempo_perdido);
        printf("Posicion usuario-> X: %i Y: %i\n", juego.personaje.posicion.col, juego.personaje.posicion.fil);
        printf("Posicion chloe-> X: %i Y: %i\n",juego.amiga_chloe.col, juego.amiga_chloe.fil);
        for(int i = 0; i < 10; i++){
            printf("Hay una %c en X: %i Y: %i\n",juego.herramientas[i].tipo,juego.herramientas[i].posicion.col,juego.herramientas[i].posicion.fil);
        }
        printf("Ultimo movmiento: %c\n", juego.personaje.ultimo_movimiento);
        for(int i = 0; i < juego.cantidad_herramientas; i++){
            if(juego.herramientas[i].visible == true){
                printf("Esta herramienta tendria que ser visible: %c en x: %i y: %i\n\n",juego.herramientas[i].tipo, juego.herramientas[i].posicion.col, juego.herramientas[i].posicion.fil);
            }
        }
        int koalas = 0;
        for(int i = 0; i < juego.cantidad_obstaculos; i++){
            if(juego.obstaculos[i].tipo == 'K'){
                koalas++;
            }
        }
        printf("Cantidad koalas: %i\n", koalas);
    }

    system("clear");
    printf("Tiempo que te tomo encontrar a chloe: %i segundos\n",(int)(detener_cronometro() + juego.personaje.tiempo_perdido));
    printf("Game Over\n");

    return 0;
}   