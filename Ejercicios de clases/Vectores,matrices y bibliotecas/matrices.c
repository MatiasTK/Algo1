#include <stdio.h>
//                                                          EL CODIGO NO ESTA COMPLETO ES UN EJEMPLO DE MATRIZ
const char BELLOTA = 'e';
const char BURBUJA = 'n';
const int MAX_BALDOSAS = 10;
const int ENCONTRE = 1;
const int NO_ENCONTRE = 0;


void recorrido(char cuarto[MAX_BALDOSAS][MAX_BALDOSAS], int fil, int col, int tope_cuarto){

}

int cuarto_oscuro(int tope_cuarto, char cuarto[MAX_BALDOSAS][MAX_BALDOSAS]){    // EN ESTA FUNCION RECORRE LA MATRIZ BUSCANDO "e" O "n" 
    bool encontre=false;
    for(int i = 0; i < tope_cuarto; i++){           // me ubica en la fila
        for(int j = 0; j < tope_cuarto; j++){       // me ubica en la columna
            if(cuarto[i][j] == BELLOTA || cuarto[i][j] == BURBUJA){
                encontre = true;
                printf("te encontre %c \n" cuarto[i][j]);
            }
            recorrido(cuarto, i, j, tope_cuarto);
        }
    }
    if(ENCONTRE)return ENCONTRE;
}

main(){


    return 0;
}