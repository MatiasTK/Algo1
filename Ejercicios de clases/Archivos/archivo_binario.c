#include <stdio.h>
#include <stdbool.h>

#define MAX_NOMBRE 25

typedef struct pelicula{
    char nombre[MAX_NOMBRE];
    short anio;
    bool pasa_bechdel_test;
    char opinion;   // B: Bueno, R: Regular, M: Malo
}   pelicula_t;

    void pedir_pelicula(pelicula_t* pelicula){
        printf("Nombre de pelicula: \n");
        scanf("%[^\n]", pelicula->nombre);
        printf("Año: \n");
        scanf("%hi", &pelicula->anio);
        printf("¿Pasa el test de bechdel?\n");
        printf("S para si, N para no.\n");
        char respuesta;
        scanf(" %c", &respuesta);
        pelicula->pasa_bechdel_test = respuesta == 'S';
        printf("¿Cual fue tu opinion?");
        printf("B: Bueno, R: Regular, M: Malo\n");
        scanf(" %c", &pelicula->opinion);
    }

int main(){

    FILE* resenias = fopen("reseñas.dat", "a"); //a -> append, no borra los archivo, empieza escribiendo desde el final

    if(resenias == NULL){
        printf("No se puede abrir el archivo.\n");
        return -1;
    }

    pelicula_t pelicula;
    pedir_pelicula(&pelicula);

    fwrite(&pelicula, sizeof(pelicula_t), 1, resenias); // Recibe la pelicula, el tamaño de la pelicula, cantidad de peliculas, lo que va a escribir al final

    fclose(resenias);
    return 0;
}