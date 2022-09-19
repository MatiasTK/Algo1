#include "solucion.h"
#include <stdbool.h>

const char LENTO = 'L';
const char MUY_LENTO = 'M';
const char RAPIDO = 'R';

typedef struct empleados {
	int delay_en_entregar; //en minutos
	bool estan_de_franco;
} empleados_t;

typedef struct restaurante{
	empleados_t empleados;
	bool cerrado;
	bool es_de_comida_rapida;
} restaurante_t;

char velocidad_del_restaurante(restaurante_t restaurante) {
    char condicion_1;
    char condicion_2;
    char condicion_3;
    char condicion_4;

    bool contiene_lento = false;
    bool contiene_muy_lento = false;

    char resultado = RAPIDO;

    if(restaurante.empleados.delay_en_entregar > 5){
        condicion_1 = LENTO;
    }
    if(restaurante.empleados.estan_de_franco == true){
        condicion_2 = MUY_LENTO;
    }
    if(restaurante.cerrado == true){
        condicion_3 = MUY_LENTO;
    }
    if(restaurante.es_de_comida_rapida == false){
        condicion_4 = LENTO;
    }

    char vector_condicion[4] = {condicion_1, condicion_2, condicion_3, condicion_4};


    // SI EJECUTAS ESTO PASA LAS PRUEBAS AUNQUE ESTA MAL! 
    // for(int i = 0; i < 4; i++){                                          
    //     if(vector_condicion[i] == MUY_LENTO){
    //         resultado = MUY_LENTO;
    //         break;
    //     } else if(vector_condicion[i] == LENTO){                  
    //         resultado = LENTO;
    //         break;
    //     } else {
    //         resultado = RAPIDO;
    //     }
    // }

    for(int i = 0; i < 4; i++){
        if(vector_condicion[i] == LENTO){
            contiene_lento = true;
        } else if(vector_condicion[i] == MUY_LENTO){
            contiene_muy_lento = true;
        }
    }

    if(contiene_muy_lento == true){
        resultado = MUY_LENTO;
    } else if(contiene_lento == true && contiene_muy_lento == false){
        resultado = LENTO;
    }


    return resultado;
}

int main(){

    restaurante_t restaurante;
    restaurante.empleados.delay_en_entregar = 7;
    restaurante.empleados.estan_de_franco = true;
    restaurante.cerrado = true;
    restaurante.es_de_comida_rapida = false;

    velocidad_del_restaurante(restaurante);

    return 0;
}