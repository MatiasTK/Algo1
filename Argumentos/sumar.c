#include <stdio.h>
#include <stdlib.h> //Para usar atoi
#include <stdbool.h>
#include <ctype.h>

bool es_numerico(char caracter){
    return(isdigit(caracter)); // da true si es un numero
}

bool string_numerico(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        if(!es_numerico(string[i])){
            return false;
        }
        i++;
    }
    return true;
}

int main(int argc, char* argv[]){

    int suma = 0;

    for(int i = 1; i < argc; i++){  
        if(string_numerico(argv[i])){
            suma += atoi(argv[i]); //Atoi convierte un string en int
        }else{
            printf("Chinchulin mandaste algo no numerico, lo ignore\n");
        }
    }

    printf("La suma de argumentos es %i\n", suma);

    return 0;
}