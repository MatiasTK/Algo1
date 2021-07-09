#include "osos_contra_reloj.h"
#include "test_de_personalidad.h"
#include "utiles.h"
#include <stdbool.h>

#define MAX_TERRENO_FILA 20
#define MAX_TERRENO_COLUMNA 30

#define MAX_ARBOLES 350
#define MAX_PIEDRAS 80

#define MAX_PILAS 30
#define MAX_VELAS 30
#define MAX_BENGALAS 10

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

const int JUGANDO = 0;
const int TERMINADO = -1;

const int MOVIMIENTOS_LINTERNA_INICIAL = 10;
const int MOVIMIENTOS_VELA_INICIAL = 5;
const int MOVIMIENTOS_BENGALA_INICIAL = 3;

const int CANTIDAD_LINTERNA_INICIAL = 1;
const int CANTIDAD_VELA_INICIAL = 4;
const int CANTIDAD_BENGALA_INICIAL = 0;

const int AGARRAR_PILA = 5;
const int AGARRAR_VELA = 5;
const int AGARRAR_BENGALA = 3;

const double CHOCAR_ARBOL = 1.0;
const double CHOCAR_ARBOL_PARDO = 0.5;
const double CHOCAR_PIEDRA = 2.0;

const int HERRAMIENTA_APAGADA = -1;

