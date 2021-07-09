#include <stdio.h>

const char NEGRO = 'n';

typedef struct colab {
    unsigned short altura;
    char color_de_pelo;
    unsigned int edad;
    long cantidad_veces_nombrado;
}colab_t;

void cargar_colab(colab_t* colaborador){
    *(colaborador)->altura = 140;
    colaborador->color_de_pelo = 'n';
    colaborador->edad = 22;
    colaborador->cantidad_veces_nombrado = 10;
}

void mostrar_colab(colab_t colaborador){
    printf("La altura es : %hu \n", colaborador);
    printf("Y tiene el pelo color  %c \n", colaborador.color_de_pelo);
}

int main(){

    colab_t tomi;
    cargar_colab(&tomi);
    mostrar_colab(tomi);


    return 0;
}