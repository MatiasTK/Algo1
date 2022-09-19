#include <stdio.h>
#include <stdbool.h>

const char TRIANGULAR = 'T';
const char CIRCULAR = 'O';
const char CUADRADA = 'C';


const char CARNE = 'C';         // PUEDO REPETIR LETRA PORQUE SON DINSTINTAS CONTANTES QUE LAS DE ARRIBA
const char POLLO = 'P';
const char VEGETAL = 'V';

const int CHICO = 2;
const int MEDIANO = 4;
const int GRANDE = 6;

bool es_forma_valida (char forma){

}

bool es_sabor_valido(char sabor){

}

bool es_tamanio_valido(int tamanio){

}

bool aceptado_por_alma(char forma, char sabor, char tamanio){
    /* bool aceptada = false; */

  /*  if(forma != CUADRADA){
        if(sabor == VEGETAL){
            if(tamanio == CHICO){
                aceptada = true;
        }
    }
  }
*/
  /*  if(forma != CUADRADA && sabor == VEGETAL && tamanio == CHICO){ 
        aceptada = true;
    }
   return aceptada;
}
*/

return (forma != CUADRADA && sabor == VEGETAL && tamanio == CHICO);  // Hace que sea true o false el aceptado por alma 
}

int main(){

    char forma;
    char sabor;
    int tamanio;
    bool aceptada;

    {

    }

    aceptada = aceptado_por_alma(forma,sabor,tamanio);

    if (aceptada == true){
        printf("Alma lo acepto\n");
    } else {
        printf("F por alma\n");
    }

    return 0;
}

// AVISO FALTA CODIGO 