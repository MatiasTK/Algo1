#include "osos_contra_reloj.h"
#include "test_de_personalidad.h"
#include "utiles.h"
#include <stdbool.h>
#include <string.h>

const char VACIO = '*';

const char CHLOE = 'C';

const char PANDA_OSO = 'P';
const char PARDO_OSO = 'G';
const char POLAR_OSO = 'I';

const char ARBOL = 'A';
const char PIEDRA = 'R';
const char KOALA = 'K';

const char PILA = 'B';
const char VELA = 'V';
const char BENGALA = 'E';

const char LINTERNA = 'L';

const char ARRIBA = 'W';
const char ABAJO = 'S';
const char IZQUIERDA = 'A';
const char DERECHA = 'D';

const char VER_TIEMPO = 'T';

#define MAX_TERRENO_FILA 20
#define MAX_TERRENO_COLUMNA 30

#define MAX_ARBOLES 350
#define MAX_PIEDRAS 80

#define MAX_PILAS 30
#define MAX_VELAS 30
#define MAX_BENGALAS 10

void inicializar_obstaculos(juego_t* juego,int maximo_por_obstaculo, char tipo_obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    int cantidad_inicializada = juego->cantidad_obstaculos;

    while(juego->cantidad_obstaculos < (maximo_por_obstaculo + cantidad_inicializada)){
        coordenada_t aux;
        aux.fil = rand() % MAX_TERRENO_FILA;
        aux.col = rand() % MAX_TERRENO_COLUMNA;
       if(terreno[aux.fil][aux.col] == VACIO){
            juego->obstaculos[juego->cantidad_obstaculos].tipo = tipo_obstaculo;
            juego->obstaculos[juego->cantidad_obstaculos].visible = false;
            juego->obstaculos[juego->cantidad_obstaculos].posicion.fil = aux.fil;
            juego->obstaculos[juego->cantidad_obstaculos].posicion.col = aux.col;
            terreno[aux.fil][aux.col] = tipo_obstaculo;
            juego->cantidad_obstaculos++;
        }
    }
}

void inicializar_herramientas(juego_t* juego, int maximo_por_herramienta, char tipo_herramienta, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    int cantidad_inicializada = juego->cantidad_herramientas;
    
    while(juego->cantidad_herramientas < (maximo_por_herramienta + cantidad_inicializada)){
        coordenada_t aux;
        aux.fil = rand() % MAX_TERRENO_FILA;
        aux.col = rand() % MAX_TERRENO_COLUMNA;
        if(terreno[aux.fil][aux.col] == VACIO){
            juego->herramientas[juego->cantidad_herramientas].tipo = tipo_herramienta;
            juego->herramientas[juego->cantidad_herramientas].visible = false;
            juego->herramientas[juego->cantidad_herramientas].posicion.fil = aux.fil;
            juego->herramientas[juego->cantidad_herramientas].posicion.col = aux.col;
            terreno[aux.fil][aux.col] = tipo_herramienta;
            juego->cantidad_herramientas++;
        }
    }
}