void inicializar_obstaculos(juego_t* juego,int maximo_obstaculo,char tipo_obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int cantidad_inicializada = juego->cantidad_obstaculos;

    while(juego->cantidad_obstaculos < (maximo_obstaculo + cantidad_inicializada)){
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

void inicializar_herramientas(juego_t* juego,int maximo_herramienta,char tipo_herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int cantidad_inicializada = juego->cantidad_herramientas;
    
    while(juego->cantidad_herramientas < (maximo_herramienta + cantidad_inicializada)){
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

void inicializar_mochila(juego_t* juego,char tipo_herramienta){
    int movimientos_iniciales = 0;
    int cantidades_iniciales = 0;
    int cantidad_elementos_actual = juego->personaje.cantidad_elementos;

    if(tipo_herramienta == LINTERNA){
        cantidades_iniciales = CANTIDAD_LINTERNA_INICIAL;
        if(juego->personaje.tipo == PARDO_OSO){
            movimientos_iniciales = MOVIMIENTOS_LINTERNA_INICIAL + 5;
        }else{
            movimientos_iniciales = MOVIMIENTOS_LINTERNA_INICIAL;
        }
    }else if(tipo_herramienta == VELA){
        movimientos_iniciales = MOVIMIENTOS_VELA_INICIAL;
        if(juego->personaje.tipo == POLAR_OSO){
            cantidades_iniciales = CANTIDAD_VELA_INICIAL + 2;
        }else{
            cantidades_iniciales = CANTIDAD_VELA_INICIAL;
        }
    }else if(tipo_herramienta == BENGALA){
        movimientos_iniciales = MOVIMIENTOS_BENGALA_INICIAL;
        if(juego->personaje.tipo == PANDA_OSO){
            cantidades_iniciales = CANTIDAD_BENGALA_INICIAL + 2;
        }else{
            cantidades_iniciales = CANTIDAD_BENGALA_INICIAL;
        }
    }

    while(juego->personaje.cantidad_elementos < (cantidades_iniciales + cantidad_elementos_actual)){
        juego->personaje.mochila[juego->personaje.cantidad_elementos].tipo = tipo_herramienta;
        juego->personaje.mochila[juego->personaje.cantidad_elementos].movimientos_restantes = movimientos_iniciales;
        juego->personaje.cantidad_elementos++;
    }

}

void inicializar_juego(juego_t* juego , char tipo_personaje){
    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];

    for(int i=0; i < MAX_TERRENO_FILA; i++){
        for(int j=0; j < MAX_TERRENO_COLUMNA; j++){
            terreno[i][j] = VACIO;  
        }
    }

    juego->personaje.tipo = tipo_personaje;
    juego->cantidad_herramientas = 0;
    juego->cantidad_obstaculos = 0;
    juego->personaje.tiempo_perdido = 0;
    juego->personaje.elemento_en_uso = HERRAMIENTA_APAGADA;
    juego->personaje.cantidad_elementos = 0;

    juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
    juego->personaje.posicion.col = 0;
    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;

    juego->chloe_visible = false;

    bool existe_chloe = false;

    while(existe_chloe == false){
        juego->amiga_chloe.fil = rand() % MAX_TERRENO_FILA;
        juego->amiga_chloe.col = rand() % MAX_TERRENO_COLUMNA;
        if(terreno[juego->amiga_chloe.fil][juego->amiga_chloe.col] == VACIO){
            terreno[juego->amiga_chloe.fil][juego->amiga_chloe.col] = CHLOE;
            existe_chloe = true;
        }
    }

    inicializar_obstaculos(juego,MAX_ARBOLES,ARBOL,terreno);
    inicializar_obstaculos(juego,MAX_PIEDRAS,PIEDRA,terreno);
    inicializar_obstaculos(juego,1,KOALA,terreno);

    inicializar_herramientas(juego,MAX_PILAS,PILA,terreno);
    inicializar_herramientas(juego,MAX_VELAS,VELA,terreno);
    inicializar_herramientas(juego,MAX_BENGALAS,BENGALA,terreno);

    inicializar_mochila(juego,LINTERNA);
    inicializar_mochila(juego,VELA);
    inicializar_mochila(juego,BENGALA);
   
}   

bool es_jugada_valida(char jugada){
    return(jugada == ARRIBA || jugada == ABAJO || jugada == IZQUIERDA || jugada == DERECHA || jugada == LINTERNA || jugada == VELA || jugada == BENGALA || jugada == VER_TIEMPO);
}

int estado_juego(juego_t juego){
    if(juego.personaje.posicion.fil == juego.amiga_chloe.fil && juego.personaje.posicion.col == juego.amiga_chloe.col){
        return TERMINADO;
    } else {
        return JUGANDO;
    }
}

void recrear_matriz(juego_t* juego, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
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

void aniadir_herramienta_mochila(juego_t* juego, char herramienta){
    if(herramienta == PILA){
        for(int i = 0; i < juego->personaje.cantidad_elementos; i++){
            if(juego->personaje.mochila[i].tipo == LINTERNA){
                juego->personaje.mochila[i].movimientos_restantes = juego->personaje.mochila[i].movimientos_restantes + AGARRAR_PILA;
            }
        }
    }else if(herramienta == VELA){
        juego->personaje.mochila[juego->personaje.cantidad_elementos].tipo = VELA;
        juego->personaje.mochila[juego->personaje.cantidad_elementos].movimientos_restantes = AGARRAR_VELA;
        juego->personaje.cantidad_elementos++;
    }else if(herramienta == BENGALA){
        juego->personaje.mochila[juego->personaje.cantidad_elementos].tipo = BENGALA;
        juego->personaje.mochila[juego->personaje.cantidad_elementos].movimientos_restantes = AGARRAR_BENGALA;
        juego->personaje.cantidad_elementos++;
    }
}

bool hay_herramienta_encendida(juego_t* juego){
    if(juego->personaje.elemento_en_uso != HERRAMIENTA_APAGADA){
        return true;
    }
    return false;
}

void moverse_herramienta_encendida(juego_t* juego){
    if(juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes > 1){
        juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes = juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes -1;
    }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes == 1){
        juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes = juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes - 1;
        if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo != LINTERNA){
        juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo = VACIO;
        }
        juego->personaje.elemento_en_uso = HERRAMIENTA_APAGADA;
    }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes <= 0){
        if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo != LINTERNA){
        juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo = VACIO;
        }
        juego->personaje.elemento_en_uso = HERRAMIENTA_APAGADA;
    }
}

