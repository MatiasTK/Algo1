#include <stdio.h>


int main(){

    FILE * archi;
    FILE * dest;

    archi = fopen("./leer", "r"); //Abre el archivo, "r" significa read -> para lectura unicamente

    dest = fopen("./escribir", "w"); //Abre el archivo, "w" significa write -> Para escritura, si existe lo deja en blanco si no crea uno nuevo

    if(!archi){
        printf("Error de apertura archi\n");
        return -1;
    }

    if(!dest){
        printf("Error de apertura dest\n");
        fclose(archi);
        return -1;
    }

    int letra;
    while(!feof(archi)){ //feof -> es como poner while(!true) -> devuelve true si llego al final del archivo
        letra = fgetc(archi); //fgetc -> lee un caracter de un stream
        printf("%c", letra);
        fputc(letra, dest); //Copia las letra de un stream y las pone en otro   
    }
    printf("\n");

    fclose(archi); //Cierra el archivo (Esto es importante)
    fclose(dest); //Cierra dest
    return 0;
}