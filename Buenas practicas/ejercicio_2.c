#include <stdio.h>
#include <stdbool.h>

const char CHARLY = 'C';
const char DELFI = 'D';
const char TOMI = 'T';

const int PUNTAJE_MINIMO = 0; 
const int PUNTAJE_MAXIMO = 10;
const int PUNTAJE_MEDIO = 5;

/*
*   PRE: Colaborador es CHARLY, DELFI o TOMI. Puntajes entre PUNTAJE_MINIMO y PUNTAJE_MAXIMO.
*   POST: Modifico puntajes en base a lo que quiere Charly.
*/
void modificar_puntajes(char colaborador, int* enojo, int* felicidad){

    if(colaborador == CHARLY){
        (*enojo) = PUNTAJE_MINIMO;
        (*felicidad) = PUNTAJE_MAXIMO;
    } else if(colaborador == DELFI){
        (*enojo) = PUNTAJE_MAXIMO;
    } else {
        (*enojo) = PUNTAJE_MINIMO;
        (*felicidad) = PUNTAJE_MEDIO;
    }


}

bool es_colaborador_valido(char colaborador){
    return (colaborador == CHARLY || colaborador == TOMI || colaborador == DELFI);
}

void pedir_colaborador(char* colaborador){
printf("Tirame el colaborador (%c,%c,%c):", CHARLY, DELFI, TOMI);
scanf(" %c", colaborador);

    while(!es_colaborador_valido(*colaborador)){
        printf("Ese colaborador no existe. tiramela bien (%c,%c,%c):", CHARLY, DELFI, TOMI);
        scanf(" %c", colaborador);
    }
}

bool es_felicidad_valida(int felicidad){
    return (felicidad >= PUNTAJE_MINIMO && felicidad <= PUNTAJE_MAXIMO);
}

void pedir_felicidad(int* felicidad){

    printf("Tirame el puntaje de la felicidad (%i,%i):", PUNTAJE_MINIMO, PUNTAJE_MAXIMO);
    scanf(" %i", felicidad);

    while(!es_felicidad_valida(*felicidad)){
        printf("Esa felicidad no existe. Tiramela bien (%i,%i):", PUNTAJE_MINIMO, PUNTAJE_MAXIMO);
        scanf(" %i", felicidad);

    }

}

void imprimir_valores(char colaborador, int enojo, int felicidad){
    printf("El colaborador es %c, tiene un puntaje de enojo de %i, y un puntaje de felicidad de %i\n", colaborador, enojo, felicidad);
}

bool es_enojo_valido(int enojo){
    return (enojo >= PUNTAJE_MINIMO && enojo <= PUNTAJE_MAXIMO);
}

void pedir_enojo(int* enojo){

    printf("Tirame el puntaje de enojo (%i, %i):", PUNTAJE_MINIMO, PUNTAJE_MAXIMO);
    scanf(" %i", enojo);

    while(!es_enojo_valido(*enojo)){
        printf("Ese enojo no existe. Tiramelo bien (%i,%i):", PUNTAJE_MINIMO, PUNTAJE_MAXIMO);
        scanf(" %i", enojo);
    }
}

int main(){
    
    char colaborador;
    int enojo;
    int felicidad;

    pedir_colaborador(&colaborador);
    pedir_felicidad(&felicidad);
    pedir_enojo(&enojo);
    modificar_puntajes(colaborador,&enojo, &felicidad);
    imprimir_valores(colaborador, enojo, felicidad);
   

    return 0;
}