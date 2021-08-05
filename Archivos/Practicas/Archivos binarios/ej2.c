#include <stdio.h>
#include <string.h>

#define MAX_CANCION 50
#define MAX_ARTISTA 100
#define MAX_COLAB 100
#define MAX_GENERO 50

typedef struct cancion{
    char nombre[MAX_CANCION];
    char artista[MAX_ARTISTA];
    char colaborador[MAX_COLAB];
    int duracion;
    int id_genero;
} cancion_t;

typedef struct genero{
    char nombre[MAX_GENERO];
    int id;
} genero_t;

void eliminar_cancion(char nombre_colab[MAX_COLAB], int min_duracion){

    FILE* canciones = fopen("canciones.dat","r");
    FILE* resultado = fopen("canciones_final.dat","w");

    if(canciones == NULL){
        perror("No se pudo leer canciones.dat");
        return;
    }

    if(resultado == NULL){
        perror("No se pudo crear canciones_final.dat");
        return;
    }
    
    cancion_t cancion;
    cancion_t cancion_final;

    size_t leer = fread(&cancion,sizeof(cancion_t),1,canciones);

    while(!feof(canciones)){
        if(strcmp(nombre_colab,cancion.colaborador) == 0){
            if(cancion.duracion > min_duracion){
                fwrite(&cancion_final,sizeof(cancion_t),1,resultado);
            }
        }else{
            fwrite(&cancion_final,sizeof(cancion_t),1,resultado);
        }
        leer = fread(&cancion,sizeof(cancion_t),1,canciones);
    }

    fclose(canciones);
    fclose(resultado);

    remove("canciones.dat");
    rename("canciones_final.dat","canciones.dat");
}

int main(){

    char nombre_colab[MAX_COLAB];
    int min_duracion;

    eliminar_cancion(nombre_colab,min_duracion);

    return 0;
}