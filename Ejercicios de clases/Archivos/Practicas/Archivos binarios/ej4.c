#include <stdio.h>
#include <string.h>

#define MAX_CANCION 50
#define MAX_ARTISTA 100
#define MAX_COLAB 100
#define MAX_GENERO 50

#define MAX_GENEROS 20

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

void bubble_sort(genero_t vector[MAX_GENEROS],int tope){
    int i,j;

    genero_t aux;

    for(i = 0; i < tope; i++){
        for(j = 0; j < (tope-i-1); j++){
            if(strcmp(vector[j].nombre,vector[j+1].nombre) > 0){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

void ordenar_generos(){
    FILE* generos = fopen("generos.dat","r");

    if(generos == NULL){
        perror("No se pudo abrir generos.dat");
        return;
    }

    genero_t vector_generos[MAX_GENEROS];
    size_t tope = fread(vector_generos,sizeof(genero_t),MAX_GENEROS,generos);

    fclose(generos);

    bubble_sort(vector_generos,(int)tope);

    FILE* resultado = fopen("generos_final.dat","w");
    if(resultado == NULL){
        perror("No se pudo crear generos_final.dat");
        return;
    }

    fwrite(vector_generos,sizeof(genero_t),tope,resultado);

    fclose(resultado);

    // remove("generos.dat");
    // rename("generos_final.dat","generos.dat");
}

void leer_binario(){
    FILE* archivo = fopen("generos_final.dat","r");
    if(archivo == NULL){
        perror("No se pudo abrir generos_final.dat");
        return;
    }

    FILE* texto = fopen("generos_final.csv","w");
    if(!texto){
        fclose(archivo);
        perror("No se pudo crear generos_final.txt");
        return;
    }

    genero_t genero;

    size_t leer = fread(&genero,sizeof(genero_t),1,archivo);

    while(leer == 1){
        fprintf(texto,"%s;%i\n",genero.nombre,genero.id);
        leer = fread(&genero,sizeof(genero_t),1,archivo);
    }

    fclose(archivo);
    fclose(texto);
}

int main(){

    ordenar_generos();
    leer_binario();

    return 0;
}