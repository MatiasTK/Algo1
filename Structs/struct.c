#include <stdio.h>
//                      ES PARA CREAR TU PROPIO TIPO DE DATO COMO EJ INT
typedef struct fecha {      
    int anio;
    char mes;
    unsigned short int dia;
}fecha_t;

int main(){

    fecha_t mi_cumple;
    mi_cumple.anio = 2000;
    mi_cumple.mes = 'N';
    mi_cumple.dia = 29;

    printf("Yo Mati soy del %i\n", mi_cumple.anio);

    return 0;
}