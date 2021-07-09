#include <stdio.h>
#include <stdbool.h>
#include <string.h>
                            //FALTAN MUCHAS COSAS
#define MAX_NOMBRE 30
#define MAX_INGREDIENTES 10
#define MAX 5

typedef struct  ingrediente
{
 
}íngrediente_t;



bool renata_aprueba(receta_t receta){
    int i = 0;
    bool receta_apta = true;

    while(receta_apta && i < receta.cant_ingredientes){
        if(!receta.ingredientes[i].es_vegano || !receta.ingredientes[i].sin_tacc){
            receta_apta = false;
        }
        i++;
    }
    return receta_apta;
}

void imprimir_receta(receta_t receta){
    printf("Nombre: %s\n", receta.nombre);

}


int encontrar_renata_receta(receta_t libro_recetas[MAX_RECETAS], int tope){
    int i = 0;
    bool encontre_receta = false;

    while(i < tope && !encontre_receta){        // USO ELSE PARA QUE CUANDO LA FUNCION ENCUENTRE UNA RECETA i SEA LA POSICION DE LA RECETA Y NO SE SIGA SUMANDO
        if(renata_aprueba(libro_recetas[i])){
            encontre_receta = true;
        } else {
            i++;
        }
    }
    return i;
}



int main(){




    return 0;
}