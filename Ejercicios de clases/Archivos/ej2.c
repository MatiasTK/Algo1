#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 50

const int ERROR = -1;

typedef struct firma{
    char nombre[MAX_NOMBRE];
    int voto;
} firma_t;

void borrar_repetidos(firma_t firma){


}

int main(){

    FILE* firmas = fopen("firmas_para_la_liberacion_del_insta.txt", "r");

    if(!firmas){
        printf("No se pudo abrir el archivo, fijate bien no seas gil\n");
        return ERROR;
    }

    FILE* firmas_aux = fopen("firmas_para_la_liberacion_del_insta_aux.txt", "w");
    
    if(!firmas_aux){
        printf("No se pudo abrir el archivo auxiliar");
        fclose(firmas);
        return ERROR;
    }

    firma_t firma;
    bool hay_charly = false;

    int leidos = fscanf(firmas,"%[^;];%i\n",firma.nombre,&(firma.voto));

    while(leidos == 2){
        if(strcmp(firma.nombre, "Charly") != 0 || !hay_charly){
            fprintf(firmas_aux,"%s;%i\n", firma.nombre, firma.voto);
            if(strcmp(firma.nombre, "Charly") == 0){
                hay_charly = true;
            }
        }
        leidos = fscanf(firmas,"%[^;];%i\n",firma.nombre,&(firma.voto));
    }

    leidos = fscanf(firmas,"%[^;];%i\n",firma.nombre,&(firma.voto));

    while(leidos == 2){
        if(firma.voto == 0){
            printf("%s votó en contra. No hay helado para él. >:c\n", firma.nombre);
        }else{
            printf("%s votó a favor! Ya te mando el cuarto de helado prometido.\n", firma.nombre);
        }
        leidos = fscanf(firmas,"%[^;];%i\n",firma.nombre,&(firma.voto));
    }

    fclose(firmas);
    fclose(firmas_aux);

    rename("firmas_para_la_liberacion_del_insta_aux.txt", "firmas_para_la_liberacion_del_insta.txt");

    return 0;
}