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

//Archivo de acceso directo -> puedo usar fseek
void mostrar_canciones(char colaborador[MAX_COLAB]){
    FILE* canciones_colab = fopen("canciones.dat","r");
    if(canciones_colab == NULL){
        printf("No se pudo abrir el archivo canciones\n");
        return;
    }

    FILE* generos = fopen("generos.dat","w");
    if(generos== NULL){
        fclose(canciones_colab);
        printf("No se pudo abrir el archivo generos\n");
        return;
    }

    cancion_t cancion;
    genero_t genero;

    size_t leidos = fread(&cancion,sizeof(cancion),1,canciones_colab);
    while(leidos == 1){
        fseek(generos,(cancion.id_genero - 1) * (int)sizeof(cancion_t) , SEEK_SET); //Encuentra lo que quiero y me deja una posicion adelante por eso hago -1
        fread(&genero,sizeof(genero_t),1,generos);

        printf("%s - %s\n", cancion.nombre, genero.nombre);

        leidos = fread(&cancion,sizeof(cancion),1,canciones_colab);
    }

    fclose(canciones_colab);
    fclose(generos);
}

int main(){

    mostrar_canciones("Nico");

    return 0;
}