#include <stdio.h>
#define MAX_HABILIDADES 4

int agente_mas_habil(int habilidades_1[MAX_HABILIDADES], int habilidades_3[MAX_HABILIDADES], int habilidades_5[MAX_HABILIDADES]){
	int suma_habilidades_1 = habilidades_1[0] + (3 * habilidades_1[1]) + (2 * habilidades_1[2]) + habilidades_1[3];
    int suma_habilidades_3 = habilidades_3[0] + (3 * habilidades_3[1]) + (2 * habilidades_3[2]) + habilidades_3[3];
    int suma_habilidades_5 = habilidades_5[0] + (3 * habilidades_5[1]) + (2 * habilidades_5[2]) + habilidades_5[3];

    if(suma_habilidades_1 > suma_habilidades_3 && suma_habilidades_1 > suma_habilidades_5){
        return 1;
    } else if(suma_habilidades_3 > suma_habilidades_1 && suma_habilidades_3 > suma_habilidades_5){
        return 3;
    } else {
        return 5;
    }
    
}