void inicializar_juego(juego_t* juego, char tipo_personaje){
    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];
    juego->personaje.tipo = tipo_personaje;
    
    juego->chloe_visible = false;
    juego->obstaculos->visible = false;
    juego->herramientas->visible = false;

    bool existe_chloe = false;
 
    juego->cantidad_obstaculos = 0; 

    juego->cantidad_herramientas = 0;

    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
    juego->personaje.posicion.col = 0;

    juego->amiga_chloe.fil = rand() % MAX_TERRENO_FILA;
    juego->amiga_chloe.col = rand() % MAX_TERRENO_COLUMNA;

    juego->obstaculos->posicion.fil = rand() % MAX_TERRENO_FILA;
    juego->obstaculos->posicion.col = rand() % MAX_TERRENO_COLUMNA;

    juego->herramientas->posicion.fil = rand() % MAX_TERRENO_FILA;
    juego->herramientas->posicion.col = rand() % MAX_TERRENO_COLUMNA;

    for(int i=0; i < MAX_TERRENO_FILA; i++){
        for(int j=0; j < MAX_TERRENO_COLUMNA; j++){
            terreno[i][j] = VACIO;  
        }
    }

    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;

    while(existe_chloe == false){
        if(terreno[juego->amiga_chloe.fil][juego->amiga_chloe.col] == VACIO){
            terreno[juego->amiga_chloe.fil][juego->amiga_chloe.col] = CHLOE;
            existe_chloe = true;
        } else {
            juego->amiga_chloe.fil = rand() % MAX_TERRENO_FILA;
            juego->amiga_chloe.col = rand() % MAX_TERRENO_COLUMNA;
        }
    }
    
    inicializar_obstaculos(juego,MAX_ARBOLES,ARBOL,terreno);
    inicializar_obstaculos(juego,MAX_PIEDRAS,PIEDRA,terreno);
    inicializar_obstaculos(juego,1,KOALA,terreno);

    inicializar_herramientas(juego,MAX_PILAS,PILA,terreno);
    inicializar_herramientas(juego,MAX_VELAS,VELA,terreno);
    inicializar_herramientas(juego,MAX_BENGALAS,BENGALA,terreno);

    juego->personaje.elemento_en_uso = -1;
    juego->personaje.ultimo_movimiento = VACIO; 

    iniciar_cronometro();

    if(juego->personaje.tipo == PARDO_OSO){
        juego->personaje.mochila[0].movimientos_restantes = 15;
    } else {
        juego->personaje.mochila[0].movimientos_restantes = 10;
    }

    if(juego->personaje.tipo == PANDA_OSO){
        juego->personaje.mochila[1].movimientos_restantes = 30;
    }else {
        juego->personaje.mochila[1].movimientos_restantes = 20;
    }

    if(juego->personaje.tipo == PANDA_OSO){
        juego->personaje.mochila[2].movimientos_restantes = 6;
    }
}

int estado_juego(juego_t juego){
    if(juego.personaje.posicion.fil == juego.amiga_chloe.fil && juego.personaje.posicion.col == juego.amiga_chloe.col){
        system("clear");
        printf("Tiempo que te tomo encontrar a chloe: %i segundos\n",(int)(detener_cronometro() + juego.personaje.tiempo_perdido));
        printf("Game Over\n");
        return -1;
    } else {
        return 0;
    }
}

bool es_jugada_valida(char jugada){
    if(jugada == ARRIBA || jugada == ABAJO || jugada == IZQUIERDA || jugada == DERECHA || jugada == LINTERNA || jugada == VELA || jugada == BENGALA || jugada == VER_TIEMPO){
        return true;
    } else {
        return false;
    }
}

void matriz_ficticia(juego_t* juego, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    for(int i=0; i < MAX_TERRENO_FILA; i++){
        for(int j=0; j < MAX_TERRENO_COLUMNA; j++){
            terreno[i][j] = VACIO;  
        }
    }

    terreno[juego->amiga_chloe.fil][juego->amiga_chloe.col] = CHLOE;

    for(int i = 0; i < juego->cantidad_obstaculos; i++){
        terreno[juego->obstaculos[i].posicion.fil][juego->obstaculos[i].posicion.col] = juego->obstaculos[i].tipo;
    }

    for(int i = 0; i < juego->cantidad_herramientas; i++){
        terreno[juego->herramientas[i].posicion.fil][juego->herramientas[i].posicion.col] = juego->herramientas[i].tipo;
    }
   
    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;
    
}

