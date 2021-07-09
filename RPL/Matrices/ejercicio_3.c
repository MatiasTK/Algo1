#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
const char HUESO = 'H';

bool quedan_huesos(char parque[MAX_FILAS][MAX_COLUMNAS]) {

    bool resultado = false;

    for(int i = 0; i <= MAX_FILAS; i++){
        for(int j = 0; j <= MAX_COLUMNAS; j++){
            if(parque[i][j] == HUESO){
                resultado = true;
            }
        }
    }

    return resultado;
}