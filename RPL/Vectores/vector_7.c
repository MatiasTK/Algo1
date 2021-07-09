#include <stdio.h>
#define MAX_NUMEROS 100
// Aqui van las constantes...

int numero_mas_chico(int numeros[MAX_NUMEROS], int tope_numeros) {

    int menor = numeros[0];

    int posicion_menor = 0;

    for(int i = 0; i < tope_numeros; i++){
        if(numeros[i] < menor){
            menor = numeros[i];
            posicion_menor = i;
        }
    }
    return posicion_menor;
}

char programa_ganador(char programas[MAX_NUMEROS], int tope_programas, int numeros[MAX_NUMEROS], int tope_numeros) {
    
    int posicion_menor;

    posicion_menor = numero_mas_chico(numeros,tope_numeros);

    char resultado = programas[posicion_menor]; 

    if(tope_numeros == 0 || tope_programas == 0){
        resultado = '-';
    } else if(posicion_menor >= tope_programas){
        resultado = '-';
    }   
    
    return resultado;
}


// int main(){

// int numeros[MAX_NUMEROS] = {0,2,5};
// int tope_numeros =15;
// char programas[MAX_NUMEROS] = {'T','S','-'};
// int tope_programas = 15;

// int nc = numero_mas_chico(numeros, tope_numeros);
// char pg = programa_ganador(programas, tope_programas, numeros, tope_numeros);

// printf("El nc es  %i y el pg es %C\n", nc,pg);

// }