int chocar_obstaculo(juego_t* juego,char jugada,char obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(es_jugada_valida(jugada) == true){
        if(jugada == ARRIBA && juego->personaje.posicion.fil -1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil > 0 && terreno[juego->personaje.posicion.fil - 1][juego->personaje.posicion.col] == obstaculo){
            if(obstaculo == ARBOL){
                if(juego->personaje.tipo == PARDO_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 0.5;
                } else {
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 1;
                }
            } else if(obstaculo == PIEDRA){
                if(juego->personaje.tipo != POLAR_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 2;
                }
            } else if(obstaculo == KOALA){
                    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
                    juego->personaje.posicion.col = 0;
                    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;
                    juego->personaje.posicion.fil = juego->personaje.posicion.fil + 1;
            }
            juego->personaje.ultimo_movimiento = ARRIBA;
            juego->personaje.posicion.fil = juego->personaje.posicion.fil - 1;
            return -1;
        } else if(jugada == ABAJO && juego->personaje.posicion.fil +1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil >= 0 && terreno[juego->personaje.posicion.fil +1][juego->personaje.posicion.col] == obstaculo){
            if(obstaculo == ARBOL){
                if(juego->personaje.tipo == PARDO_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 0.5;
                } else {
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 1;
                }
            } else if(obstaculo == PIEDRA){
                if(juego->personaje.tipo != POLAR_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 2;
                }
            } else if(obstaculo == KOALA){
                    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
                    juego->personaje.posicion.col = 0;
                    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;
                    juego->personaje.posicion.fil = juego->personaje.posicion.fil - 1;
            }
            juego->personaje.ultimo_movimiento = ABAJO;
            juego->personaje.posicion.fil = juego->personaje.posicion.fil + 1;
            return -1;
        } else if(jugada == IZQUIERDA && juego->personaje.posicion.col -1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col > 0 && terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col -1] == obstaculo){
            if(obstaculo == ARBOL){
                if(juego->personaje.tipo == PARDO_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 0.5;
                } else {
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 1;
                }
            } else if(obstaculo == PIEDRA){
                if(juego->personaje.tipo != POLAR_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 2;
                }
            } else if(obstaculo == KOALA){
                    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
                    juego->personaje.posicion.col = 0;
                    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;
                    juego->personaje.posicion.col = juego->personaje.posicion.col + 1;
            }
            juego->personaje.ultimo_movimiento = IZQUIERDA;
            juego->personaje.posicion.col = juego->personaje.posicion.col - 1;
            return -1;
        } else if(jugada == DERECHA && juego->personaje.posicion.col + 1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col >= 0 && terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col +1] == obstaculo){
            if(obstaculo == ARBOL){
                if(juego->personaje.tipo == PARDO_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 0.5;
                } else {
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 1;
                }
            } else if(obstaculo == PIEDRA){
                if(juego->personaje.tipo != POLAR_OSO){
                    juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + 2;
                }
            } else if(obstaculo == KOALA){
                    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
                    juego->personaje.posicion.col = 0;
                    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;
                    juego->personaje.posicion.col = juego->personaje.posicion.col - 1;
            }
            juego->personaje.ultimo_movimiento = DERECHA;
            juego->personaje.posicion.col = juego->personaje.posicion.col + 1;
            return -1;
        }
        return 0;
    } else {
        return 0;
    }
}

