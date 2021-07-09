#include <stdio.h>

typedef struct cancion{

int duracion;
char genero;
int cantidad_insultos;
int bpm;

} cancion_t;

typedef struct artista{

int edad;
char color_de_pelo;
char genero_principal;
int cantidad_discos;

cancion_t mini_canciones;      // AÑADO UN STRUCT DENTRO DE OTRO

} artista_t;


int main(){

    artista_t charly;

    charly.mini_canciones[3].cantidad_insultos = 50;

    return 0;
}