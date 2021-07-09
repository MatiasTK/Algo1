#include <stdio.h>
#include <stdbool.h>

// PASAR DE LETRA MINISCULA A MAYUSCULA 

const int DESFASAJE_MAYUS_MINUS = 32;

bool es_minuscula(char letra){
   return((letra) >= 'a' && (letra) <= 'z');
}
/*
*  PRE: 
*  POST: Modifica el parametro letra a mayuscula solo si es minuscula & imprime por pantalla la letra modificada con mensaje
*/
void capitalizar(char* letra){
    if(es_minuscula(*letra)){
        (*letra) = (*letra) - DESFASAJE_MAYUS_MINUS;
    }
    printf("Dentro de la funcion %c\n", *letra); // NO ES NECESARIO PONER ESTO! ACA QUIERO VER QUE PASA EN LA FUNCION NOMAS
}

int main(){

char letra = 'b';

printf("Letra inicial %c\n", letra);
capitalizar(&letra);
printf("Letra final %c\n", letra);

 return 0;   
}
