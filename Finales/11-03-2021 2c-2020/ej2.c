#include <stdio.h>
#include <string.h>

#define MAX_FRASE 100

typedef struct mensaje {
    char frase[MAX_FRASE];
    char letra;
} mensaje_t;

void cifrar_mensaje(){
    FILE* binario = fopen("mensaje_a_cifrar.dat","r");
    if(binario == NULL){
        perror("No se pudo abrir mensaje_a_cifrar.dat");
        return;
    }
    FILE* resultado = fopen("mensaje_cifrado.txt","w");
    if(!resultado){
        fclose(binario);
        perror("No se pudo crear mensaje_firado.txt");
        return;
    }

    mensaje_t mensaje;

    int leer = fread(&mensaje,sizeof(mensaje_t),1,binario);

    while(!feof(binario)){
        for(int i = 0; i < strlen(mensaje.frase);i++){
            if(mensaje.frase[i] != mensaje.letra){
                fprintf(resultado,"%c",mensaje.frase[i]);
            }
        }
        leer = fread(&mensaje,sizeof(mensaje_t),1,binario);
    }

    fclose(binario);
    fclose(resultado);
}

int main(){

    cifrar_mensaje();

    return 0;
}