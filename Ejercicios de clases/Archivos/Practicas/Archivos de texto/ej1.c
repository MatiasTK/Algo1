#include <stdio.h>
#include <string.h>

#define MAX_LETRAS 200


void imprimir_cancion(){
    FILE* cancion = fopen("cancion_especial.txt","r");

    if(!cancion){
        perror("No se pudo abrir cancion_especial.txt\n");
        return;
    }

    char letra[MAX_LETRAS];

    size_t leer = fscanf(cancion,"%[^\n]\n",letra);

    while(leer == 1){
        printf("%s\n",letra);
        leer = fscanf(cancion,"%[^\n]\n",letra);
    }

    fclose(cancion);
}

int main(){

    imprimir_cancion();


    return 0;
}