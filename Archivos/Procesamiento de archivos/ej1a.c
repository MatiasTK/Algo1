#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 50

typedef struct colab {
    char nombre[MAX_NOMBRE];
    int goles_metidos;
    int goles_errados;
    int faltas_cometidas;
    int cantidad_lesiones;
} colab_t;
//Igual que ej1 pero aca asumimos que no hay colaboradores nuevos
int main(){

    FILE* colabs = fopen("colabs.dat","r+");
    if(colabs == NULL){
        printf("No se abrio correctamente colabs.dat\n");
        return -1;
    }
    FILE* actualizaciones = fopen("actualizaciones.dat","r");
    if(actualizaciones == NULL){
        printf("No se abrio correctamente actualizaciones.dat\n");
        fclose(colabs);
        return -1;
    }

    colab_t colab;
    colab_t actualizacion;

    size_t leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);
    size_t leidos_actualizacion = fread(&actualizacion, sizeof(colab_t),1,actualizaciones);

    while(leidos_colabs == 1){
        //Si coinciden, hago los cambios en colabs y avanzo en actualizacion
        if(strcmp(colab.nombre, actualizacion.nombre) == 0){
            colab.goles_errados += actualizacion.goles_errados;
            colab.goles_metidos += actualizacion.goles_metidos;
            colab.faltas_cometidas += actualizacion.faltas_cometidas;
            colab.cantidad_lesiones += actualizacion.cantidad_lesiones;
            fseek(colabs,(-1)*(int)sizeof(colab_t), SEEK_CUR); // me muevo una posicion atras
            fwrite(&colab,sizeof(colab_t),1,colabs);
            leidos_actualizacion = fread(&actualizacion, sizeof(colab_t),1,actualizaciones);
        }
        leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);
    }

    fclose(colabs);
    fclose(actualizaciones);

    return 0;
}