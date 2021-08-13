#include <stdio.h>

#define MAX_GENERO 50

typedef struct genero{
    char nombre[MAX_GENERO];
    int id;
} genero_t;

int main(){
    FILE* abrir = fopen("generos.csv","r");

    FILE* crear = fopen("generos.dat","w");

    if(!abrir){
        perror("No se pudo leer generos.csv");
        return -1;
    }

    if(crear == NULL){
        fclose(abrir);
        perror("No se pudo crear generos.dat");
        return -1;
    }

    genero_t genero;

    int leer = fscanf(abrir,"%[^;];%i\n",genero.nombre,&genero.id);

    while(leer == 2){
        fwrite(&genero,sizeof(genero_t),1,crear);
        leer = fscanf(abrir,"%[^;];%i\n",genero.nombre,&genero.id);
    }

    fclose(abrir);
    fclose(crear);

}