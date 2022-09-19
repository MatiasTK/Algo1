#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//norte.dat y sur.dat binarios acceso secuencial

//reputaciones.dat binario acceso aleatorio ordenado por id_reputacion y de reputacion_t


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

//generar ->Formato: nombre;cantidad_visitas;porcentaje_de_veces_que_trajo_regalo;descripcion_reputacion

int contar_regalos(visiante_t visitante, int tope){
    int contador = 0;

    for(int i = 0; i < tope; i++){
        if(visitante.visitas[i].trajo_regalos == true){
            contador++;
        }
    }

    return contador;
}

int porcentaje_regalo(int visitas, int regalos){
    int porcentaje = (regalos * 100) / visitas;
    return porcentaje;
}

/*
* PRE:
* POST: Devuelve -1 si no pudo abrir algun archivo o 0 si se ejecuto el codigo correctamente
*/
int unificar_archivos(){

    FILE* generar = fopen("visitantes.csv","w");

    FILE* norte = fopen("norte.dat","r");

    FILE* sur = fopen("sur.dat","r");

    FILE* reputaciones = fopen("reputaciones.dat","r");

    if(!generar || !norte || !sur || !reputaciones){
        fclose(generar);
        fclose(norte);
        fclose(sur);
        fclose(reputaciones);
        perror("No se pudo abrir algun archivo\n");
        return -1;
    }

    visiante_t visitantes1;
    visiante_t visitantes2;
    reputacion_t reputacion;

    int regalos_total;
    int cantidad_visitas;

    size_t leer_sur = fread(&visitantes1,sizeof(visiante_t),1,sur);
    size_t leer_norte = fread(&visitantes2,sizeof(visiante_t),1,norte);

    while(!feof(norte) && !feof(sur)){
        if(strcmp(visitantes1.nombre, visitantes2.nombre) == 0){
            regalos_total = contar_regalos(visitantes1,visitantes1.cantidad_visitas) + contar_regalos(visitantes2,visitantes2.cantidad_visitas); // calculo el total de regalos
            cantidad_visitas = visitantes1.cantidad_visitas + visitantes2.cantidad_visitas;
            fseek(reputaciones,sizeof(reputacion_t) * (visitantes1.id_reputacion -1),SEEK_SET); // busco el id de reputacion
            fread(&reputacion, sizeof(reputacion_t),1,reputaciones);
            fprintf(generar,"%s;%i;%i;%s\n", visitantes1.nombre, cantidad_visitas, porcentaje_regalo(cantidad_visitas,regalos_total),reputacion.descripcion);
            leer_sur = fread(&visitantes1,sizeof(visiante_t),1,sur);
            leer_norte = fread(&visitantes2,sizeof(visiante_t),1,norte);
        }else if(strcmp(visitantes1.nombre, visitantes2.nombre) > 0){
            regalos_total = contar_regalos(visitantes1,visitantes1.cantidad_visitas);
            cantidad_visitas = visitantes1.cantidad_visitas;
            fseek(reputaciones,sizeof(reputacion_t) * (visitantes1.id_reputacion -1),SEEK_SET);
            fprintf(generar,"%s;%i;%i;%s\n", visitantes1.nombre, cantidad_visitas, porcentaje_regalo(cantidad_visitas,regalos_total),reputacion.descripcion);
            leer_sur = fread(&visitantes1,sizeof(visiante_t),1,sur);
        }else if(strcmp(visitantes1.nombre, visitantes2.nombre) < 0){
            regalos_total = contar_regalos(visitantes2,visitantes2.cantidad_visitas);
            cantidad_visitas = visitantes2.cantidad_visitas;
            fseek(reputaciones,sizeof(reputacion_t) * (visitantes2.id_reputacion -1), SEEK_SET);
            fprintf(generar,"%s;%i;%i;%s\n", visitantes1.nombre, cantidad_visitas, porcentaje_regalo(cantidad_visitas,regalos_total),reputacion.descripcion);
            leer_norte = fread(&visitantes2,sizeof(visiante_t),1,norte);
        }
    }

    while(!feof(norte)){
            regalos_total = contar_regalos(visitantes2,visitantes2.cantidad_visitas);
            cantidad_visitas = visitantes2.cantidad_visitas;
            fseek(reputaciones,sizeof(reputacion_t)*(visitantes2.id_reputacion -1), SEEK_SET);
            fprintf(generar,"%s;%i;%i;%s\n", visitantes1.nombre, cantidad_visitas, porcentaje_regalo(cantidad_visitas,regalos_total),reputacion.descripcion);
            leer_norte = fread(&visitantes2,sizeof(visiante_t),1,norte);
    }

    while(!feof(sur)){
            regalos_total = contar_regalos(visitantes1,visitantes1.cantidad_visitas);
            cantidad_visitas = visitantes1.cantidad_visitas;
            fseek(reputaciones,sizeof(reputacion_t) * (visitantes1.id_reputacion -1),SEEK_SET);
            fprintf(generar,"%s;%i;%i;%s\n", visitantes1.nombre, cantidad_visitas, porcentaje_regalo(cantidad_visitas,regalos_total),reputacion.descripcion);
            leer_sur = fread(&visitantes1,sizeof(visiante_t),1,sur);
    }


    fclose(generar);
    fclose(norte);
    fclose(sur);
    fclose(reputaciones);

    return 0;
}