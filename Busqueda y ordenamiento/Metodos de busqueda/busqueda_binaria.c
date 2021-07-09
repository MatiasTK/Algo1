// SOLO SIRVE PARA UN VECTOR ORDENADO!!
// SI NO EXISTE LO QUE ESTOY BUSCANDO DEVUELVE -1
#include <stdio.h>  
#include <stdbool.h>

int busqueda_binaria_recursiva(int vector[10], int tope, int buscado, int inicio, int fin){
    if(inicio > fin){
        return -1;
    }

    int medio = (inicio + fin)/2;

    if(vector[medio] == buscado){
        return medio;
    } else if(vector[medio] > buscado){
        return busqueda_binaria_recursiva(vector,tope,buscado,inicio,medio-1);
    } else {
        return busqueda_binaria_recursiva(vector,tope,buscado,medio+1,fin);
    }
}

int busqueda_binaria_iterativa(int vector[10],int tope, int buscado){
    int inicio = 0;
    int fin = tope-1;
    int medio;
    bool encontrado = false;

    while(!encontrado && inicio <= fin){
        medio = (inicio+fin)/2;
        if(vector[medio] == buscado){
            encontrado = true;
        }else if(vector[medio] > buscado){
            fin = medio-1;
        } else{
            inicio = medio+1;
        }
    }

    if(!encontrado){
        return -1;
    } else {
        return medio;
    }
}


int main(){

    int vector[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int tope = 10;
    int buscado = 0;

    printf("[");
    for(int i = 0; i < tope; i++){
        printf(" %i ",vector[i]);
    }
    printf("]\n");

    printf("Que numero queres buscar?\n");
    scanf("%i", &buscado);
    printf("El numero esta en la posicion %i\n", busqueda_binaria_recursiva(vector,tope,buscado, 0, tope-1));
    printf("El numero esta en la posicion %i\n", busqueda_binaria_iterativa(vector,tope,buscado));

    return 0;
}