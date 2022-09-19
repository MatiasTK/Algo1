/*
No entiendo que hay que hacer, que tengo dos archivos? son binarios? estan ordenados?
como determino quien es traidor y quien no?
De donde saco la informacion goles para colabs y alumnos? 
Tengo que hacer una union entre archivos?
*/

//Suponiendo que tengo dos archivos de textos ordenado por nombres 
//Suponiendo que los archivos de texto tienen el formato nombre;goles

#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50

//Hago una union ya que si estan en estadisticas alumnos y estadisticas colab significa que es un traidor
int main(){
    FILE* estadisticas_alumnos = fopen("estadisticas_alumnos.txt","r");

    FILE* estadisticas_colabs = fopen("estadisticas_colabs.txt","r");

    FILE* traidores = fopen("traidores.csv","w");

    if(!estadisticas_alumnos || !estadisticas_colabs || !traidores){
        fclose(estadisticas_alumnos);
        fclose(estadisticas_colabs);
        fclose(traidores);
        perror("No se pudo abrir un archivo");
        return -1;
    }

    char nombre_alumno[MAX_NOMBRE];
    char nombre_colab[MAX_NOMBRE];
    int goles_para_colabs;
    int goles_para_alumnos;
    int goles_totales;

    int leer_alumnos = fscanf(estadisticas_alumnos,"%[^;];%i\n",nombre_alumno,&goles_para_colabs);
    int leer_colabs = fscanf(estadisticas_colabs,"%[^;];%i\n",nombre_colab,&goles_para_alumnos);

    while(leer_alumnos == 2 && leer_colabs == 2){
        if(strcmp(nombre_alumno,nombre_colab) == 0){
            goles_totales = goles_para_colabs + goles_para_alumnos;
            fprintf(traidores,"%s;%i;%i;%i\n",nombre_colab,goles_para_colabs,goles_para_alumnos,goles_totales);
            leer_alumnos = fscanf(estadisticas_alumnos,"%[^;];%i\n",nombre_alumno,&goles_para_colabs);
            leer_colabs = fscanf(estadisticas_colabs,"%[^;];%i\n",nombre_colab,&goles_para_alumnos);
        }else if(strcmp(nombre_alumno,nombre_colab) < 0){
            leer_alumnos = fscanf(estadisticas_alumnos,"%[^;];%i\n",nombre_alumno,&goles_para_colabs);
        }else{
            leer_colabs = fscanf(estadisticas_colabs,"%[^;];%i\n",nombre_colab,&goles_para_alumnos);
        }
    }

    fclose(estadisticas_alumnos);
    fclose(estadisticas_colabs);
    fclose(traidores);

    return 0;
}