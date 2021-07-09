#include <stdio.h>

int seleccion(int vector[], int tope){
    int i,j;
    int aux;
    int minimo;

    for(i = 0; i < tope; i++){
        minimo = i;
        for(j = i + 1;j < tope; j++){
            if(vector[minimo] > vector[j]){
                minimo = j;
                aux = vector[i];
                vector[i] = vector[minimo];
                vector[minimo] = aux;
            }
        }
    }

    return 0;
}

int main(){

    int vector[10] = {9,10,8,7,5,6,2,3,1,4};
    int tope = 10;
    seleccion(vector,tope);

    for(int i=0;i < tope; i++){
        printf(" %i ", vector[i]);
    }

    return 0;
}