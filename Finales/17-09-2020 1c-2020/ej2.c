#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct desencriptar{
    char string_buscado[MAX_NOMBRE];
    char caracter_buscado;
} desencriptar_t;

int desencriptar(){

    FILE* testamento = fopen("testamento.txt","r");

    FILE* desencriptado = fopen("desencriptado.txt", "w");

    while(!testamento){
        printf("No se pudo abrir testamento.txt");
        return -1;
    }

    while(!desencriptado){
        printf("No se pudo crear desencriptado.txt");
        fclose(testamento);
        return -1;
    }

    desencriptar_t desencriptar;

    int leer = fscanf(testamento,"%c",&(desencriptar.caracter_buscado));

    while(leer != EOF){
        if(desencriptar.caracter_buscado == 'e'){
            
        }else if(desencriptar.caracter_buscado == 's'){
            fprintf(desencriptado,"a");
        }else if(desencriptar.caracter_buscado == 'n'){
            fprintf(desencriptado,"s");
        }else if(desencriptar.caracter_buscado == 'r'){
            fprintf(desencriptado,"n");
        }else if(desencriptar.caracter_buscado == 'a'){
            fprintf(desencriptado,"r");
        }else{
            fprintf(desencriptado,"%c",desencriptar.caracter_buscado);
        }

        leer = fscanf(testamento,"%c",&(desencriptar.caracter_buscado));
    }


    fclose(testamento);
    fclose(desencriptado);
}

int main(){

    desencriptar();

    return 0;
}