#include <stdio.h>
#include <stdbool.h>

#define MAX_NOMBRE 25

typedef struct pelicula{
    char nombre[MAX_NOMBRE];
    short anio;
    bool pasa_bechdel_test;
    char opinion;   // B: Bueno, R: Regular, M: Malo
}   pelicula_t;

void imprimir_pelicula(pelicula_t pelicula){
    printf("-------------------------------------------\n");
    printf("Nombre: %s\n", pelicula.nombre);
    printf("Año: %hi\n", pelicula.anio);
    if(pelicula.pasa_bechdel_test){
        printf("¿Pasa el test de bechdel? Si\n");
    }else{
        printf("¿Pasa el test de bechdel? No\n");
    }
    printf("Opinion: %c\n", pelicula.opinion);
}

int main(){

    FILE* resenias = fopen("reseñas.dat", "r");
    if(resenias == NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
    pelicula_t pelicula;

    int leidos = fread(&pelicula, sizeof(pelicula_t),1,resenias);

    while(leidos > 0){ //Cuando falla o termina devuelve 0
        imprimir_pelicula(pelicula);  
        leidos = fread(&pelicula, sizeof(pelicula_t),1,resenias);
    }


    fclose(resenias);

    return 0;
}