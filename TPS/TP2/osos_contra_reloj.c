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
/*
* PRE: cantidad_obstaculos y maximo_obstaculo deben estar inicializados, elemento_del_mapa_t debe ser un struct valido
* POST: Inicializa los obstaculos en el mapa con su tipo,visibilidad y posicion
*/
void inicializar_obstaculos(int* cantidad_obstaculos,elemento_del_mapa_t obstaculos[MAX_OBSTACULOS],int maximo_obstaculo,char tipo_obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int cantidad_inicializada = (*cantidad_obstaculos);

    while((*cantidad_obstaculos) < (maximo_obstaculo + cantidad_inicializada)){
        coordenada_t aux;
        aux.fil = rand() % MAX_TERRENO_FILA;
        aux.col = rand() % MAX_TERRENO_COLUMNA;
        if(terreno[aux.fil][aux.col] == VACIO){
            obstaculos[(*cantidad_obstaculos)].tipo = tipo_obstaculo;
            obstaculos[(*cantidad_obstaculos)].visible = false;
            obstaculos[(*cantidad_obstaculos)].posicion.fil = aux.fil;
            obstaculos[(*cantidad_obstaculos)].posicion.col = aux.col;
            terreno[aux.fil][aux.col] = tipo_obstaculo;
            (*cantidad_obstaculos)++;
        }
    }
}
/*
* PRE: cantidad_herramientas y maximo_herramienta deben estar inicializados, elemento_del_mapa_t debe ser un struct valido
* POST: Inicializa las herramientas en el mapa con su tipo,visibilidad y posicion
*/
void inicializar_herramientas(int* cantidad_herramientas,elemento_del_mapa_t herramientas[MAX_HERRAMIENTAS],int maximo_herramienta,char tipo_herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int cantidad_inicializada = (*cantidad_herramientas);
    
    while((*cantidad_herramientas) < (maximo_herramienta + cantidad_inicializada)){
        coordenada_t aux;
        aux.fil = rand() % MAX_TERRENO_FILA;
        aux.col = rand() % MAX_TERRENO_COLUMNA;
        if(terreno[aux.fil][aux.col] == VACIO){
            herramientas[(*cantidad_herramientas)].tipo = tipo_herramienta;
            herramientas[(*cantidad_herramientas)].visible = false;
            herramientas[(*cantidad_herramientas)].posicion.fil = aux.fil;
            herramientas[(*cantidad_herramientas)].posicion.col = aux.col;
            terreno[aux.fil][aux.col] = tipo_herramienta;
            (*cantidad_herramientas)++;
        }
    }
}
/*
* PRE: tipo_herramienta debe ser una herramienta valida, personaje_t debe ser un struct valido
* POST: Inicializa los elementos en la mochila dependiendo del tipo de personaje inicial
*/
void inicializar_mochila(personaje_t* personaje,char tipo_herramienta){
    int movimientos_iniciales = 0;
    int cantidades_iniciales = 0;
    int cantidad_elementos_actual = personaje->cantidad_elementos;

    if(tipo_herramienta == LINTERNA){
        cantidades_iniciales = CANTIDAD_LINTERNA_INICIAL;
        if(personaje->tipo == PARDO_OSO){
            movimientos_iniciales = MOVIMIENTOS_LINTERNA_INICIAL + 5;
        }else{
            movimientos_iniciales = MOVIMIENTOS_LINTERNA_INICIAL;
        }
    }else if(tipo_herramienta == VELA){
        movimientos_iniciales = MOVIMIENTOS_VELA_INICIAL;
        if(personaje->tipo == POLAR_OSO){
            cantidades_iniciales = CANTIDAD_VELA_INICIAL + 2;
        }else{
            cantidades_iniciales = CANTIDAD_VELA_INICIAL;
        }
    }else if(tipo_herramienta == BENGALA){
        movimientos_iniciales = MOVIMIENTOS_BENGALA_INICIAL;
        if(personaje->tipo == PANDA_OSO){
            cantidades_iniciales = CANTIDAD_BENGALA_INICIAL + 2;
        }else{
            cantidades_iniciales = CANTIDAD_BENGALA_INICIAL;
        }
    }

    while(personaje->cantidad_elementos < (cantidades_iniciales + cantidad_elementos_actual)){
        personaje->mochila[personaje->cantidad_elementos].tipo = tipo_herramienta;
        personaje->mochila[personaje->cantidad_elementos].movimientos_restantes = movimientos_iniciales;
        personaje->cantidad_elementos++;
    }

}
/*
* PRE: Recibe un juego con su estructura valida
* POST: Inicializa el juego cargando toda la informacion inicial y los datos del personaje
*/
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
    juego->personaje.ultimo_movimiento = DERECHA;

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

    inicializar_obstaculos(&(juego->cantidad_obstaculos),juego->obstaculos,MAX_ARBOLES,ARBOL,terreno);
    inicializar_obstaculos(&(juego->cantidad_obstaculos),juego->obstaculos,MAX_PIEDRAS,PIEDRA,terreno);
    inicializar_obstaculos(&(juego->cantidad_obstaculos),juego->obstaculos,1,KOALA,terreno);

    inicializar_herramientas(&(juego->cantidad_herramientas),juego->herramientas,MAX_PILAS,PILA,terreno);
    inicializar_herramientas(&(juego->cantidad_herramientas),juego->herramientas,MAX_VELAS,VELA,terreno);
    inicializar_herramientas(&(juego->cantidad_herramientas),juego->herramientas,MAX_BENGALAS,BENGALA,terreno);

    inicializar_mochila(&(juego->personaje),LINTERNA);
    inicializar_mochila(&(juego->personaje),VELA);
    inicializar_mochila(&(juego->personaje),BENGALA);
}   
/*
* PRE: Jugada debe estar inicializado
* POST: Devuelve true si la jugada realizada es valida sino devuelve false
*/
bool es_jugada_valida(char jugada){
    return(jugada == ARRIBA || jugada == ABAJO || jugada == IZQUIERDA || jugada == DERECHA || jugada == LINTERNA || jugada == VELA || jugada == BENGALA || jugada == VER_TIEMPO);
}
/*
* PRE: Recibe un juego con todas sus estructuras validas
* POST: Devuelve -1 si el personaje encontro a chloe y el estado es terminado y 0 si el personaje no encontro a chloe y el estado es jugando
*/
int estado_juego(juego_t juego){
    if(juego.personaje.posicion.fil == juego.amiga_chloe.fil && juego.personaje.posicion.col == juego.amiga_chloe.col){
        return TERMINADO;
    } else {
        return JUGANDO;
    }
}
/*
* PRE: Recibe un juego con su estructura valida
* POST: Recrea la matriz para utilizarla en realizar jugada
*/
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
/*
* PRE: herramienta debe ser una herramienta valida, personaje_t debe ser un struct valido
* POST: Añade una herramienta a la mochila con su respectivo tipo y movimiento restante
*/
void aniadir_herramienta_mochila(personaje_t* personaje, char herramienta){
    if(herramienta == PILA){
        for(int i = 0; i < personaje->cantidad_elementos; i++){
            if(personaje->mochila[i].tipo == LINTERNA){
                personaje->mochila[i].movimientos_restantes = personaje->mochila[i].movimientos_restantes + AGARRAR_PILA;
            }
        }
    }else if(herramienta == VELA){
        personaje->mochila[personaje->cantidad_elementos].tipo = VELA;
        personaje->mochila[personaje->cantidad_elementos].movimientos_restantes = AGARRAR_VELA;
        personaje->cantidad_elementos++;
    }else if(herramienta == BENGALA){
        personaje->mochila[personaje->cantidad_elementos].tipo = BENGALA;
        personaje->mochila[personaje->cantidad_elementos].movimientos_restantes = AGARRAR_BENGALA;
        personaje->cantidad_elementos++;
    }
}
/*
* PRE: elemento_en_uso debe ser -1 o la posicion de una herramienta
* POST: Devuelve true si hay una herramienta encendida o false si no hay ninguna encendida
*/
bool hay_herramienta_encendida(int elemento_en_uso){
    if(elemento_en_uso != HERRAMIENTA_APAGADA){
        return true;
    }
    return false;
}
/*
* PRE: elemento_en_uso debe estar inicializado, elemento_mochila_t debe ser un struct valido
* POST: Mueve al jugador en el mapa con una herramienta encendida restandole un movimiento y eliminandola si esta se queda sin movimientos
*/
void moverse_herramienta_encendida(int* elemento_en_uso, elemento_mochila_t mochila[MAX_HERRAMIENTAS]){
    if(mochila[(*elemento_en_uso)].movimientos_restantes > 1){
        mochila[(*elemento_en_uso)].movimientos_restantes = mochila[(*elemento_en_uso)].movimientos_restantes -1;
    }else if(mochila[(*elemento_en_uso)].movimientos_restantes == 1){
        mochila[(*elemento_en_uso)].movimientos_restantes = mochila[(*elemento_en_uso)].movimientos_restantes - 1;
        if(mochila[(*elemento_en_uso)].tipo != LINTERNA){
        mochila[(*elemento_en_uso)].tipo = VACIO;
        }
        (*elemento_en_uso) = HERRAMIENTA_APAGADA;
    }else if(mochila[(*elemento_en_uso)].movimientos_restantes <= 0){
        if(mochila[(*elemento_en_uso)].tipo != LINTERNA){
        mochila[(*elemento_en_uso)].tipo = VACIO;
        }
        (*elemento_en_uso) = HERRAMIENTA_APAGADA;
    }
}
/*
* PRE: Jugada tiene que ser una jugada valida y elemento tiene que ser un obstaculo o herramienta, personaje_t debe ser un struct valido
* POST: Devuelve true si el movimiento que hace el jugador es valido sobre una herramienta o obstaculo
*/
bool chequear_movimiento(personaje_t personaje,char jugada,char elemento,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(jugada == ARRIBA){   
        if(personaje.posicion.fil -1 < MAX_TERRENO_FILA && personaje.posicion.fil-1 >= 0 && terreno[personaje.posicion.fil - 1][personaje.posicion.col] == elemento){
            return true;
        }
    }else if(jugada == ABAJO){
        if(personaje.posicion.fil +1 < MAX_TERRENO_FILA && personaje.posicion.fil+1 >= 0 && terreno[personaje.posicion.fil +1][personaje.posicion.col] == elemento){
            return true;
        }
    }else if(jugada == IZQUIERDA){
        if(personaje.posicion.col -1 < MAX_TERRENO_COLUMNA && personaje.posicion.col-1 >= 0 && terreno[personaje.posicion.fil][personaje.posicion.col -1] == elemento){
            return true;
        }
    }else if(jugada == DERECHA){
        if(jugada == DERECHA && personaje.posicion.col + 1 < MAX_TERRENO_COLUMNA && personaje.posicion.col+1 >= 0 && terreno[personaje.posicion.fil][personaje.posicion.col +1] == elemento){
            return true;
        }
    }
    return false;
}
/*
* PRE: obstaculo debe ser un obstaculo valido, personaje_t debe ser un struct valido
* POST: Aumenta el tiempo perdido si el jugador choca con un obstaculo o lo mueve de lugar si choca con un koala
*/
void consecuencia_obstaculo(personaje_t* personaje, char obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(obstaculo == ARBOL){
        if(personaje->tipo == PARDO_OSO){
            personaje->tiempo_perdido = personaje->tiempo_perdido + CHOCAR_ARBOL_PARDO;
        } else {
            personaje->tiempo_perdido = personaje->tiempo_perdido + CHOCAR_ARBOL;
        }
    } else if(obstaculo == PIEDRA){
        if(personaje->tipo != POLAR_OSO){
            personaje->tiempo_perdido = personaje->tiempo_perdido + CHOCAR_PIEDRA;
        }
    } else if(obstaculo == KOALA){
        personaje->posicion.col = 0;
        personaje->posicion.fil = rand() % MAX_TERRENO_FILA;
        terreno[personaje->posicion.fil][personaje->posicion.col] = personaje->tipo;
    }
}
/*
* PRE: jugada debe ser una jugada valida, personaje_t debe ser un struct valido
* POST: Mueve al jugador a la posicion indicada
*/
void mover_sobre_elemento(personaje_t* personaje, char jugada){
    if(jugada == ARRIBA){
        personaje->ultimo_movimiento = ARRIBA;
        personaje->posicion.fil = personaje->posicion.fil - 1;
    }else if(jugada == ABAJO){
        personaje->ultimo_movimiento = ABAJO;
        personaje->posicion.fil = personaje->posicion.fil + 1;
    }else if(jugada == IZQUIERDA){
        personaje->ultimo_movimiento = IZQUIERDA;
        personaje->posicion.col = personaje->posicion.col - 1;
    }else if(jugada == DERECHA){
        personaje->ultimo_movimiento = DERECHA;
        personaje->posicion.col = personaje->posicion.col + 1;
    }
}
/*
* PRE: jugada debe ser una jugada valida y obstaculo debe ser un obstaculo valido, juego_t debe ser un struct valido
* POST: Si el jugador choca con un obstaculo lo mueve y devuelve -1 o devuelve 0 si no choco contra ningun obstaculo
*/
int choco_obstaculo(juego_t* juego,char jugada,char obstaculo,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(chequear_movimiento(juego->personaje,jugada,obstaculo,terreno) == true){
        consecuencia_obstaculo(&(juego->personaje),obstaculo, terreno);
        if(obstaculo != KOALA){
            mover_sobre_elemento(&(juego->personaje),jugada);
        }
        if(hay_herramienta_encendida(juego->personaje.elemento_en_uso) == true){
            moverse_herramienta_encendida(&(juego->personaje.elemento_en_uso),juego->personaje.mochila);
        }
        return -1;
    }
    return 0;
}
/*
* PRE: cantidad_herramientas debe estar inicializado, jugada debe ser una jugada valida, personaje_t y elemento_del_mapa_t deben ser struct validos
* POST: Remueve una herramienta del mapa si el jugador pasa por encima
*/
void remover_herramienta(elemento_del_mapa_t herramientas[MAX_HERRAMIENTAS],personaje_t personaje,int* cantidad_herramientas, char jugada, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int posicion_a_remover = 0;

    for(int i = 0; i < (*cantidad_herramientas); i++){
        if(herramientas[i].posicion.fil == personaje.posicion.fil && herramientas[i].posicion.col == personaje.posicion.col){
            posicion_a_remover = i;
        }
    }
    herramientas[posicion_a_remover].tipo = herramientas[(*cantidad_herramientas)-1].tipo;
    herramientas[posicion_a_remover].posicion.fil = herramientas[(*cantidad_herramientas)-1].posicion.fil;
    herramientas[posicion_a_remover].posicion.col = herramientas[(*cantidad_herramientas)-1].posicion.col;
    (*cantidad_herramientas)--;
    terreno[personaje.posicion.fil][personaje.posicion.col] = VACIO; 

}
/*
* PRE: jugada debe ser una jugada valida, herramienta debe ser una herramienta valida, juego_t debe ser un struct valido
* POST: Si el jugador choca con una herramienta lo mueve, añade la herramienta a la mochila, la remueve del mapa y devuelve -1, si no choca con una herramienta devuelve 0
*/
int choco_herramienta(juego_t* juego,char jugada,char herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){    
    if(chequear_movimiento(juego->personaje,jugada,herramienta,terreno) == true){
        aniadir_herramienta_mochila(&(juego->personaje),herramienta);
        mover_sobre_elemento(&(juego->personaje),jugada);
        remover_herramienta(juego->herramientas,juego->personaje,&(juego->cantidad_herramientas),jugada,terreno);
        if(hay_herramienta_encendida(juego->personaje.elemento_en_uso) == true){
            moverse_herramienta_encendida(&(juego->personaje.elemento_en_uso),juego->personaje.mochila);
        }
        return -1;
    }
    return 0;
}
/*
* PRE: jugada debe ser una jugada valida, coordenada_t debe ser un struct valido
* POST: Devuelve true si el movimiento que puede hacer el jugador es valido en una posicion vacia o en la que esta chloe
*/
bool chequear_movimiento_vacio_chloe(coordenada_t posicion, char jugada,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(jugada == ARRIBA){   
        if(posicion.fil -1 < MAX_TERRENO_FILA && posicion.fil >= 0 && (terreno[posicion.fil -1][posicion.col] == VACIO || terreno[posicion.fil -1][posicion.col] == CHLOE)){
            return true;
        }
    }else if(jugada == ABAJO){
        if(posicion.fil +1 < MAX_TERRENO_FILA && posicion.fil >= 0 && (terreno[posicion.fil +1][posicion.col] == VACIO || terreno[posicion.fil +1][posicion.col] == CHLOE)){
            return true;
        }
    }else if(jugada == IZQUIERDA){
        if(posicion.col -1 < MAX_TERRENO_COLUMNA && posicion.col > 0 && (terreno[posicion.fil][posicion.col -1 ] == VACIO || terreno[posicion.fil][posicion.col -1 ] == CHLOE)){
            return true;
        }
    }else if(jugada == DERECHA){
        if(posicion.col + 1 < MAX_TERRENO_COLUMNA && posicion.col >= 0 && (terreno[posicion.fil][posicion.col +1] == VACIO || terreno[posicion.fil][posicion.col +1] == CHLOE)){
            return true;
        }
    }
    return false;
}
/*
* PRE: jugada debe ser una jugada valida, juego_t debe ser un struct valido
* POST: Mueve al jugador en el mapa
*/
void mover_jugador(juego_t* juego, char jugada,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(chequear_movimiento_vacio_chloe(juego->personaje.posicion,jugada,terreno) == true){
        if(hay_herramienta_encendida(juego->personaje.elemento_en_uso) == true){
            moverse_herramienta_encendida(&(juego->personaje.elemento_en_uso),juego->personaje.mochila);
        }
        mover_sobre_elemento(&(juego->personaje),jugada);
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
/*
* PRE: cantidad_obstaculos debe estar inicializado, elemento_del_mapa_t debe ser un struct valido
* POST: Genera un koala nuevo en el mapa
*/
void generar_koala(elemento_del_mapa_t obstaculos[MAX_OBSTACULOS],int* cantidad_obstaculos,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    int maximo_koalas = (*cantidad_obstaculos) + 1;

    while((*cantidad_obstaculos) < maximo_koalas){
        coordenada_t aux;
        aux.fil = rand() % MAX_TERRENO_FILA;
        aux.col = rand() % MAX_TERRENO_COLUMNA;
        if(terreno[aux.fil][aux.col] == VACIO){
            obstaculos[(*cantidad_obstaculos)].tipo = KOALA;
            obstaculos[(*cantidad_obstaculos)].visible = false;
            obstaculos[(*cantidad_obstaculos)].posicion.fil = aux.fil;
            obstaculos[(*cantidad_obstaculos)].posicion.col = aux.col;
            terreno[aux.fil][aux.col] = KOALA;
            (*cantidad_obstaculos)++;
        }
    }
}

/*
* PRE: herramienta debe ser una herramienta valida, personaje_t debe ser un struct valido
* POST: Devuelve la posicion de la herramienta si la encuentra, sino devuelve -1;
*/
int encontrar_herramienta(personaje_t personaje, char herramienta){
    int posicion_herramienta = -1;
    bool encontre = false;

    int i = 0;
    while(i < personaje.cantidad_elementos && encontre == false){
        if(personaje.mochila[i].tipo == herramienta){
            if(personaje.mochila[i].movimientos_restantes > 0){
                posicion_herramienta = i;
                encontre = true;
            }
        }
        i++; 
    }

    return posicion_herramienta;
}
/*
* PRE: jugada debe ser una jugada valida, juego_t debe ser un struct valido
* POST: Si la jugada es una herramienta y hay otra activa cambia la herramienta
*/
void cambiar_herramienta(juego_t* juego, char jugada,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    int movimientos_bengala = 0;

    if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == BENGALA){
        juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes--;
        movimientos_bengala = juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes;
    }
    if(movimientos_bengala <= 0){
        if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == LINTERNA){
            if(jugada == VELA || jugada == BENGALA){
                if(encontrar_herramienta(juego->personaje,jugada) >= 0){
                    juego->personaje.elemento_en_uso = encontrar_herramienta(juego->personaje,jugada);
                    juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes--;
                }
            }
        }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == VELA){
            if(jugada == LINTERNA || jugada == BENGALA){
                if(encontrar_herramienta(juego->personaje,jugada) >= 0){
                    juego->personaje.elemento_en_uso = encontrar_herramienta(juego->personaje,jugada);
                    juego->personaje.mochila[juego->personaje.elemento_en_uso].movimientos_restantes--;
                    if(jugada == LINTERNA){
                        generar_koala(juego->obstaculos,&(juego->cantidad_obstaculos),terreno);           
                    }
                }
            }
        }
    }

}
/*
* PRE: herramienta debe ser una herramienta valida, juego_t debe ser un struct valido
* POST: Si la jugada es una herramienta la enciende o la apaga 
*/
void encender_apagar_herramienta(juego_t* juego, char herramienta,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    int posicion_herramienta = 0;
    char herramienta_encendida;

    if(hay_herramienta_encendida(juego->personaje.elemento_en_uso) == false){
        posicion_herramienta = encontrar_herramienta((juego->personaje),herramienta);
        if(posicion_herramienta >= 0){
            if(juego->personaje.mochila[posicion_herramienta].movimientos_restantes > 0){
                juego->personaje.elemento_en_uso = posicion_herramienta;
                juego->personaje.mochila[posicion_herramienta].movimientos_restantes = juego->personaje.mochila[posicion_herramienta].movimientos_restantes -1;
                if(herramienta == LINTERNA){
                    generar_koala(juego->obstaculos,&(juego->cantidad_obstaculos),terreno);
                }
            }
        }
    }else{
        posicion_herramienta = juego->personaje.elemento_en_uso;
        herramienta_encendida = juego->personaje.mochila[posicion_herramienta].tipo;
        if(herramienta == herramienta_encendida){
            if(herramienta == BENGALA){
                juego->personaje.mochila[posicion_herramienta].movimientos_restantes = juego->personaje.mochila[posicion_herramienta].movimientos_restantes -1;
            }else{
                juego->personaje.elemento_en_uso = HERRAMIENTA_APAGADA;
            }
        }else{
            cambiar_herramienta(juego,herramienta,terreno);
        }
    }
}
/*
* PRE: Juego debe ser una estructura valida
* POST: Hace todos los elementos del mapa invisibles 
*/
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
/*
* PRE: posicion_jugador y movimiento debe estar inicializado, movimiento debe ser un movimiento valido, juego_t debe ser un struct valido
* POST: Ilumina los elementos en la fila indicada
*/
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
/*
* PRE: Recibe un juego con todas sus estructuras válidas
* POST: Ilumina la fila correcta con la linterna
*/
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
/*
* PRE: Recibe un juego con todas sus estructuras válidas
* POST: Ilumina el mapa con la vela
*/
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
/*
* PRE: punto1x,punto1y,punto2x,punto2y deben estar inicializados
* POST: Calcula la distancia manhattan entre dos puntos y devuelve el resultado
*/
int distancia_manhattan(int punto1x, int punto1y, int punto2x, int punto2y){
    int resultado;

    resultado = (abs(punto1x - punto2x) + abs(punto1y - punto2y));

    return resultado;
}
/*
* PRE: Recibe un juego con todas sus estructuras válidas
* POST: Ilumina el mapa con la bengala
*/
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
/*
* PRE: Recibe un juego con todas sus estructuras válidas
* POST: Ilumina el mapa con la herramienta indicada
*/
void iluminar_herramienta(juego_t* juego,char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){

    oscurecer_terreno(juego);

    if(hay_herramienta_encendida(juego->personaje.elemento_en_uso) == true){
        if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == LINTERNA){
            iluminar_linterna(juego);
        }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == VELA){
            iluminar_vela(juego);
        }else if(juego->personaje.mochila[juego->personaje.elemento_en_uso].tipo == BENGALA){
            iluminar_bengala(juego);
        }
    } 
}
/*
* PRE: personaje_t debe ser una estructura valida
* POST: Elimina una herramienta que ya no tiene movimientos restantes
*/
void eliminar_herramienta(personaje_t* personaje){
    if(hay_herramienta_encendida(personaje->elemento_en_uso) == true){
        if(personaje->mochila[personaje->elemento_en_uso].movimientos_restantes <= 0){
            if(personaje->mochila[personaje->elemento_en_uso].tipo != LINTERNA){
                personaje->mochila[personaje->elemento_en_uso].tipo = VACIO;
            }
            personaje->elemento_en_uso = HERRAMIENTA_APAGADA;
        }
    }
}   
/*
* PRE: Jugada debe estar inicializado, juego_t debe ser un struct valido
* POST: Enciende o cambia a la herramienta indicada
*/
void utilizar_herramienta(juego_t* juego, char jugada, char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA]){
    if(jugada == LINTERNA){
        encender_apagar_herramienta(juego,LINTERNA,terreno);
    }else if(jugada == VELA){;
        encender_apagar_herramienta(juego,VELA,terreno);
    }else if(jugada == BENGALA){
        encender_apagar_herramienta(juego,BENGALA,terreno);
    }

    eliminar_herramienta(&(juego->personaje));
}
/*
* PRE: personaje.tipo debe ser un personaje valido, personaje_t debe ser un struct valido
* POST: Hace a chloe visible luego de que tiempo perdido sea mayor o igual a 30 si el personaje es panda
*/
void panda_chloe_visible(personaje_t personaje, bool* chloe_visible){
    if(personaje.tipo == PANDA_OSO && personaje.tiempo_perdido >= 30){
        (*chloe_visible)= true;
    } 
}
/*
* PRE: Recibe una estructura juego y una jugada valida
* POST: Mueve el personaje en la direccion indicada o habilita cualquiera de las herramientas y actualiza el juego
*/
void realizar_jugada(juego_t* juego, char jugada){
    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];

    recrear_matriz(juego,terreno);
    utilizar_herramienta(juego,jugada,terreno);
    mover_jugador(juego,jugada,terreno);
    iluminar_herramienta(juego,terreno);
    panda_chloe_visible(juego->personaje, &(juego->chloe_visible));
}
/*
* PRE: Recibe un juego con todas sus estructuras válidas
* POST: Muestra el juego por pantalla
*/
void mostrar_juego(juego_t juego){

    char terreno[MAX_TERRENO_FILA][MAX_TERRENO_COLUMNA];
    
    for(int i = 0; i < MAX_TERRENO_FILA; i++){
        for(int j = 0; j < MAX_TERRENO_COLUMNA;j++){
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
        printf("\n");
    }
    printf("\n\n");
}