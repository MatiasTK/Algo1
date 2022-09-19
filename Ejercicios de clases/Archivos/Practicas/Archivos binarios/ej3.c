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


void imprimir_canciones(char colaborador_buscado[MAX_COLAB]){
    FILE* canciones = fopen("canciones.dat","r");
    FILE* generos = fopen("generos.dat","r");

    if(canciones == NULL){
        perror("No se pudo abrir canciones.dat");
        return;
    }

    if(generos == NULL){
        perror("No se pudo abrir generos.dat");
        return;
    }

    cancion_t cancion;
    genero_t genero;

    size_t leer = fread(&cancion,sizeof(cancion_t),1,canciones);

    printf("Las canciones elegidas por %s son: \n",colaborador_buscado);

    while(!feof(canciones)){
        if(strcmp(cancion.colaborador,colaborador_buscado) == 0){
            fseek(generos,(int)sizeof(genero_t) * (cancion.id_genero - 1), SEEK_SET);
            printf("Nombre: %s, Genero: %s",cancion.nombre,genero.nombre);
        }
        leer = fread(&cancion,sizeof(cancion_t),1,canciones);
    }

    fclose(canciones);
    fclose(generos);
}

int main(){

    char colab_buscado[MAX_COLAB];

    imprimir_canciones(colab_buscado);

    return 0;
}