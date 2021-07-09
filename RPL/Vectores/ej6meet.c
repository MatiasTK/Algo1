#include <stdio.h>

#define ANIOS_BOKE 10

int main(){

    int copas[ANIOS_BOKE] = {4,1,5,2,3,8,2,6,7,1};

    int maximo = buscar_maximo(copas,ANIOS_BOKE);
    int minimo = buscar_minimo(copas, ANIOS_BOKE);

    printf("El año que mas copas gano bokita fue %i\n", maximo);
    printf("El año que menos copas gano bokita fue %i\n", minimo);

    return 0;

}

int buscar_maximo(int array[], int tope){

    int maximo = 0;


    for(int i = 0; i < tope; i++){
        if( array[i] > maximo){
            maximo = array[i];
            
        }
    }

    return maximo;
}

int buscar_minimo(int array[], int tope){

    int minimo = array[0];

    for(int i = 0; i < tope; i++){
        if(array[i] < minimo){
            minimo = array[i];
        }
    }
    return minimo;
}