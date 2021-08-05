#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_RASGO 50
#define MAX_DESCRIPCION 100

typedef struct rasgo {
    char descripcion[MAX_DESCRIPCION];
    bool tiene;
} rasgo_t;

typedef struct personaje {
    char nombre[MAX_NOMBRE];
    rasgo_t rasgos[MAX_RASGO];
    int tope_rasgos;
    bool descartado;
} personaje_t;

const char VACIO = '*';
/*
* PRE: 
*
*/
void encontrar_personaje(personaje_t personaje, char descripcion_obtenida[MAX_DESCRIPCION], bool tiene_obtenido, int tope_fila, int tope_columna){

    int contador_no_descartados;

    for(int i = 0; i < tope_fila; i++){
        for(int j = 0; j < tope_columna; j++){
            if(personaje.nombre[i] != VACIO){
                contador_no_descartados++;
            }
        }
    }


    for(int i = 0; i < tope_fila; i++){
        for(int j = 0; j < tope_columna; j++){
            if(strcmp(personaje.rasgos[i].descripcion, descripcion_obtenida) == 0){
                if(personaje.rasgos[i].tiene != tiene_obtenido){
                    personaje.descartado == true;
                    personaje.nombre[i] = VACIO;
                    contador_no_descartados--;
                }else {
                    personaje.descartado == false;
                }
            }
        }
    }


    if(contador_no_descartados == 1){
        for(int i = 0; i < tope_fila; i++){
            for(int j = 0; j < tope_columna; j++){
                if(personaje.nombre[i] != VACIO){
                    printf("Elegiste a %s", personaje.nombre[i]);
                }
            }
        }
    }

}