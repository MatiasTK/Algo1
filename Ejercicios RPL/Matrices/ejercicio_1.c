#include <stdio.h>
#define MAX_TERRENO 10
const char ROSAS = 'R';

void cantidad_arboles(char patio[MAX_TERRENO][MAX_TERRENO]) {
    for(int i = 0; i < MAX_TERRENO; i++){
        for(int j = 0; j < MAX_TERRENO; j++){
            patio[i][j] = ROSAS;
        }
    }
}