bool chequear_movimiento(juego_t* juego,char jugada,char elemento,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(jugada == ARRIBA){   
        if(juego->personaje.posicion.fil -1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil-1 >= 0 && terreno[juego->personaje.posicion.fil - 1][juego->personaje.posicion.col] == elemento){
            return true;
        }
    }else if(jugada == ABAJO){
        if(juego->personaje.posicion.fil +1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil+1 >= 0 && terreno[juego->personaje.posicion.fil +1][juego->personaje.posicion.col] == elemento){
            return true;
        }
    }else if(jugada == IZQUIERDA){
        if(juego->personaje.posicion.col -1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col-1 >= 0 && terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col -1] == elemento){
            return true;
        }
    }else if(jugada == DERECHA){
        if(jugada == DERECHA && juego->personaje.posicion.col + 1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col+1 >= 0 && terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col +1] == elemento){
            return true;
        }
    }
    return false;
}

void consecuencia_obstaculo(juego_t* juego, char obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(obstaculo == ARBOL){
            if(juego->personaje.tipo == PARDO_OSO){
                juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + CHOCAR_ARBOL_PARDO;
            } else {
                juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + CHOCAR_ARBOL;
            }
    } else if(obstaculo == PIEDRA){
        if(juego->personaje.tipo != POLAR_OSO){
            juego->personaje.tiempo_perdido = juego->personaje.tiempo_perdido + CHOCAR_PIEDRA;
        }
    } else if(obstaculo == KOALA){
            juego->personaje.posicion.col = 0;
            juego->personaje.posicion.fil = rand() % MAX_TERRENO_FILA;
            terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = juego->personaje.tipo;
    }
}

void mover_sobre_elemento(juego_t* juego, char jugada){
    if(jugada == ARRIBA){
        juego->personaje.ultimo_movimiento = ARRIBA;
        juego->personaje.posicion.fil = juego->personaje.posicion.fil - 1;
    }else if(jugada == ABAJO){
        juego->personaje.ultimo_movimiento = ABAJO;
        juego->personaje.posicion.fil = juego->personaje.posicion.fil + 1;
    }else if(jugada == IZQUIERDA){
        juego->personaje.ultimo_movimiento = IZQUIERDA;
        juego->personaje.posicion.col = juego->personaje.posicion.col - 1;
    }else if(jugada == DERECHA){
        juego->personaje.ultimo_movimiento = DERECHA;
        juego->personaje.posicion.col = juego->personaje.posicion.col + 1;
    }
}

int choco_obstaculo(juego_t* juego,char jugada,char obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(chequear_movimiento(juego,jugada,obstaculo,terreno) == true){
        consecuencia_obstaculo(juego,obstaculo, terreno);
        if(obstaculo != KOALA){
            mover_sobre_elemento(juego,jugada);
        }
        if(hay_herramienta_encendida(juego) == true){
            moverse_herramienta_encendida(juego);
        }
        return -1;
    }
    return 0;
}

void remover_herramienta(juego_t* juego, char jugada, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int posicion_a_remover = 0;

    for(int i = 0; i < juego->cantidad_herramientas; i++){
        if(juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil && juego->herramientas[i].posicion.col == juego->personaje.posicion.col){
            posicion_a_remover = i;
        }
    }
    juego->herramientas[posicion_a_remover].tipo = juego->herramientas[juego->cantidad_herramientas-1].tipo;
    juego->herramientas[posicion_a_remover].posicion.fil = juego->herramientas[juego->cantidad_herramientas-1].posicion.fil;
    juego->herramientas[posicion_a_remover].posicion.col = juego->herramientas[juego->cantidad_herramientas-1].posicion.col;
    juego->cantidad_herramientas--;
    terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col] = VACIO; 

}

