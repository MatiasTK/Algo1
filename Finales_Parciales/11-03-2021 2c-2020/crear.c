#include <stdio.h>
#include <string.h>

#define MAX_FRASE 100

typedef struct mensaje {
    char frase[MAX_FRASE];
    char letra;
} mensaje_t;

int main(){

    mensaje_t mensaje;
    strcpy(mensaje.frase,"esto es algo1mendez");
    mensaje.letra = 'e';
    FILE* archivo = fopen("mensaje_a_cifrar.dat","w");
    if(archivo == NULL){
        perror("No se pudo crear");
        return -1;
    }
    fwrite(&mensaje,sizeof(mensaje_t),1,archivo);
    fclose(archivo);

    return 0;
}