#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_NOMBRE 50
#define MAX_DESCRIPCION 100

// Archivo de texto ordenado por nombre del pueblo, luego por nombre de barberia
//Formato: pueblo;nombre de la barbería;tipo de corte que se realizó;puntuación;
//Puntuacion -> de 0 a 5, -1 si no la visito

//EJ: mostrar barberias visitadas agrupadas por el pueblo con un promedio de puntuacion

int promedio_puntos(int puntos_totales, int cantidad_barberias){
    int promedio = 0;
    promedio = puntos_totales / cantidad_barberias;
    return promedio;
}

void mostrar_barberia(){

    FILE* barberias = fopen("barberias.txt","r");

    if(!barberias){
        perror("No se pudo abrir barberias.txt\n");
        return;
    }

    char pueblo[MAX_NOMBRE];
    char nombre_barberia[MAX_NOMBRE];
    char tipo_corte[MAX_DESCRIPCION];
    int puntuacion;

    char pueblo_aux[MAX_NOMBRE];

    int leer = fscanf(barberias,"%[^;];%[^;];%[^;];%i\n",pueblo,nombre_barberia,tipo_corte,&puntuacion);

    strcpy(pueblo_aux,pueblo);

    char pueblo_viejo[MAX_NOMBRE];

    while(leer == 4){
        printf("Pueblo: %s\n",pueblo);

        int puntos_totales = 0;
        int cantidad_barberias = 0;
        strcpy(pueblo_viejo,pueblo);
        strcpy(pueblo_aux,pueblo);

        while(leer == 4 && strcmp(pueblo,pueblo_aux) == 0){
            if(puntuacion != -1){
                printf("%s: %i puntos.\n",nombre_barberia,puntuacion);
                puntos_totales += puntuacion;
                cantidad_barberias++;
            }
            strcpy(pueblo_aux,pueblo);
            leer = fscanf(barberias,"%[^;];%[^;];%[^;];%i\n",pueblo,nombre_barberia,tipo_corte,&puntuacion);
        }
        printf("Promedio barberias %s: %i puntos.\n",pueblo_viejo,promedio_puntos(puntos_totales,cantidad_barberias));
        printf("------------------------------------\n");
        strcpy(pueblo_viejo,pueblo);
    }

    fclose(barberias);

}

int main(){

    mostrar_barberia();

    return 0;
}