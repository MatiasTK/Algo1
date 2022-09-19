#include <stdio.h>

typedef struct cancion{

int duracion;
char genero;
int cantidad_insultos;
int bpm;

} cancion_t;

int main(){

    int nombre_del_vector[50];

    cancion_t mini_canciones[10];
    int tope;

    cargar_canciones_charly(mini_canciones, &tope);

    mini_canciones[2].genero = 'T';

    return 0;
}