#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COLAB 50
#define MAX_GENERO 30
#define MAX_CANCION 100
#define MAX_ARTISTA 100

//Si cambio el orden del struct va a imprimir cualquier cosa ya que cambio de lugar los bytes
typedef struct cancion {
    char nombre[MAX_CANCION];
    char artista[MAX_ARTISTA];
    char colaborador[MAX_COLAB];
    int duracion;
    int id_genero;
} cancion_t;

typedef struct genero {
    char nombre[MAX_GENERO];
    int id;
} genero_t;

int main(){

    FILE* generos = fopen("genero.dat","r");
    if(generos == NULL){
        printf("No se pudo abrir generos");
        return -1;
    }

    genero_t generos_vector[MAX_GENERO];

    size_t tope = fread(&generos_vector,sizeof(genero_t),MAX_GENERO,generos); // Nos va a devolver el tope(la cantidad de elementos que hay en el maximo)

    while(tope == 1){

        tope = fread(&generos_vector,sizeof(genero_t),MAX_GENERO,generos);
    }

    fclose(generos);

    for(int i = 0; i < tope; i++){
        printf("Genero: %i - %s\n",generos_vector[i].id,generos_vector[i].nombre);
    }

    FILE* generos_escritura = fopen("genero.dat","w");
    if(generos_escritura == NULL){
        printf("No se pudo abrir generos");
        return -1;
    }

    fwrite(generos_vector,sizeof(genero_t),tope, generos_escritura);

    fclose(generos_escritura);
}