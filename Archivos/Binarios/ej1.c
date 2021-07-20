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

#define COLAB "Jorge"

void imprimir_canciones(FILE* canciones){

    cancion_t cancion;
    printf("Canciones que escucha %s:\n", COLAB);

    int leidos = fread(&cancion, sizeof(cancion_t),1,canciones); //Devuelve 0 si falla o termina de leer

    while(leidos != 0){
        if(strcmp(cancion.colaborador,COLAB) == 0){
            printf("- %s : %s\n",cancion.artista,cancion.nombre); 
        }
        leidos = fread(&cancion,sizeof(cancion_t),1,canciones);
    }       
}

void imprimir_canciones_alt(FILE* canciones, char nombre[MAX_COLAB]){
    cancion_t cancion;
    printf("Canciones que escucha %s:\n", nombre);

    int leidos = fread(&cancion,sizeof(cancion_t),1,canciones);

    while(!feof(canciones)){
        if(strcmp(cancion.colaborador,nombre) == 0){
            printf("- %s : %s\n",cancion.artista,cancion.nombre); 
        }
        leidos = fread(&cancion,sizeof(cancion_t),1,canciones);
    }   
}

int main(){

    FILE* canciones = fopen("canciones.dat","r");

    if(canciones == NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }

    imprimir_canciones(canciones); //Es mejor este para archivos de texto
    imprimir_canciones_alt(canciones,COLAB);

    fclose(canciones);

    return 0;
}