int chocar_herramienta(juego_t* juego,char jugada,char herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    int posicion_pila = 0;
    int posicion_vela = 0;
    int posicion_bengala = 0;

    for(int i = 0; i < juego->cantidad_herramientas; i++){
        if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil -1 && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
            posicion_pila = i;
        }
    }
   
    if(es_jugada_valida(jugada) == true){
        if(jugada == ARRIBA && juego->personaje.posicion.fil -1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil > 0 && terreno[juego->personaje.posicion.fil -1][juego->personaje.posicion.col] == herramienta){
            if(herramienta == PILA){
                juego->personaje.mochila[0].tipo = PILA;
                juego->personaje.mochila[0].movimientos_restantes = juego->personaje.mochila[juego->personaje.cantidad_elementos].movimientos_restantes + 5;
                terreno[juego->personaje.posicion.fil -1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil -1 && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
                        posicion_pila = i;
                    }
                }
                juego->herramientas[posicion_pila].tipo = VACIO;
                juego->personaje.posicion.fil = juego->personaje.posicion.fil - 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == VELA){
                juego->personaje.mochila[1].tipo = VELA;
                juego->personaje.mochila[1].movimientos_restantes = juego->personaje.mochila[1].movimientos_restantes + 5;
                terreno[juego->personaje.posicion.fil -1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil -1 && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
                        posicion_vela = i;
                    }
                }
                juego->herramientas[posicion_vela].tipo = VACIO;
                juego->personaje.posicion.fil = juego->personaje.posicion.fil - 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == BENGALA){
                juego->personaje.mochila[2].tipo = BENGALA;
                juego->personaje.mochila[2].movimientos_restantes = juego->personaje.mochila[2].movimientos_restantes + 3;
                terreno[juego->personaje.posicion.fil -1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil -1 && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
                            posicion_bengala = i;
                    }
                }
                juego->herramientas[posicion_bengala].tipo = VACIO;
                juego->personaje.posicion.fil = juego->personaje.posicion.fil - 1;
                juego->personaje.cantidad_elementos++;
            }
            juego->personaje.ultimo_movimiento = ARRIBA;
            return -1;
        } else if(jugada == ABAJO && juego->personaje.posicion.fil +1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil >= 0 && terreno[juego->personaje.posicion.fil +1][juego->personaje.posicion.col] == herramienta){
            if(herramienta == PILA){
                juego->personaje.mochila[0].tipo = PILA;
                juego->personaje.mochila[0].movimientos_restantes = juego->personaje.mochila[0].movimientos_restantes + 5;
                terreno[juego->personaje.posicion.fil +1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil +1 && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
                            posicion_pila = i;
                    }
                }
                juego->herramientas[posicion_pila].tipo = VACIO;
                juego->personaje.posicion.fil = juego->personaje.posicion.fil + 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == VELA){
                juego->personaje.mochila[1].tipo = VELA;
                juego->personaje.mochila[1].movimientos_restantes = juego->personaje.mochila[1].movimientos_restantes + 5;
                terreno[juego->personaje.posicion.fil +1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil +1 && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
                        posicion_vela = i;
                    }
                }
                juego->herramientas[posicion_vela].tipo = VACIO;
                juego->personaje.posicion.fil = juego->personaje.posicion.fil + 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == BENGALA){
                juego->personaje.mochila[2].tipo = BENGALA;
                juego->personaje.mochila[2].movimientos_restantes = juego->personaje.mochila[2].movimientos_restantes + 3;
                terreno[juego->personaje.posicion.fil +1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil +1 && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
                        posicion_bengala = i;
                    }
                }
                juego->herramientas[posicion_bengala].tipo = VACIO;
                juego->personaje.posicion.fil = juego->personaje.posicion.fil + 1;
                juego->personaje.cantidad_elementos++;
            }
            juego->personaje.ultimo_movimiento = ABAJO;
            return -1;
        }else if(jugada == IZQUIERDA && juego->personaje.posicion.col -1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col > 0 && terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col -1 ] == herramienta){
        if(herramienta == PILA){
                juego->personaje.mochila[0].tipo = PILA;
                juego->personaje.mochila[0].movimientos_restantes = juego->personaje.mochila[0].movimientos_restantes + 5;
                terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col-1] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil && juego->herramientas[i].posicion.col== juego->personaje.posicion.col -1){
                            posicion_pila = i;
                    }
                }
                juego->herramientas[posicion_pila].tipo = VACIO;
                juego->personaje.posicion.col = juego->personaje.posicion.col - 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == VELA){
                juego->personaje.mochila[1].tipo = VELA;
                juego->personaje.mochila[1].movimientos_restantes = juego->personaje.mochila[1].movimientos_restantes + 5;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil && juego->herramientas[i].posicion.col == juego->personaje.posicion.col -1){
                            posicion_vela = i;
                    }
                }
                juego->herramientas[posicion_vela].tipo = VACIO;
                juego->personaje.posicion.col = juego->personaje.posicion.col - 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == BENGALA){
                juego->personaje.mochila[2].tipo = BENGALA;
                juego->personaje.mochila[2].movimientos_restantes = juego->personaje.mochila[2].movimientos_restantes + 3;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil && juego->herramientas[i].posicion.col == juego->personaje.posicion.col -1){
                            posicion_bengala = i;
                    }
                }
                juego->herramientas[posicion_bengala].tipo = VACIO;
                juego->personaje.posicion.col = juego->personaje.posicion.col - 1;
                juego->personaje.cantidad_elementos++;
            }
            juego->personaje.ultimo_movimiento = IZQUIERDA;
            return -1;
        } else if(jugada == DERECHA && juego->personaje.posicion.col + 1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col >= 0 && terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col +1] == herramienta){
            if(herramienta == PILA){
                juego->personaje.mochila[0].tipo = PILA;
                juego->personaje.mochila[0].movimientos_restantes = juego->personaje.mochila[0].movimientos_restantes + 5;
                terreno[juego->personaje.posicion.fil -1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil && juego->herramientas[i].posicion.col == juego->personaje.posicion.col+1){
                        posicion_pila = i;
                    }
                }
                juego->herramientas[posicion_pila].tipo = VACIO;
                juego->personaje.posicion.col = juego->personaje.posicion.col + 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == VELA){
                juego->personaje.mochila[1].tipo = VELA;
                juego->personaje.mochila[1].movimientos_restantes = juego->personaje.mochila[1].movimientos_restantes + 5;
                terreno[juego->personaje.posicion.fil -1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil && juego->herramientas[i].posicion.col == juego->personaje.posicion.col+1){
                        posicion_vela = i;
                    }
                }
                juego->herramientas[posicion_vela].tipo = VACIO;
                juego->personaje.posicion.col = juego->personaje.posicion.col + 1;
                juego->personaje.cantidad_elementos++;
            } else if(herramienta == BENGALA){
                juego->personaje.mochila[2].tipo = BENGALA;
                juego->personaje.mochila[2].movimientos_restantes = juego->personaje.mochila[2].movimientos_restantes + 3;
                terreno[juego->personaje.posicion.fil -1 ][juego->personaje.posicion.col] = VACIO;
                for(int i = 0; i < juego->cantidad_herramientas; i++){
                    if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil && juego->herramientas[i].posicion.col == juego->personaje.posicion.col+1){
                        posicion_bengala = i;
                    }
                }
                juego->herramientas[posicion_bengala].tipo = VACIO;
                juego->personaje.posicion.col = juego->personaje.posicion.col + 1;
                juego->personaje.cantidad_elementos++;
            }
            juego->personaje.ultimo_movimiento = DERECHA;
            return -1;
        }
        return 0;
    } else {
        return 0;
    }
}

