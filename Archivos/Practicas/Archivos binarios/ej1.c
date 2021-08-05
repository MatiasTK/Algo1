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

void imprimir_cancion(char nombre_colab[MAX_COLAB]){
    FILE* canciones = fopen("canciones.dat","r");

    if(canciones == NULL){
        perror("No se pudo abrir canciones.dat");
        return;
    }

    cancion_t cancion;

    size_t leer = fread(&cancion,sizeof(cancion_t),1,canciones);

    printf("Canciones elegidas por %s: \n",nombre_colab);

    while(!feof(canciones)){
        if(strcmp(nombre_colab,cancion.colaborador) == 0){
            printf("%s de %s",cancion.nombre, cancion.artista);
        }
        leer = fread(&cancion,sizeof(cancion_t),1,canciones);
    }

    fclose(canciones);
}

int main(){

    char nombre_colab[MAX_COLAB];

    imprimir_cancion(nombre_colab);

    return 0;
}