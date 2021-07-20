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

void quitar_canciones(char colaborador[MAX_COLAB], int duracion){
    FILE* canciones_colab = fopen("canciones.dat","r");
    if(canciones_colab == NULL){
        printf("No se pudo abrir el archivo canciones\n");
        return;
    }
    
    FILE* canciones_aux = fopen("canciones_aux.dat","w");
    if(canciones_aux == NULL){
        fclose(canciones_colab);
        printf("No se pudo abrir el archivo canciones_aux\n");
        return;
    }

    cancion_t cancion;

    int leidos = fread(&cancion,sizeof(cancion_t),1,canciones_colab);
    while(leidos == 1){

        if(strcmp(cancion.colaborador, "Charly") != 0 || cancion.duracion < duracion){
            fwrite(&cancion,sizeof(cancion_t),1,canciones_colab);
        }

        leidos = fread(&cancion,sizeof(cancion_t),1,canciones_colab);
    }

    fclose(canciones_colab);
    fclose(canciones_aux);
    rename("canciones_aux.dat","canciones.dat");

}

int main(){

    int duracion_buscada = 5;

    quitar_canciones("Nico",duracion_buscada);

    return 0;
}