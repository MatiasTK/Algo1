#include <stdio.h>

#define MAX_FILA 10
#define MAX_COLUMNA 10
//----------------------------> Esta hecho medio raro pero creo que funciona
#define MAX_PIEZAS 200

typedef struct pieza {
    int fil;
    int col;
    int id;
} pieza_t;

void armar_rompecabezas(pieza_t matriz[MAX_FILA][MAX_COLUMNA], int tope_fila, int tope_columna,pieza_t matriz_nueva[MAX_FILA][MAX_COLUMNA], int tope_final_fila, int tope_final_columna){
    for(int i = 0; i < tope_fila;i++){
        for(int j = 0; j < tope_columna;j++){
            matriz_nueva[matriz[i][j].fil][matriz[i][j].col].id = matriz[i][j].id;
            tope_final_columna++;
            //Aunque creo que aumentar los topes no es necesario ya que utiliza los mismos topes que la matriz original
        }
        tope_final_fila++;
    }
}   

int main(){


    return 0;
}