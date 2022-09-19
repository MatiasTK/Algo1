//partidas.csv ordenado por nombre y luego fecha
//fecha;nombre del contrincante;id_juego;resultado de la partida

//juegos.dat archivo binario ordenado por id_juego 

#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct juego {
    int id_juego;
    char nombre[MAX_NOMBRE];
} juego_t;

void es_juego_valido(juego_t juego, FILE* juegos, int id_buscado){
    size_t leidos = fread(&juego,sizeof(juego_t),1,juegos);

    while(leidos > 0 && strcmp(juego.id_juego,id_buscado) == 0){
        leidos = fread(&juego,sizeof(juego_t),1,juegos);
    }
}

int listar_partidas(){

    FILE* partidas = fopen("partidas.csv","r");
    FILE* juegos = fopen("juegos.dat","r");

    if(!partidas){
        printf("No se pudo abrir partidas.csv");
        return -1;
    }

    if(juegos == NULL){
        printf("No se pudo abrir juegos.dat");
        fclose(partidas);
        return -1;
    }

    fclose(partidas);
    fclose(juegos);
}