void mover_jugador(juego_t* juego, char jugada, char elemento_ultimo_movimiento,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(es_jugada_valida(jugada) == true){
        if(jugada == ARRIBA && juego->personaje.posicion.fil -1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil > 0 && (terreno[juego->personaje.posicion.fil -1][juego->personaje.posicion.col] == VACIO || terreno[juego->personaje.posicion.fil -1][juego->personaje.posicion.col] == CHLOE)){
            juego->personaje.posicion.fil = juego->personaje.posicion.fil - 1;
            juego->personaje.ultimo_movimiento = ARRIBA;
        } else if(jugada == ABAJO && juego->personaje.posicion.fil +1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil >= 0 && (terreno[juego->personaje.posicion.fil +1][juego->personaje.posicion.col] == VACIO || terreno[juego->personaje.posicion.fil +1][juego->personaje.posicion.col] == CHLOE)){
            juego->personaje.posicion.fil = juego->personaje.posicion.fil + 1;
            juego->personaje.ultimo_movimiento = ABAJO;
        }else if(jugada == IZQUIERDA && juego->personaje.posicion.col -1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col > 0 && (terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col -1 ] == VACIO || terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col -1 ] == CHLOE)){
            juego->personaje.posicion.col = juego->personaje.posicion.col - 1;
            juego->personaje.ultimo_movimiento = IZQUIERDA;
        } else if(jugada == DERECHA && juego->personaje.posicion.col + 1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col >= 0 && (terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col +1] == VACIO || terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col +1] == CHLOE)){
            juego->personaje.posicion.col = juego->personaje.posicion.col + 1;
            juego->personaje.ultimo_movimiento = DERECHA;
        } else {
            if(chocar_obstaculo(juego,jugada,ARBOL,terreno) == 0){
                if(chocar_obstaculo(juego,jugada,PIEDRA,terreno) == 0){
                    if(chocar_obstaculo(juego,jugada,KOALA,terreno) == 0){
                        if(chocar_herramienta(juego,jugada,PILA,terreno) == 0){
                            if(chocar_herramienta(juego,jugada,VELA,terreno) == 0){
                                if(chocar_herramienta(juego,jugada,BENGALA,terreno) == 0){
                                    printf("No podes hacer eso\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void encender_apagar_herramienta(juego_t* juego,char herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    int generar_nuevo_koala = 0;

    if(herramienta == PILA){
        if(juego->personaje.elemento_en_uso == -1 && juego->personaje.mochila[0].movimientos_restantes > 0){
            juego->personaje.elemento_en_uso = 0;

            
                while(generar_nuevo_koala == (generar_nuevo_koala + 1)){

                coordenada_t aux;
                aux.fil = rand() % MAX_TERRENO_FILA;
                aux.col = rand() % MAX_TERRENO_COLUMNA;
                if(terreno[aux.fil][aux.col] == VACIO){
                    juego->obstaculos[juego->cantidad_obstaculos].tipo = KOALA;
                    juego->obstaculos[juego->cantidad_obstaculos].visible = false;
                    juego->obstaculos[juego->cantidad_obstaculos].posicion.fil = aux.fil;
                    juego->obstaculos[juego->cantidad_obstaculos].posicion.col = aux.col;
                    terreno[aux.fil][aux.col] = KOALA;
                    juego->cantidad_obstaculos++;
                    generar_nuevo_koala++;
                }
            }
        }else if(juego->personaje.elemento_en_uso == 0){
            juego->personaje.elemento_en_uso = -1;
            juego->personaje.mochila[0].movimientos_restantes = juego->personaje.mochila[0].movimientos_restantes -1;
        }else if(juego->personaje.mochila[0].movimientos_restantes <= 0){
            if(juego->personaje.elemento_en_uso == 0){
                juego->personaje.elemento_en_uso = -1;
                printf("No te queda carga de la linterna");
            }
        }
    }else if(herramienta == VELA){
        if(juego->personaje.elemento_en_uso == -1 && juego->personaje.mochila[1].movimientos_restantes > 0){
            juego->personaje.elemento_en_uso = 0;
        } else if(juego->personaje.elemento_en_uso == 0){
            juego->personaje.elemento_en_uso = -1;
            juego->personaje.mochila[1].movimientos_restantes = juego->personaje.mochila[1].movimientos_restantes -1;
        } else if(juego->personaje.mochila[1].movimientos_restantes <= 0){
            if(juego->personaje.elemento_en_uso == 0 ){
                juego->personaje.elemento_en_uso = -1;
                printf("No te queda carga de la vela");
            }
        }
    }else if(herramienta == BENGALA){
        if(juego->personaje.elemento_en_uso == -1 && juego->personaje.mochila[2].movimientos_restantes > 0){
            juego->personaje.elemento_en_uso = 0;
        } else if(juego->personaje.elemento_en_uso == 0){
            juego->personaje.elemento_en_uso = -1;
            juego->personaje.mochila[2].movimientos_restantes = juego->personaje.mochila[2].movimientos_restantes -1;
        } else if(juego->personaje.mochila[2].movimientos_restantes <= 0){
            if(juego->personaje.elemento_en_uso == 0){
                juego->personaje.elemento_en_uso = -1;
                printf("No te queda carga de la bengala");
            }
        }
    }

}

void utilizar_herramienta(juego_t* juego,char jugada, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    char herramienta;

    if(es_jugada_valida(jugada) == true){
        if(jugada == LINTERNA){
            herramienta = PILA;
            juego->personaje.ultimo_movimiento = LINTERNA;
            encender_apagar_herramienta(juego,herramienta,terreno);
        } else if(jugada == VELA){
            herramienta = VELA;
            juego->personaje.ultimo_movimiento = VELA;
            encender_apagar_herramienta(juego,herramienta,terreno);
        } else if(jugada == BENGALA){
            herramienta = BENGALA;
            juego->personaje.ultimo_movimiento = BENGALA;
            encender_apagar_herramienta(juego,herramienta,terreno);
        }  else if(jugada == VER_TIEMPO){
            juego->personaje.ultimo_movimiento = VER_TIEMPO;
        }
    }
}

void realizar_jugada(juego_t* juego, char jugada){

    if(juego->personaje.tipo == POLAR_OSO && juego->personaje.tiempo_perdido >= 30){
        juego->chloe_visible = true;
    }

    juego->personaje.cantidad_elementos = 0;

    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];

    char elemento_ultimo_movimiento = VACIO;
    matriz_ficticia(juego, terreno);

    mover_jugador(juego,jugada,elemento_ultimo_movimiento,terreno);
    utilizar_herramienta(juego,jugada,terreno);

}

void mostrar_juego(juego_t juego){


    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];

    for(int i=0; i < MAX_TERRENO_FILA; i++){
        for(int j=0; j < MAX_TERRENO_COLUMNA; j++){
            terreno[i][j] = VACIO;  
        }
    }

    terreno[juego.amiga_chloe.fil][juego.amiga_chloe.col] = CHLOE;

    for(int i = 0; i < juego.cantidad_obstaculos; i++){
        terreno[juego.obstaculos[i].posicion.fil][juego.obstaculos[i].posicion.col] = juego.obstaculos[i].tipo;
    }

    for(int i = 0; i < juego.cantidad_herramientas; i++){
        terreno[juego.herramientas[i].posicion.fil][juego.herramientas[i].posicion.col] = juego.herramientas[i].tipo;
    }

    terreno[juego.personaje.posicion.fil][juego.personaje.posicion.col] = juego.personaje.tipo;
    
    for(int i = 0; i < MAX_TERRENO_FILA; i++){
        for(int j = 0; j < MAX_TERRENO_COLUMNA;j++){
            if(juego.personaje.tipo == 'G'){
                printf(" %c", terreno[i][j]);
            }else if(juego.chloe_visible == false && juego.herramientas->visible == false && juego.obstaculos->visible == false){
                if(terreno[i][j] != juego.personaje.tipo){
                    terreno[i][j] = VACIO;
                }
                printf(" %c",terreno[i][j]);
            } else {
                if(terreno[i][j] != juego.personaje.tipo && terreno[i][j] != CHLOE){
                    terreno[i][j] = VACIO;
                }
                printf(" %c",terreno[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n");

    if(juego.personaje.ultimo_movimiento == VER_TIEMPO){
        printf("Tiempo transcurrido: %i segundos\n", (int)tiempo_actual());
    }
}