int choco_herramienta(juego_t* juego,char jugada,char herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){    
    if(chequear_movimiento(juego,jugada,herramienta,terreno) == true){
        aniadir_herramienta_mochila(juego,herramienta);
        mover_sobre_elemento(juego,jugada);
        remover_herramienta(juego,jugada,terreno);
        if(hay_herramienta_encendida(juego) == true){
            moverse_herramienta_encendida(juego);
        }
        return -1;
    }
    return 0;
}

bool chequear_movimiento_vacio_chloe(juego_t* juego, char jugada,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(jugada == ARRIBA){   
        if(juego->personaje.posicion.fil -1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil >= 0 && (terreno[juego->personaje.posicion.fil -1][juego->personaje.posicion.col] == VACIO || terreno[juego->personaje.posicion.fil -1][juego->personaje.posicion.col] == CHLOE)){
            return true;
        }
    }else if(jugada == ABAJO){
        if(juego->personaje.posicion.fil +1 < MAX_TERRENO_FILA && juego->personaje.posicion.fil >= 0 && (terreno[juego->personaje.posicion.fil +1][juego->personaje.posicion.col] == VACIO || terreno[juego->personaje.posicion.fil +1][juego->personaje.posicion.col] == CHLOE)){
            return true;
        }
    }else if(jugada == IZQUIERDA){
        if(juego->personaje.posicion.col -1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col > 0 && (terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col -1 ] == VACIO || terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col -1 ] == CHLOE)){
            return true;
        }
    }else if(jugada == DERECHA){
        if(juego->personaje.posicion.col + 1 < MAX_TERRENO_COLUMNA && juego->personaje.posicion.col >= 0 && (terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col +1] == VACIO || terreno[juego->personaje.posicion.fil][juego->personaje.posicion.col +1] == CHLOE)){
            return true;
        }
    }
    return false;
}

void mover_jugador(juego_t* juego, char jugada,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(chequear_movimiento_vacio_chloe(juego,jugada,terreno) == true){
        if(hay_herramienta_encendida(juego) == true){
            moverse_herramienta_encendida(juego);
        }
        mover_sobre_elemento(juego,jugada);
    } else {
        if(choco_obstaculo(juego,jugada,ARBOL,terreno) == 0){
            if(choco_obstaculo(juego,jugada,PIEDRA,terreno) == 0){
                if(choco_obstaculo(juego,jugada,KOALA,terreno) == 0){
                    if(choco_herramienta(juego,jugada,PILA,terreno) == 0){
                        if(choco_herramienta(juego,jugada,VELA,terreno) == 0){
                            if(choco_herramienta(juego,jugada,BENGALA,terreno) == 0){
                                printf("No podes hacer eso\n");
                            }
                        }
                    }
                }
            }
        }
    }
}

void generar_koala(juego_t* juego,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    int maximo_koalas = juego->cantidad_obstaculos + 1;

    while(juego->cantidad_obstaculos < maximo_koalas){
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
        }
    }
}

/*
*
* POST: Devuelve la posicion de la herramienta si la encuentra, sino devuelve -1;
*/
int encontrar_herramienta(juego_t* juego, char herramienta){
    int posicion_herramienta = -1;
    bool encontre = false;

    int i = 0;
    while(i < juego->personaje.cantidad_elementos && encontre == false){
        if(juego->personaje.mochila[i].tipo == herramienta){
            posicion_herramienta = i;
            encontre = true;
        }
        i++; 
    }

    return posicion_herramienta;
}

