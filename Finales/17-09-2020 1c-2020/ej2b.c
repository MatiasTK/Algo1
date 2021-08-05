#include <stdio.h>
#include <string.h>

int desencriptar(){
    FILE* desencriptado = fopen("testamento.txt","r");

    FILE* encriptar = fopen("encriptar.txt", "w");

    while(!desencriptado){
        printf("No se pudo abrir testamento.txt");
        return -1;
    }

    while(!encriptar){
        printf("No se pudo crear encriptado.txt");
        fclose(desencriptado);
        return -1;
    }

    char caracter_buscado;

    int leer = fscanf(desencriptado,"%c",&caracter_buscado);

    while(leer != EOF){
        if(caracter_buscado == 'E'){
            fprintf(encriptar,"Ejeje");
        }else if(caracter_buscado == 'e'){
            fprintf(encriptar,"ejeje");
        }else if(caracter_buscado == 'a'){
            fprintf(encriptar,"s");
        }else if(caracter_buscado == 's'){
            fprintf(encriptar,"n");
        }else if(caracter_buscado == 'n'){
            fprintf(encriptar,"r");
        }else if(caracter_buscado == 'r'){
            fprintf(encriptar,"a");
        }else{
            fprintf(encriptar,"%c",caracter_buscado);
        }

        leer = fscanf(desencriptado,"%c",&caracter_buscado);
    }

    fclose(desencriptado);
    fclose(encriptar);
}

int main(){

    desencriptar();

    return 0;
}