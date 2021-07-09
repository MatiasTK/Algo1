#include <stdio.h>
#include <string.h>
#include "ejercicio_1.h"
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
/*
* PRE: cantidad colabs > 0, posicion valida del vector.
* POST: Se borrara el colab del vector, se reduce el tope en 1.
*/
void eliminar_colab(colaborador_t colabs[MAX_COLABS], int* cantidad_colabs, int posicion){          // SIRVE PARA ELIMINAR ALGO DE LA MOCHILA EN EL TP
    // colabs[posicion] = colabs[*(cantidad_colabs) - 1];
    strcpy (colabs[posicion].nombre, colabs[(*cantidad_colabs) - 1].nombre;
    colabs[posicion].fil = colabs[*(cantidad_colabs) - 1].fil;
    colabs[posicion].col = colabs[*(cantidad_colabs) - 1].col;
    (*cantidad_colabs)--;
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

    return 0;
}