void cambiar_herramienta(juego_t* juego, char jugada,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == LINTERNA){
        if(jugada == VELA || jugada == BENGALA){
            if(encontrar_herramienta(juego,jugada) >= 0){
                juego->personaje.elemento_en_uso = encontrar_herramienta(juego,jugada);
            }
            juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes--;
        }
    }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == VELA){
        if(jugada == LINTERNA || jugada == BENGALA){
            if(encontrar_herramienta(juego,jugada) >= 0){
                juego->personaje.elemento_en_uso = encontrar_herramienta(juego,jugada);
            }
            juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes--;
            if(jugada == LINTERNA){
                generar_koala(juego,terreno);           
            }
        }
    }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == BENGALA){
        if(jugada == LINTERNA || jugada == VELA){
            juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes--;
        }
    }
}

void encender_apagar_herramienta(juego_t* juego, char herramienta, int posicion_herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(juego->personaje.elemento_en_uso == HERRAMIENTA_APAGADA && juego->personaje.mochila[posicion_herramienta].movimientos_restantes > 0){
        juego->personaje.elemento_en_uso = posicion_herramienta;
        if(herramienta == LINTERNA){
            generar_koala(juego,terreno);
        }
        juego->personaje.mochila[posicion_herramienta].movimientos_restantes = juego->personaje.mochila[posicion_herramienta].movimientos_restantes - 1;
    }else if(juego->personaje.mochila[posicion_herramienta].movimientos_restantes <= 0){
        juego->personaje.elemento_en_uso = HERRAMIENTA_APAGADA;
        if(herramienta != LINTERNA){
            juego->personaje.mochila[posicion_herramienta].tipo = VACIO;
        }
        printf("Te agotaste las cargas de esa herramienta!\n");
    }else if(juego->personaje.elemento_en_uso == posicion_herramienta){
        if(herramienta == BENGALA){
            juego->personaje.mochila[posicion_herramienta].movimientos_restantes = juego->personaje.mochila[posicion_herramienta].movimientos_restantes - 1;
        }else{
            juego->personaje.elemento_en_uso = HERRAMIENTA_APAGADA;
        }
    }

    if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == BENGALA && juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes <= 0){
        juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo = VACIO;
        juego->personaje.elemento_en_uso = HERRAMIENTA_APAGADA;
    }

}

void oscurecer_terreno(juego_t* juego){
    for(int i = 0; i < juego->cantidad_herramientas; i++){
        juego->herramientas[i].visible = false;
    }
    for(int j = 0; j < juego->cantidad_obstaculos; j++){
        juego->obstaculos[j].visible = false;
    }
    if(juego->personaje.tipo == PANDA_OSO && juego->personaje.tiempo_perdido < 30){
        juego->chloe_visible = false;
    }else if(juego->personaje.tipo == PARDO_OSO || juego->personaje.tipo == POLAR_OSO){
        juego->chloe_visible = false;
    }
}

void iluminar_terreno_linterna(juego_t* juego, int posicion_jugador, int movimiento){
    if(movimiento == ARRIBA || movimiento == ABAJO){
        for(int i = 0; i < juego->cantidad_herramientas; i++){
                if(juego->herramientas[i].posicion.col == juego->personaje.posicion.col && juego->herramientas[i].posicion.fil == posicion_jugador){
                    juego->herramientas[i].visible = true;
                }
            }
        for(int j = 0; j < juego->cantidad_obstaculos; j++){
            if(juego->obstaculos[j].posicion.col == juego->personaje.posicion.col && juego->obstaculos[j].posicion.fil == posicion_jugador){
                juego->obstaculos[j].visible = true;
            }
        }
        if(juego->amiga_chloe.col == juego->personaje.posicion.col && juego->amiga_chloe.fil == posicion_jugador){
            juego->chloe_visible = true;
        }
    }else if(movimiento == IZQUIERDA || movimiento == DERECHA){
       for(int i = 0; i < juego->cantidad_herramientas; i++){
                if(juego->herramientas[i].posicion.col == posicion_jugador && juego->herramientas[i].posicion.fil == juego->personaje.posicion.fil){
                    juego->herramientas[i].visible = true;
                }
            }
        for(int j = 0; j < juego->cantidad_obstaculos; j++){
            if(juego->obstaculos[j].posicion.col == posicion_jugador && juego->obstaculos[j].posicion.fil == juego->personaje.posicion.fil){
                juego->obstaculos[j].visible = true;
            }
        }
        if(juego->amiga_chloe.col == posicion_jugador && juego->amiga_chloe.fil == juego->personaje.posicion.fil){
            juego->chloe_visible = true;
        } 
    }
}

