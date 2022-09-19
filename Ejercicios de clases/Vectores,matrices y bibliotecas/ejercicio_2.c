#include <stdio.h>
#include <stdbool.h>

#define ALTO 10
#define ANCHO 10

const char AWITA = 'A';
const char BARQUITO = 'B';
const char TOCADO = 'T';
const char ERRADO = 'X';

/*
* PRE: NO TIENE!
* POST: devuelve la matriz llena de agua
*/
void llenar_con_agua(char terreno[ALTO][ANCHO]){
    for(int i = 0; i < ALTO; i++){
        for(int j = 0; j < ANCHO;j++){
            terreno[i][j] = AWITA;
        }
    }
}

void posicionar_barquito(char terreno[ALTO][ANCHO]){
    terreno[1][1] = BARQUITO;
    terreno[1][2] = BARQUITO;
}

void mostrar_terreno(char terreno[ALTO][ANCHO]){
    for(int i = 0; i < ALTO; i++){
        for(int j = 0; j < ANCHO;j++){
            printf("%c", terreno[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void disparar(char terreno[ALTO][ANCHO], int fila, int columna){
    if(terreno[fila][columna] == BARQUITO){
        terreno[fila][columna] = TOCADO;
    } else if(terreno[fila][columna] == AWITA){
        terreno[fila][columna] = ERRADO;
    }
}

int main(){

    int fila, columna;

    char terreno[ALTO][ANCHO];
    llenar_con_agua(terreno);
    mostrar_terreno(terreno);
    posicionar_barquito(terreno);
    mostrar_terreno(terreno);

    printf("Fila disparo:  \n");
    scanf("%i", &fila);
    printf("Columna disparo: \n");
    scanf("%i", &columna);

    disparar(terreno, fila, columna);
    mostrar_terreno(terreno);

    return 0;   
}