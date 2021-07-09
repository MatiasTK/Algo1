#include <stdio.h>
#include <string.h>

int strlen_manual(char string[]){

    int i = 0;

    while(string[i] != '\0'){
        i++;
    }
    return i;
}

int strlen_recursiva(char string[],int inicio){

    if(string[inicio] == '\0'){
        return 0;
    } else {
        return 1 + strlen_recursiva(string, inicio+1);    // Lo traduciria como: Poneme un 1 y volve a analizar en el vector siguiente
    }                                                     
}
// seria tipo: en h no hay \0 entonces añado 1 y analizo el siguiente, en o no hay \0 añado 1 y analizo el siguiente..
int main(){

    printf("La longitud es: %i\n", strlen_manual("hola"));
    printf("La longitud es: %i\n", strlen_recursiva("hola", 0));

    return 0;
}