void iluminar_linterna(juego_t* juego){
    if(juego->personaje.ultimo_movimiento == ARRIBA){
        int posicion_jugador = juego->personaje.posicion.fil;
        while(posicion_jugador >= 0){
            iluminar_terreno_linterna(juego,posicion_jugador,ARRIBA);
            posicion_jugador--;
        }
    }else if(juego->personaje.ultimo_movimiento == ABAJO){
        int posicion_jugador = juego->personaje.posicion.fil;
        while(posicion_jugador <= MAX_TERRENO_FILA){
            iluminar_terreno_linterna(juego,posicion_jugador,ABAJO);
            posicion_jugador++;
        }
    }else if(juego->personaje.ultimo_movimiento == IZQUIERDA){
        int posicion_jugador = juego->personaje.posicion.col;
        while(posicion_jugador >= 0){
            iluminar_terreno_linterna(juego,posicion_jugador,IZQUIERDA);
            posicion_jugador--;
        }
    }else if(juego->personaje.ultimo_movimiento == DERECHA){
        int posicion_jugador = juego->personaje.posicion.col;
        while(posicion_jugador <= MAX_TERRENO_COLUMNA){
            iluminar_terreno_linterna(juego,posicion_jugador,DERECHA);
            posicion_jugador++;
        } 
    }
}

void iluminar_vela(juego_t* juego){
    int maximo_fila = juego->personaje.posicion.fil + 2;
    int maximo_columna = juego->personaje.posicion.col + 2;

    for(int i = juego->personaje.posicion.fil-1; i < maximo_fila; i++){
        for(int j = juego->personaje.posicion.col-1; j < maximo_columna; j++){
            for(int k = 0; k < juego->cantidad_obstaculos; k++){
                if(juego->obstaculos[k].posicion.fil == i && juego->obstaculos[k].posicion.col == j){
                    juego->obstaculos[k].visible = true;
                }
            }
            for(int k = 0; k < juego->cantidad_herramientas; k++){
                if(juego->herramientas[k].posicion.fil == i && juego->herramientas[k].posicion.col == j){
                    juego->herramientas[k].visible = true;
                }
            }
            if(juego->amiga_chloe.col == j && juego->amiga_chloe.fil == i){
                juego->chloe_visible = true;
            }
        }
    }
}

int distancia_manhattan(int punto1x, int punto1y, int punto2x, int punto2y){
    int resultado;

    resultado = (abs(punto1x - punto2x) + abs(punto1y - punto2y));

    return resultado;
}

void iluminar_bengala(juego_t* juego){
    int bengala_fila = rand() % MAX_TERRENO_FILA;
    int bengala_columna = rand() % MAX_TERRENO_COLUMNA;

    for(int i = 0; i < MAX_TERRENO_FILA; i++){
        for(int j = 0; j < MAX_TERRENO_COLUMNA; j++){
            if(distancia_manhattan(bengala_fila,bengala_columna, i, j) <= 3){
                for(int g = 0; g < juego->cantidad_herramientas; g++){
                    if(juego->herramientas[g].posicion.fil == i && juego->herramientas[g].posicion.col == j){
                        juego->herramientas[g].visible = true;
                    }
                }
                for(int k = 0; k < juego->cantidad_obstaculos; k++){
                    if(juego->obstaculos[k].posicion.fil == i && juego->obstaculos[k].posicion.col == j){
                        juego->obstaculos[k].visible = true;
                    }
                }
                if(juego->amiga_chloe.fil == i && juego->amiga_chloe.col == j){
                    juego->chloe_visible = true;
                }
            }
        }
    }
}

