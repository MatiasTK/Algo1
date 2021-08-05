#include <stdio.h>

int cantidad_comidas_cocinar(comida_t comidas[MAX_COMIDAS], int inicio, int tope){
    if(inicio < tope){
        if(comidas[inicio].cantidad_veces_hecha < 7){
            return 1+ cantidad_comidas_cocinar(comidas, inicio+1, tope);
        }   
    return cantidad_comidas_cocinar(comidas, inicio+1, tope);
    }
    return 0;
}

int main(){

    cantidad_comidas_cocinar();


    return 0;
}