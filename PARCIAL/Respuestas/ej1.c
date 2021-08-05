#include <stdio.h>

const char FLOR = 'F';
/*
* PRE: 
* POST: Devuelve contador_mal_posicionadas -> cantidad de flores que estan mal posicionadas
*/
int flores_mal_distanciadas(char huerta[MAX_ANCHO][MAX_ALTO]){
    
    int contador_mal_posicionadas = 0;
    
    for(int i = 0; i < MAX_ANCHO; i++){
        for(int j = 0; j < MAX_ALTO; j++){
            if(huerta[i][j] == FLOR){
                if(huerta[i-1][j] == FLOR){
                    contador_mal_posicionadas++;
                }else if(huerta[i+1][j] == FLOR){
                    contador_mal_posicionadas++;
                }else if(huerta[i][j-1] == FLOR){
                    contador_mal_posicionadas++;
                }else if(huerta[i][j+1] == FLOR){
                    contador_mal_posicionadas++;
                }
            }
        }
    }
    
    return contador_mal_posiconadas;
}
//Solo cuento hasta 1 vez por cada flor, osea si esta mal posicionada por derecha y por izquierda el contador solo va a subir 1
//-----------------------------------------------------------------------------------------------------------------------------------
//Arreglado

int flores_mal_distanciadas(char huerta[MAX_ANCHO][MAX_ALTO]){
    
    int contador_mal_posicionadas = 0;
    
    for(int i = 0; i < MAX_ANCHO; i++){
        for(int j = 0; j < MAX_ALTO; j++){
            if(huerta[i][j] == FLOR){
                if(huerta[i-1][j] == FLOR && (i-1) >= 0){
                    contador_mal_posicionadas++;
                }else if(huerta[i+1][j] == FLOR && (i+1) < MAX_ANCHO){
                    contador_mal_posicionadas++;
                }else if(huerta[i][j-1] == FLOR && (j-1) >= 0){
                    contador_mal_posicionadas++;
                }else if(huerta[i][j+1] == FLOR && (j+1) < MAX_ALTO){
                    contador_mal_posicionadas++;
                }
            }
        }
    }
    
    return contador_mal_posiconadas;
}