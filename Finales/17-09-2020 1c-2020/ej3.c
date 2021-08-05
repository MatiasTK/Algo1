#include <stdio.h>

#define MAX_MARCA 50

typedef struct zapatilla {
    int codigo;
    char marca[MAX_MARCA];
    int talle;
    char color_cordon;
    char armario;
} zapatilla_t ;

typedef struct zapatilla2 {
    int codigo;
    char marca[MAX_MARCA];
    int talle;
    char color_cordon;
    char armario;
} zapatilla2_t ;
/*
* PRE: armario_1 y armario_2 deben ser binarios ordenados por codigo y cerrados en otro lugar
* POST: Devuelve -1 si no pudo abrir el archivo , 0 si no pudo completar el par, un numero si completo el par y la diferencia de colores de cordones
*/
int zapatillas(FILE* armario_1, FILE* armario_2){

    FILE * sin_par = fopen("sin_par","w");

    if(sin_par == NULL){
        fprintf("No se pudo crear sin_par");
        return -1;
    }

    zapatilla_t zapatilla;
    zapatilla2_t zapatilla2;

    int cordones_color = 0;

    int leer_armario = fread(&zapatilla,sizeof(zapatilla_t),1,armario_1);
    int leer_armario2 = fread(&zapatilla2,sizeof(zapatilla_t),1,armario_2);
// DIFERENCIA DE ARCHIVOS PARA ENCONTRAR ZAPATILLAS QUE NO ESTEN EN EL OTRO
    while(!feof(armario_1) && !feof(armario_2)){
        if(zapatilla.codigo == zapatilla2.codigo){
            if(zapatilla.color_cordon != zapatilla2.color_cordon){
                cordones_color++;
            }
            leer_armario = fread(&zapatilla,sizeof(zapatilla_t),1,armario_1);
            leer_armario2 = fread(&zapatilla2,sizeof(zapatilla_t),1,armario_2);
        }else if(zapatilla.codigo < zapatilla2.codigo){
            fwrite(&zapatilla,sizeof(zapatilla_t),1,sin_par);
            leer_armario = fread(&zapatilla,sizeof(zapatilla_t),1,armario_1);
        }else{
            leer_armario2 = fread(&zapatilla2,sizeof(zapatilla_t),1,armario_2);
        }
    }

    if(feof(armario_2)){
        while(!feof(armario_1)){
            fwrite(&zapatilla,sizeof(zapatilla_t),1,sin_par);
            leer_armario = fread(&zapatilla,sizeof(zapatilla_t),1,armario_1);
        }
    }

    return cordones_color;
}