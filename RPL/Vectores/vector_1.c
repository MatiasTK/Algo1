#include <stdio.h>
#define MAX_HABITACIONES 200
const char LLAVE = 'L'; 

int posicion_llave(char habitaciones[MAX_HABITACIONES], int tope_habitaciones) {
    
    int contador = 0;
    for(int i = 0; i < tope_habitaciones; i++){
        if(habitaciones[i] == LLAVE){
            contador = i;
        }
    }
    return contador;
}