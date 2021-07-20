//---------------------------- NO esta completo -----------------------------------
#include <stdio.h>
#include <stdbool.h>
#define PATH_COLABS "colabs.dat"
#define MAX_NOMBRE 50

typedef struct colaborador{
    int id;
    int nombre[MAX_NOMBRE];
    bool es_vegano;
    bool tiene_coche;
} colaborador_t;


void hacer_vegano(char path[MAX_PATH], int id){ //En caso de tener un archivo ordenado
    FILE* archivo = fopen(path, "r+"); // r+ porque queremos leer y modificarlo, W+ lo rehace el archivo por eso no nos sirve
    if(archivo == NULL){
        printf("No se pudo abrir el archivo\n");
        return -1;
    }

    fseek(archivo,id*sizeof(colaborador_t),SEEK_SET); //fseek seria -> (Archivo a abrir, hasta donde leer, de donde empezar) nos paramos en la posicion ID
    // Seek set me para al principio del archivo, id*sizeof(colaborador_t) me busca el id que quiero * el tamaño ya que lo tenemos que pasar a bytes
    colaborador_t aux;
    int leido = fread(&aux,sizeof(colaborador_t),1,archivo); //Guardamos la posicion del ID
    if(leido == 0){
        printf("No se pudo acceder al archivo");
        fclose(archivo);
        return -1;
    }
    aux.es_vegano = true; //Lo hago vegano
    fseek(archivo,-(sizeof(colaborador_t)),SEEK_CUR); //Como el primer seek me dejo una posicion adelantada vuelvo para atras desde la inicial
    fwrite(&aux,sizeof(colaborador_t),1,archivo); //Escribo los cambios en el archivo

    fclose(archivo);
}

int main(){



    return 0;
}