void iluminar_herramienta(juego_t* juego,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    oscurecer_terreno(juego);

    if(hay_herramienta_encendida(juego) == true){
        if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == LINTERNA){
            iluminar_linterna(juego);
        }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == VELA){
            iluminar_vela(juego);
        }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == BENGALA){
            iluminar_bengala(juego);
        }
    } 
}

void utilizar_herramienta(juego_t* juego, char jugada, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int posicion_herramienta = 0;

    if(jugada == LINTERNA){
        posicion_herramienta = encontrar_herramienta(juego,LINTERNA);
        if(posicion_herramienta >= 0){
            encender_apagar_herramienta(juego,LINTERNA,posicion_herramienta,terreno);
        }
    }else if(jugada == VELA){;
        posicion_herramienta = encontrar_herramienta(juego,VELA);
        if(posicion_herramienta >= 0){
            encender_apagar_herramienta(juego,VELA,posicion_herramienta,terreno);
        }
    }else if(jugada == BENGALA){
        posicion_herramienta = encontrar_herramienta(juego,BENGALA);
        if(posicion_herramienta >= 0){
            encender_apagar_herramienta(juego,BENGALA,posicion_herramienta,terreno);
        };
    }

    if(hay_herramienta_encendida(juego) == true){
        cambiar_herramienta(juego,jugada,terreno);
    }
}

void panda_chloe_visible(juego_t *juego){
    if(juego->personaje.tipo == PANDA_OSO && juego->personaje.tiempo_perdido >= 30){
        juego->chloe_visible = true;
    } 
}

void realizar_jugada(juego_t* juego, char jugada){
    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];

    recrear_matriz(juego,terreno);
    utilizar_herramienta(juego,jugada,terreno);
    mover_jugador(juego,jugada,terreno);
    iluminar_herramienta(juego,terreno);
    panda_chloe_visible(juego);
}

void mostrar_juego(juego_t juego){

    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];
    
    for(int i = 0; i < MAX_TERRENO_FILA; i++){
        for(int j = 0; j < MAX_TERRENO_COLUMNA;j++){
            if(juego.personaje.tipo == 'Z'){
                terreno[i][j] = VACIO;

                for(int x = 0; x < juego.cantidad_herramientas; x++){
                    terreno[juego.herramientas[x].posicion.fil][juego.herramientas[x].posicion.col] = juego.herramientas[x].tipo;
                }
                for(int y = 0; y < juego.cantidad_obstaculos; y++){
                    terreno[juego.obstaculos[y].posicion.fil][juego.obstaculos[y].posicion.col] = juego.obstaculos[y].tipo;
                }
                terreno[juego.amiga_chloe.fil][juego.amiga_chloe.col] = CHLOE;

                terreno[juego.personaje.posicion.fil][juego.personaje.posicion.col] = juego.personaje.tipo;
                printf(" %c", terreno[i][j]);
            }else{
                terreno[i][j] = VACIO;

                for(int x = 0; x < juego.cantidad_obstaculos; x++){
                    if(juego.obstaculos[x].visible == true){
                        terreno[juego.obstaculos[x].posicion.fil][juego.obstaculos[x].posicion.col] = juego.obstaculos[x].tipo;
                    }
                }

                for(int y = 0; y < juego.cantidad_herramientas; y++){
                    if(juego.herramientas[y].visible == true){
                        terreno[juego.herramientas[y].posicion.fil][juego.herramientas[y].posicion.col] = juego.herramientas[y].tipo;
                    }
                }

                if(juego.chloe_visible == true){
                    terreno[juego.amiga_chloe.fil][juego.amiga_chloe.col] = CHLOE;
                }

                terreno[juego.personaje.posicion.fil][juego.personaje.posicion.col] = juego.personaje.tipo;
                printf(" %c",terreno[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}