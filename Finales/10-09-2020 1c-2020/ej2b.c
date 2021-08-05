#include <stdio.h>

#define MAX_REGISTROS 10

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

//puntajes de secciones del blanco -> binario acceso directo secciones.dat NO ORDENADO -> registro seccion_t -> NO MAS DE 10

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
    seccion_t vector[MAX_REGISTROS];

    int leer_gandalf = fread(&tiro_gandalf,sizeof(tiro_t),1,archivo_gandalf);
    int leer_saruman = fread(&tiro_saruman,sizeof(tiro_t),1,archivo_saruman);

    int tope = fread(vector,sizeof(seccion_t),MAX_REGISTROS,puntajes);

    int contador_gandalf = 0;
    int contador_saruman = 0;

    while(!feof(archivo_gandalf)){
        if(vector[tiro_gandalf.id_seccion].puntaje != -1){
            contador_gandalf += vector[tiro_gandalf.id_seccion].puntaje;
        }
        leer_gandalf = fread(&tiro_gandalf,sizeof(tiro_t),1,archivo_gandalf);
    }

    while(!feof(archivo_saruman)){
        if(vector[tiro_saruman.id_seccion].puntaje != -1){
            contador_saruman += vector[tiro_saruman.id_seccion].puntaje;
        }
        leer_saruman = fread(&tiro_saruman,sizeof(tiro_t),1,archivo_saruman);
    }

    if(contador_gandalf > contador_saruman){
        printf("El nuevo presidente del ministerio es Gandalf!\n");
    }else{
        printf("El nuevo presidente del ministerio es Saruman!\n");
    }

    fclose(archivo_gandalf);
    fclose(archivo_saruman);
    fclose(puntajes);

}
