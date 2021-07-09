#ifndef __EJERCICIO_1_
#define __EJERCICIO_1_

#define MAX_NOMBRE 50
#define MAX_COLABS 23


typedef struct colaborador
{
    char nombre[MAX_NOMBRE];
    int fil;
    int col;
}colaborador_t;

void imprimir_posicion(colaborador_t colabs[MAX_COLABS], int cantidad_colabs,char nombre_buscado[MAX_COLABS]);

void cargar_vector(colaborador_t colabs[MAX_COLABS], int* cantidad_colabs);

#endif // __EJERCICIO_1_


// ES UN EJEMPLO DE BIBLIOTECA NO LA ESTOY USANDO.