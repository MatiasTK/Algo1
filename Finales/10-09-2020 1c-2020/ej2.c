#include <stdio.h>

typedef struct tiro {
    int tiro_numero;
    int id_seccion;
} tiro_t;

typedef struct seccion {
    int id_seccion;
    int puntaje;
} seccion_t;

//Tiradas gandalf -> binario secuencial gandalf.dat
//Tiradas saruman -> binario secuencial surman.dat
//Ambos ordenados por numero de tiro de tiro_t

//puntajes de secciones del blanco -> binario acceso directo ordenado por id_seccion secciones.dat -> registro seccion_t

//Si no le dio al blanco el puntaje sera -1 y no sumara puntos

void determinar_presidente(){
    FILE* archivo_gandalf = fopen("gandalf.dat","r");
    FILE* archivo_saruman = fopen("saruman.dat","r");
    FILE* puntajes = fopen("secciones.dat","r");

    if(archivo_gandalf == NULL || archivo_saruman == NULL || puntajes == NULL){
        fclose(archivo_gandalf);
        fclose(archivo_saruman);
        fclose(puntajes);
        perror("No se pudo leer algun archivo\n");
        return;
    }

    tiro_t tiro_gandalf;
    tiro_t tiro_saruman;
    seccion_t seccion;

    int leer_gandalf = fread(&tiro_gandalf,sizeof(tiro_t),1,archivo_gandalf);
    int leer_saruman = fread(&tiro_saruman,sizeof(tiro_t),1,archivo_saruman);

    int puntos_gandalf = 0;
    int puntos_saruman = 0;

    while(!feof(archivo_gandalf)){
        fseek(puntajes,sizeof(seccion_t)*(tiro_gandalf.id_seccion - 1),SEEK_SET);
        if(seccion.puntaje != -1){
            puntos_gandalf += seccion.puntaje;
        }
        leer_gandalf = fread(&tiro_gandalf,sizeof(tiro_t),1,archivo_gandalf);
    }

    while(!feof(archivo_saruman)){
        fseek(puntajes,sizeof(seccion_t)*(tiro_saruman.id_seccion - 1),SEEK_SET);
        if(seccion.id_seccion >= 0 && seccion.puntaje != -1){
            puntos_saruman += seccion.puntaje;
        }
        leer_saruman = fread(&tiro_saruman,sizeof(tiro_t),1,archivo_saruman);
    }

    if(puntos_gandalf > puntos_saruman){
        printf("El nuevo presidente del ministerio es Gandalf!\n");
    }else{
        printf("El nuevo presidente del ministerio es Saruman!\n");
    }

    fclose(archivo_gandalf);
    fclose(archivo_saruman);
    fclose(puntajes);
}
