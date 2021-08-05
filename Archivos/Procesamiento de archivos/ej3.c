#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NOMBRE 50

typedef struct colab {
    char nombre[MAX_NOMBRE];
    int goles_metidos;
    int goles_errados;
    int faltas_cometidas;
    int cantidad_lesiones;
} colab_t;

int main(int argc, char* argv[]){

    FILE* colabs = fopen(argv[1],"r+");
    if(colabs == NULL){
        printf("No se abrio correctamente colabs.dat\n");
        return -1;
    }

    colab_t colab;

    size_t leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);

    int cantidad_minima_goles = atoi(argv[2]); // convierte array en entero

    printf("Cantidad minima goles: %i\n",cantidad_minima_goles);

    while(leidos_colabs == 1){
        if(colab.goles_metidos <= cantidad_minima_goles){
            printf("%s - %i - %i - %i - %i\n", colab.nombre, colab.goles_metidos, colab.goles_errados, colab.faltas_cometidas, colab.cantidad_lesiones);
        }
        leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);
    }

    fclose(colabs);

    return 0;
}