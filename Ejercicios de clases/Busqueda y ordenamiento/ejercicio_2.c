#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SURCOS 500
#define MAX_HORTALIZAS_POR_SURCOS 500
#define MAX_NOMBRE 500
#define MAX_HORTALIZAS 500

const char CHOCLO = 'C';

typedef struct hortaliza {
char nombre;
int precio_de_lista;
} hortaliza_t;

typedef struct huerta {
hortaliza_t hortalizas[MAX_SURCOS][MAX_HORTALIZAS_POR_SURCOS];
int cantidad_surcos;
int cantidad_hortalizas_por_surcos;
} huerta_t;

typedef struct colaborador {
char nombre[MAX_NOMBRE];
hortaliza_t frutas_y_verduras[MAX_HORTALIZAS];
} colab_t;

typedef struct coordenada{
    int fil;
    int col;
}coordenada_t;

typedef struct ratas{
    char nombre[MAX_NOMBRE];
    int precio;
}ratas_t;

/*
* PRE: tope >= 0, huerta_t no debe estar vacia. 
* POST: agrega a coordenadas_choclo las posiciones de los choclos.
*/
void encontrar_choclitos(huerta_t huerta, coordenada_t coordenadas_choclo[MAX_CHOCLO], int* tope){
    for(int i = 0; i < huerta.cantidad_surcos; i++){
        for(int j = 0; j<huerta.cantidad_hortalizas_por_surcos; j++){
            if(huerta.hortalizas[i][j].nombre == CHOCLO){
                coordenadas_choclo[*tope].fil = i;
                cordenadas_choclo[*tope].col = j;
                (*tope)++;
            }
        }
    }
}

void crear_vector_ratas(colab_t colaboradores[MAX_COLABS],ratas_t ratas[MAX_COLABS], int tope, int* tope_deudores){
    int suma;
    for(int i = 0; i < tope;i++){
        suma = 0;
        for(int j = 0; i < colaboradores[i].cantidad_hortalizas; j++){
            suma = colaborador[i].frutas_y_verduras[j].precio_de_lista + suma;
        }
        if(suma > PRECIO_REGALO){
            strcpy(ratas[*tope_deudores].nombre, colaboradores[i].nombre);
            ratas[*tope_deudores].deuda = suma - PRECIO_REGALO;
            (*tope_deudores)++;
        }
    }
}