#include <stdio.h>
#include <stdbool.h>

int busqueda_lineal(int vector[10], int tope, int buscado){
    
    bool encontrado = false;
    int i = 0;
    int resultado = 0;

    while(!encontrado && i < tope){
        if(vector[i] == buscado){
            encontrado = true;
            resultado = i;
        } else {
            i++;
        }
    }

    return resultado;
}

int main(){

    int vector[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tope = 10;
    int buscado = 0;

    printf("[");
    for(int i = 0; i < tope; i++){
        printf(" %i ",vector[i]);
    }
    printf("]\n");

    printf("Que numero queres buscar?\n");
    scanf("%i", &buscado);
    printf("El numero esta en la posicion %i\n", busqueda_lineal(vector,tope,buscado));

    return 0;
}