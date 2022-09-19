#include <stdio.h>
#include <string.h>
#include "ejercicio_1.h"
#include <stdlib.h>
#include <time.h>
                                // NOTA: ES MALA PRACTICA USAR UN RETURN DENTRO DE FOR Y BREAK DENTRO DE FOR
                                // CODIGO PARA BUSCAR COSAS EN LA MOCHILA -> LINTERNA,BENGALAS,VELAS
#define MAX_NOMBRE 50
#define MAX_COLABS 23

typedef struct colaborador
{
    char nombre[MAX_NOMBRE];
    int fil;
    int col;
}colaborador_t;

void cargar_vector(colaborador_t colabs[MAX_COLABS], int* cantidad_colabs){
    // FALTA CODIGO
}

int buscar_colab(colaborador_t colabs[MAX_COLABS], int cantidad_colabs, char nombre_buscado[MAX_NOMBRE]){

    // int posicion = -1;
    // for(int i = 0; i < cantidad_colabs; i++){
    //     if(strcmp(colabs[i].nombre, nombre_buscado) == 0){
    //         posicion = i;
    //     }
    // }
    // return posicion;

    int i = 0;
    int posicion = -1;

    while(i < cantidad_colabs && posicion == -1){                           // USO WHILE Y NO FOR YA QUE NECESITO QUE PARE CUANDO LO ENCUENTRE SINO
        if(strcmp(colabs[i].nombre, nombre_buscado) == 0){                  // TENDRIA QUE USAR BREAK Y ES MALA PRACTICA
            posicion = i;
        }
        i++;
    }

    return posicion;
}

void imprimir_posicion(colaborador_t colabs[MAX_COLABS],int cantidad_colabs, char nombre_buscado[MAX_NOMBRE]){
    int posicion = buscar_colab(colabs,cantidad_colabs,nombre_buscado);
    if(posicion != -1){
        printf("%s esta en la fila %i y en la columna %i",nombre_buscado,colabs[posicion].fil,colabs[posicion].col);
    } else {
        printf("El colaborador %s se escapa de mi vida", nombre_buscado);
    }
}

void mostrar_habitacion(colaborador_t colabs[MAX_COLABS], int cantidad_colabs){
    //INICIALIZAR MATRIZ
    char habitacion[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            habitacion[i][j] = '_';

        }  
    }

    //CARGO COSAS EN LA MATRIZ
    for(int i = 0; i < cantidad_colabs; i++){
        char inicial = colabs[i].nombre[0];
        habitacion[colabs[i].fil][colabs[j].col]; 
    }

    // MOSTRAR POR PANTALLA
    printf(" 0 1 2 3 4 5 6 7 8 9\n");
    for(int i = 0; i < 10; i++){
        printf("%i", i);
        for(int j = 0; j < 10; j++){
            printf(" %c", habitacion[i][j]);
        }
        printf("\n");
    }
}

int main(){

    colaborador_t colabs[MAX_COLABS];
    int cantidad_colabs = 0;

    cargar_vector(colabs,&cantidad_colabs);

    for(int i = 0; i < cantidad_colabs; i++){
        printf("%s\tFila:%i\tColumna:%i\n",colabs[i].nombre,colabs[i].fil,colabs[i].col);
    }

    char nombre_buscado[MAX_NOMBRE];
    strcpy(nombre_buscado,"Cande");
    imprimir_posicion(colabs, cantidad_colabs, nombre_buscado);


    //Generar numero aleatorio (STDLIB)

    srand ((unsigned int) time(NULL)); // Necesita time.h, srand hace que cambie en funcion de tiempo el numero generado, NULL hace referencia al tiempo actual

    for(int i = 0; i < 10,i++){
        int numero_aleatorio = rand()%100; // va a generar numeros entre 0 y 99 
        printf("%i\n", numero_aleatorio);
    }

    return 0;
}