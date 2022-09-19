#include <stdio.h>

int cuadrado(int un_numero){
    return un_numero * un_numero;
}

int main(){
    int valor;

    valor=cuadrado(3);
    printf("valor vale %i\n", valor);
    return 0;   

}