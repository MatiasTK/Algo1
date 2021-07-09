#include <stdio.h>
#define MAXIMOS_DIAS 7

int dia_record(int adoptados[MAXIMOS_DIAS], int tope){
    int dia_record = tope - 1;
    int mayor = adoptados[6];

    for(int i = tope; i > -1; i--){
        if(adoptados[i] > mayor){
            mayor = adoptados[i];
            dia_record = i;
        }
    }


    return dia_record;
}

int main(){

    int adoptados[MAXIMOS_DIAS] = {60,6,6,6,6,6,6};
    int tope = 7;

    dia_record(adoptados,tope);

    return 0;

}