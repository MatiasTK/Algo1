#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 100

typedef struct colab {
    char nombre[MAX_NOMBRE];
    int goles_metidos;
    int goles_errados;
    int faltas_cometidas;
    int cantidad_lesiones;
} colab_t;


int main(int argc, char* argv[]){

    int cantidad_goles = atoi(argv[1]); //Ya que el string es un numero y no un char lo convierto en int con la funcion atoi

    FILE* archivo = fopen("colabs.dat","r");
    if(archivo == NULL){
        perror("No se pudo abrir colabs.dat");
        return -1;
    }

    colab_t colab;

    size_t leer = fread(&colab,sizeof(colab_t),1,archivo);

    while((int)leer == 1){
        if(colab.goles_metidos > cantidad_goles){
            printf("%s tiene %i goles metidos, %i goles errados, %i faltas, %i lesiones en total\n",colab.nombre,colab.goles_metidos,colab.goles_errados,colab.faltas_cometidas,colab.cantidad_lesiones);
        }
        leer = fread(&colab,sizeof(colab_t),1,archivo);
    }

    fclose(archivo);

    return 0;
}