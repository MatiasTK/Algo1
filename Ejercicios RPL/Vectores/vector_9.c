#include <stdio.h>
#define MAXIMOS_DESTINOS 100
//Aqui declara las constantes

int cantidad_de_picos(int alturas[MAXIMOS_DESTINOS], int tope){
    
    int cantidad_picos = 0;

    for(int i = 0; i < tope; i++){
        if(i > 0 && i < tope - 1 ){
            if(alturas[i] > alturas[i - 1] && alturas[i] > alturas[i + 1]){
            cantidad_picos++;
            }
        }
    }

    return cantidad_picos;

}

int main(){

    int alturas[MAXIMOS_DESTINOS] = {5, 4, 5, 4, 6, 7, 3, 4, 3, 5};
    int tope = 10;

    cantidad_de_picos(alturas, tope);

    return 0;
}