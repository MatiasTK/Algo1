#include <stdio.h>
#define MAX_AHORROS 256

const char ED = 'E';
const char EDD = 'D';
const char EDDY = 'Y';
const char NADIE = 'N';

char ganador_ahorrista(int ahorros[MAX_AHORROS], int tope_ahorros) {

    int posicion_dia;
    int mayor = 0;
    char ganador;

    for(int i = 0; i < tope_ahorros; i++){
        if(ahorros[i] > mayor){
            mayor = ahorros[i];
            posicion_dia =  i + 1;
        }
    }

    if(tope_ahorros == 0){
        ganador = NADIE;
    } else if(posicion_dia % 2 == 0){
        ganador = EDD;
    } else if(posicion_dia % 5 == 0 && posicion_dia % 2 != 0){
        ganador = ED;
    } else {
        ganador = EDDY;
    }

return ganador;
}