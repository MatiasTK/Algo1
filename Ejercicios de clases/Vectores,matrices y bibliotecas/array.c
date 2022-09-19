#include <stdio.h>
#include "vectores.h" // Atencion si tiene esto no puedo usar vscode para llamar a la lib, tengo que escribir manual en la terminal


int main(){

    int otro_arreglo[9];            
    int otro_tope = 9;

    int mi_arreglo[]={1,2,3,4,5,6,7,8,9};
    int tope = 9;

    inicializar_arreglo_de(otro_arreglo, otro_tope);
    imprimir_vector_de(mi_arreglo, tope);
    imprimir_vector_de(otro_arreglo, otro_tope);
    

    return 0;
}