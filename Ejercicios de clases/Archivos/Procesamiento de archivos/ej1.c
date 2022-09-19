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
//Archivo binario -> Mezcla ??? 
int main(){

    FILE* colabs = fopen("colabs.dat","r");
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
    FILE* colabs_nuevo = fopen("colabs_nuevo.dat","w");
    if(colabs_nuevo == NULL){
        printf("No se abrio correctamente colabs_nuevo.dat\n");
        fclose(colabs);
        fclose(actualizaciones);
        return -1;
    }

    colab_t colab;
    colab_t actualizacion;

    size_t leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);
    size_t leidos_actualizacion = fread(&actualizacion,sizeof(colab_t),1,actualizaciones);

    while(leidos_colabs == 1 && leidos_actualizacion == 1){
        int compare = strcmp(colab.nombre, actualizacion.nombre);

        if(compare < 0){
            fwrite(&colab,sizeof(colab_t),1,colabs_nuevo);
            leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);
        }else if(compare > 0){
            fwrite(&actualizacion,sizeof(colab_t),1,colabs_nuevo);
            leidos_colabs = fread(&actualizacion,sizeof(colab_t),1,actualizaciones);
        }else{
            colab.goles_errados += actualizacion.goles_errados;
            colab.goles_metidos += actualizacion.goles_metidos;
            colab.faltas_cometidas += actualizacion.faltas_cometidas;
            colab.cantidad_lesiones += actualizacion.cantidad_lesiones;
            fwrite(&colab, sizeof(colab_t),1,colabs_nuevo);
            leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);
            leidos_actualizacion = fread(&actualizacion,sizeof(colab_t),1,actualizaciones);
        }
    }

    while(leidos_colabs == 1){
        fwrite(&colab,sizeof(colab_t),1,colabs_nuevo);
        leidos_colabs = fread(&colab,sizeof(colab_t),1,colabs);
    }

    while(leidos_actualizacion == 1){
        fwrite(&actualizacion,sizeof(colab_t),1,colabs_nuevo);
        leidos_actualizacion = fread(&actualizacion,sizeof(colab_t),1,actualizaciones);
    }

    fclose(colabs);
    fclose(actualizaciones);
    fclose(colabs_nuevo);

    return 0;
}