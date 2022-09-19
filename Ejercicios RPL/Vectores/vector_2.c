#include <stdio.h>
#define MAX_AHORROS 256

int calcular_ahorros_totales(int ahorros[MAX_AHORROS], int tope_ahorros) {
	int suma_vector = 0;
    for(int i = 0; i < tope_ahorros; i++){
        suma_vector = suma_vector + ahorros[i];
    }
    return suma_vector;
}