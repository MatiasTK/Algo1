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

cancion_t petiso_me_dicen;      // AÑADO UN STRUCT DENTRO DE OTRO

} artista_t;


int main(){

    artista_t charly;

    charly.edad = 36;
    charly.color_de_pelo = 'V';
    charly.genero_principal = 'T';
    charly.cantidad_discos = 0;

    charly.petiso_me_dicen.duracion = 272;
    charly.petiso_me_dicen.genero = ;
    charly.petiso_me_dicen.cantidad_insultos = ;
    charly.petiso_me_dicen.bpm = ;

    return 0;
}