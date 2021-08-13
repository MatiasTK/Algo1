#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 100

typedef struct colab {
    char nombre[MAX_NOMBRE];
    int goles_metidos;
    int goles_errados;
    int faltas_cometidas;
    int cantidad_lesiones;
} colab_t;

int main(int argc, char* argv[]){

    FILE* archivo = fopen(argv[1],"r+"); //r+ ya que voy a leerlo y despues modificarlo
    if(archivo == NULL){
        perror("No se pudo abrir colabs.dat");
        return -1;
    }

    FILE* actualizaciones = fopen(argv[2],"r");
    if(actualizaciones == NULL){
        fclose(archivo);
        perror("No se pudo abrir actualizaciones.dat");
        return -1;
    }

    printf("Argumentos analizados: %i\n",argc);

    colab_t colab;
    colab_t actualizacion;

    int leer_colab = fread(&colab,sizeof(colab_t),1,archivo);
    int leer_actualizacion = fread(&actualizacion,sizeof(colab_t),1,actualizaciones);

    while(!feof(archivo)){
        if(strcmp(colab.nombre,actualizacion.nombre) == 0){ //Si los nombres son iguales lo actualizo
            colab.goles_metidos += actualizacion.goles_metidos; //Sumo los parametros viejos a los nuevos
            colab.goles_errados += actualizacion.goles_errados;
            colab.faltas_cometidas += actualizacion.faltas_cometidas;
            colab.cantidad_lesiones += actualizacion.cantidad_lesiones;
            fseek(archivo,sizeof(colab_t)*(-1),SEEK_CUR); //Me voy una posicion anterior ya que estoy adelante
            fwrite(&colab,sizeof(colab_t),1,archivo); //Lo escribo en el archivo original
            int leer_actualizacion = fread(&actualizacion,sizeof(colab_t),1,actualizaciones); //Avanzo en actualizaciones
        }
        int leer_colab = fread(&colab,sizeof(colab_t),1,archivo); //Si no es igual al de actualizaciones avanzo en el original
    }
    fclose(archivo);
    fclose(actualizaciones);

    return 0;
}