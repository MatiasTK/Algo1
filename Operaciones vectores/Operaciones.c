//                                  EL VECTOR DEBE ESTAR ORDENADO!
#include <stdio.h>

#define MAX_VECTOR 50

void mezcla ( int vector_uno[] , int tope_uno , int vector_dos[] , int tope_dos , int
vector_resultado[] , int* tope_resultado ){
    int i ,j;
    i =0;
    j =0;
    (* tope_resultado ) =0;

    while ( ( i < tope_uno ) && ( j < tope_dos ) ){
        if ( vector_uno [i] <= vector_dos [j ]) {
        vector_resultado [* tope_resultado ]= vector_uno [i ];
        i ++;
        }
    else {
        vector_resultado [* tope_resultado ]= vector_dos [j ];
        j ++;
    }
    (* tope_resultado ) ++;
    }

 /* Si alguno de los vectores llego a su tope se completa el vector resultado con los
elementos del otro vector */

    while (i < tope_uno ){
        vector_resultado [* tope_resultado ]= vector_uno [i ];
        (* tope_resultado ) ++;
        i ++;
    }
    while (j < tope_dos ){
        vector_resultado [* tope_resultado ]= vector_dos [j ];
        (* tope_resultado ) ++;
        j ++;
    }
}

void diferencia_vectores ( int vector_uno[] , int tope_uno , int vector_dos[] ,
 int tope_dos , int vector_diferencia[MAX_VECTOR] , int * tope_diferencia ){

    int i = 0, j = 0;
    (* tope_diferencia ) =0;

    while ( i < tope_uno && j < tope_dos ){
        if( vector_uno [i ] == vector_dos [j ]){
            i ++;
            j ++;
        } else if ( vector_uno [ i] < vector_dos [j ]) {
            vector_diferencia [* tope_diferencia ] = vector_uno [i ];
            (* tope_diferencia ) ++;
            i ++;
        } else {
            j ++;
        }
    }
    while (i < tope_uno ){
        vector_diferencia [* tope_diferencia ] = vector_uno [i ];
        (* tope_diferencia ) ++;
        i ++;
    }
        while (i < tope_dos ){
        vector_diferencia [* tope_diferencia ] = vector_uno [j ];
        (* tope_diferencia ) ++;
        j ++;
    }
}

void interseccion ( int vector_uno [] , int tope_uno , int vector_dos [], int tope_dos , int
vector_interseccion [] , int * tope_interseccion ) {

    int i =0;
    int j =0;
    (* tope_interseccion ) =0;

     while ( ( i < tope_uno ) && ( j < tope_dos ) ){
         if( vector_uno [i ] == vector_dos [ j ]) {
            vector_interseccion [* tope_interseccion ]= vector_uno [i ];
            (* tope_interseccion ) ++;
            i ++;
            j ++;
        } else if( vector_uno [i] < vector_dos [j ]) {
            i ++;
        } else {
            j ++;
    }
    }
}

int main(){

    int tope_uno = 10;
    int tope_dos = 5;

    int vector_uno[] = {1, 4, 6, 8, 12, 15, 20, 23, 24, 26};
    int vector_dos[] = {1, 3, 5, 9, 17};

    int vector_resultado[MAX_VECTOR];
    int tope_resultado = 0;
    //Añadir el otro vector de forma ordenada
    mezcla(vector_uno,tope_uno,vector_dos,tope_dos,vector_resultado,&tope_resultado);
    printf("La mezcla es:");
    for(int i = 0; i < tope_resultado; i++){
        printf(" %i", vector_resultado[i]);
    }
    printf("\n");
    //Restar repetidos entre dos vectores
    int vector_diferencia[MAX_VECTOR];
    int tope_diferencia = 0;

    diferencia_vectores(vector_uno,tope_uno,vector_dos,tope_dos,vector_diferencia,&tope_diferencia);
    printf("La diferencia es:");
    for(int i = 0; i < tope_diferencia; i++){
        printf(" %i", vector_diferencia[i]);
    }
    printf("\n");

    int vector_interseccion[MAX_VECTOR];
    int tope_interseccion = 0;
    //Numeros que se repitan en los dos vectores
    interseccion(vector_uno,tope_uno,vector_dos,tope_dos,vector_interseccion,&tope_interseccion);
    printf("La interseccion es:");
    for(int i = 0; i < tope_interseccion; i++){
        printf(" %i", vector_interseccion[i]);
    }
    printf("\n");

    return 0;
}