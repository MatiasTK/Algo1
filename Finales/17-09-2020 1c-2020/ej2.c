#include <stdio.h>
#include <string.h>

#define MAX_PALABRA 200

void desencriptar(){
    FILE* encriptado = fopen("testamento.txt","r");
    if(!encriptado){
        perror("No se pudo abrir testamento.txt");
        return;
    }

    FILE* desencriptado = fopen("desencriptado.txt","w");
    if(!desencriptado){
        fclose(encriptado);
        perror("No se pudo crear desencriptado.txt");
        return;
    }

    char letra;
    char palabra_a_remover[MAX_PALABRA]; // Esto deberia recibirlo en la firma de la funcion
    strcpy(palabra_a_remover,"jeje");

    int leer = fscanf(encriptado,"%c",&letra);

    while(leer == 1){
        if(letra == 'E'){
            fprintf(desencriptado,"%c",'E');
            int logintud_indicada = 0;
            while(logintud_indicada != strlen(palabra_a_remover)){
                leer = fscanf(encriptado,"%c",&letra);
                logintud_indicada++;
            }
        }else if(letra == 'e'){
            fprintf(desencriptado,"%c",'e');
            int logintud_indicada = 0;
            while(logintud_indicada != strlen(palabra_a_remover)){
                leer = fscanf(encriptado,"%c",&letra);
                logintud_indicada++;
            }
        }else if(letra == 's'){
            fprintf(desencriptado,"%c",'a');
        }else if(letra == 'n'){
            fprintf(desencriptado,"%c",'s');
        }else if(letra == 'r'){
            fprintf(desencriptado,"%c",'n');
        }else if(letra == 'a'){
            fprintf(desencriptado,"%c",'r');
        }else{
            fprintf(desencriptado,"%c",letra);
        }
        leer = fscanf(encriptado,"%c",&letra);
    }

    fclose(desencriptado);
    fclose(encriptado);
}

int main(){

    desencriptar();

    return 0;
}