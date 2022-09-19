#include "osos_contra_reloj.h"

#define MAX_TERRENO_FILA 20
#define MAX_TERRENO_COLUMNA 30

#define CANTIDAD_ARBOLES 350
#define CANTIDAD_PIEDRAS 80

#define CANTIDAD_PILAS 30
#define CANTIDAD_VELAS 30
#define CANTIDAD_BENGALAS 30

const char VACIO = '*';
const char CHLOE = 'C';
const char PANDA_OSO = 'P';
const char PARDO_OSO = 'G';
const char POLAR_OSO = 'I';
const char ARBOL = 'A';
const char PIEDRA = 'R';
const char KOALA = 'K';
const char LINTERNA = 'L';

const char ARRIBA = 'W';
const char ABAJO = 'S';
const char IZQUIERDA = 'A';
const char DERECHA = 'D';


void inicializar_juego(juego_t* juego , char tipo_personaje){
//Elegir personaje
    tipo_personaje = juego->personaje.tipo;
//Personaje panda
    if(tipo_personaje == PANDA_OSO && juego->personaje.tiempo_perdido >= 30){
        juego->chloe_visible = true;
    }
//Spawnear matriz
    int matriz_ejemplo[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];
    for(int i = 0; i < MAX_TERRENO_FILA; i++){
        for(int j = 0; j < MAX_TERRENO_COLUMNA; j++){
            matriz_ejemplo[i][j] = VACIO;
        }
    }
//Spawnear personaje y chloe

    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
    juego->personaje.posicion.col = 0;

    bool existe_chloe = false;

    juego->amiga_chloe.fil = rand() % MAX_TERRENO_FILA;
    juego->amiga_chloe.col = rand() % MAX_TERRENO_COLUMNA;

    while(existe_chloe == false){
        if(juego->amiga_chloe.fil == juego->personaje.posicion.fil){
            juego->amiga_chloe.fil = rand() % MAX_TERRENO_FILA;
            juego->amiga_chloe.col = rand() % MAX_TERRENO_COLUMNA;
        } else {
            existe_chloe = true;
        }
    }

//Obstaculos
    juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
    juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;

    juego->cantidad_obstaculos = 0;

    while(juego->cantidad_obstaculos < CANTIDAD_ARBOLES){
        if(matriz_ejemplo[juego->obstaculos->posicion.fil][juego->obstaculos->posicion.col] == VACIO){

            matriz_ejemplo[juego->obstaculos->posicion.fil][juego->obstaculos->posicion.col] = ARBOL;
            juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;
            juego->cantidad_obstaculos++;
        } else {
            juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;  
        }
    }

    while(juego->cantidad_obstaculos < (CANTIDAD_ARBOLES + CANTIDAD_PIEDRAS)){
        if(matriz_ejemplo[juego->obstaculos->posicion.fil][juego->obstaculos->posicion.col] == VACIO){

            matriz_ejemplo[juego->obstaculos->posicion.fil][juego->obstaculos->posicion.col] = PIEDRA;
            juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;
            juego->cantidad_obstaculos++;
        } else {
            juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;
        }
    }

    bool existe_koala = false;

    while(existe_koala == false){
        if(matriz_ejemplo[juego->obstaculos->posicion.fil][juego->obstaculos->posicion.col] == VACIO){
            bool existe_koala = true;
        } else {
            juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;
        }
    } existe_koala = false;

    if(juego->herramientas->tipo == LINTERNA && juego->personaje.ultimo_movimiento == LINTERNA){ 
        if(matriz_ejemplo[juego->obstaculos->posicion.fil][juego->obstaculos->posicion.col] == VACIO){
            bool existe_koala = true;
        } else {
            juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;
        }
    } existe_koala = false;
    
//Si choco obstaculos
    int x = 0;

    while(x < MAX_OBSTACULOS){
        if(juego->personaje.posicion.fil == juego->obstaculos[x].posicion.fil && juego->personaje.posicion.col == juego->obstaculos[x].posicion.col){
            if(matriz_ejemplo[juego->obstaculos[x].posicion.fil][juego->obstaculos[x].posicion.col] == ARBOL){
                if(juego->personaje.tipo == PARDO_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 0.5;
                    x++;
                } else {
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 1;
                    x++;
                }
            } else if(matriz_ejemplo[juego->obstaculos[x].posicion.fil][juego->obstaculos[x].posicion.col] == PIEDRA){
                if(juego->personaje.tipo != POLAR_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 2;
                    x++;
                }
            } else if(matriz_ejemplo[juego->obstaculos[x].posicion.fil][juego->obstaculos[x].posicion.col] == KOALA){
                    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
                    juego->personaje.posicion.col = 0;
                    x++;
            }
        }
    }
//Herramientas mochila
    int usos_linterna = 10;
    int usos_linterna_pardo = 15;

    if(usos_linterna <= 0 || usos_linterna_pardo <= 0){
        juego->personaje.elemento_en_uso = -1;
    }

    if(juego->personaje.elemento_en_uso != -1 && juego->herramientas->tipo == LINTERNA){
        if(juego->personaje.ultimo_movimiento == ARRIBA || juego->personaje.ultimo_movimiento == ABAJO || juego->personaje.ultimo_movimiento == IZQUIERDA || juego->personaje.ultimo_movimiento == DERECHA && juego->personaje.tipo == PARDO_OSO){
            usos_linterna_pardo = usos_linterna_pardo - 1;
        } else if(juego->personaje.ultimo_movimiento == ARRIBA || juego->personaje.ultimo_movimiento == ABAJO || juego->personaje.ultimo_movimiento == IZQUIERDA || juego->personaje.ultimo_movimiento == DERECHA){
            usos_linterna = usos_linterna -1;
        }
    }

    if(juego->herramientas->tipo == LINTERNA && juego->personaje.ultimo_movimiento == LINTERNA){
        if(juego->personaje.elemento_en_uso == -1 && juego->personaje.tipo == PARDO_OSO && usos_linterna_pardo > 0){
            //FALTA CODEAR ILUMINAR LA FILA
            juego->personaje.elemento_en_uso = 0;
            usos_linterna_pardo = usos_linterna_pardo - 1;
        } else if(juego->personaje.elemento_en_uso == -1 && usos_linterna > 0){
            //FALTA CODEAR ILUMINAR LA FILA
            juego->personaje.elemento_en_uso = 0;
            usos_linterna = usos_linterna -1;
        } else if(juego->personaje.elemento_en_uso != -1){
            juego->personaje.elemento_en_uso = -1;
        } else {
            printf("No podes hacer eso");
        }
    }

    int usos_vela = 5;
//Herramientas recolestables
    juego->cantidad_herramientas = 0;
    juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
    juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;

    while(juego->cantidad_herramientas < CANTIDAD_PILAS){
        if(matriz_ejemplo[juego->herramientas->posicion.fil][juego->herramientas->posicion.col] == VACIO){

            matriz_ejemplo[juego->herramientas->posicion.fil][juego->herramientas->posicion.col] = PILA;
            juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;
            juego->cantidad_herramientas++;
        } else {
            juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;  
        }
    }

    while(juego->cantidad_herramientas < (CANTIDAD_PILAS + CANTIDAD_VELAS)){
        if(matriz_ejemplo[juego->herramientas->posicion.fil][juego->herramientas->posicion.col] == VACIO){

            matriz_ejemplo[juego->herramientas->posicion.fil][juego->herramientas->posicion.col] = VELA;
            juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;
            juego->cantidad_herramientas++;
        } else {
            juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;  
        }
    }

    while(juego->cantidad_herramientas < (CANTIDAD_PILAS + CANTIDAD_VELAS + CANTIDAD_BENGALAS)){
        if(matriz_ejemplo[juego->herramientas->posicion.fil][juego->herramientas->posicion.col] == VACIO){

            matriz_ejemplo[juego->herramientas->posicion.fil][juego->herramientas->posicion.col] = BENGALA;
            juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;
            juego->cantidad_herramientas++;
        } else {
            juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
            juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;  
        }
    }
//Choco con una herramienta

    int 
}