#include <stdio.h>
#include <string.h>

#define MAX_FRASE 50

void imprimir_vocales_aux(char frase[MAX_FRASE], int posicion){
    if(frase[posicion] == '\0'){
        return;
    }
    if(frase[posicion] == 'a' || frase[posicion] == 'e' || frase[posicion] == 'i' || frase[posicion] == 'o' || frase[posicion] == 'u'){
        printf(" %c\n", frase[posicion]);
    }
    return imprimir_vocales_aux(frase, posicion+1);
}

void imprimir_vocales(char frase[MAX_FRASE]){
    imprimir_vocales_aux(frase,0);
}

void imprimir_pares_aux(char frase[MAX_FRASE], int posicion){
    if(frase[posicion] == '\0'){
        return;
    }

    if((posicion % 2 == 0){
        printf(" %c\n", frase[posicion]);
    }

    return imprimir_pares_aux(frase,posicion+1);
}

void imprimir_pares(char frase[MAX_FRASE]){
    imprimir_pares_aux(frase,0);
}

int main(){

    char frase[MAX_FRASE];
    strcpy(frase, "algoritmos mendez");

    // imprimir_vocales(frase);
    imprimir_pares(frase);

    return 0;
}