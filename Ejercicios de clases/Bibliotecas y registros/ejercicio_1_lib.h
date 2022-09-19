#ifndef __EJERCICIO_1_LIB__
#define __EJERCICIO_1_LIB__

#include <stdbool.h>

typedef struct juego{
int distancia;
int pan_pie;
char pan_inicial;
int queso_pie;
char queso_inicial;
char ultima_jugada;
} juego_t;

void inicializar_juego(juego_t* jueguito);

void jugar_turno(juego_t* jueguito);

#endif // __EJERCICIO_1_LIB__

