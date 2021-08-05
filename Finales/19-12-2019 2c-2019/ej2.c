#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FECHA 8
#define MAX_VISITAS 10
#define MAX_NOMBRE 50
#define MAX_DESCRIPCION 100

typedef struct visita {
    char fecha[MAX_FECHA]; // formato AAAAMMDD
    bool trajo_regalos;
} visita_t;

typedef struct visitante {
    char nombre[MAX_NOMBRE];
    visita_t visitas[MAX_VISITAS];
    int cantidad_visitas;
    int id_reputacion;
} visiante_t;

typedef struct reputacion {
    int id_reputacion;
    char descripcion[MAX_DESCRIPCION];
} reputacion_t;

void ordenar_reputacion(){
    FILE* visitantes = fopen("visitantes.csv","r");
    if(!visitantes){
        perror("No se pudo abrir visitantes.csv");
        return;
    }

    reputacion_t reputacion;
    char nombre[MAX_NOMBRE];
    int cantidad_visitas;
    int porcentaje_regalo;
    char descripcion_rep[MAX_DESCRIPCION];

    int leidos = fscanf(visitantes,"%[^;];%i;%i;%[^;]\n",nombre,&cantidad_visitas,&porcentaje_regalo,descripcion_rep);

    char descripcion_aux[MAX_DESCRIPCION];
    strcpy(descripcion_aux,descripcion_rep);

    while(leidos == 4){
        printf("Reputacion: %s\n",descripcion_rep);
        int contador_mas = 0;
        int contador_menos = 0;
        while((leidos == 4) && strcmp(descripcion_rep,descripcion_aux) == 0){
            printf("Nombre: %s", nombre);
            if(porcentaje_regalo > 50){
                contador_mas++;
            }else if(porcentaje_regalo < 50){
                contador_menos++;
            }
            strcpy(descripcion_aux,descripcion_rep);
            leidos = fscanf(visitantes,"%[^;];%i;%i;%[^;]\n",nombre,&cantidad_visitas,&porcentaje_regalo,descripcion_rep);
        }
        printf("Trajeron regalo: \n");
        printf("Mas del 50%%  de las veces: %i \n",contador_mas);
        printf("Menos del 50%% de las veces: %i \n",contador_menos);
    }

    fclose(visitantes);
}

int main(){

    ordenar_reputacion();

    return 0;
}