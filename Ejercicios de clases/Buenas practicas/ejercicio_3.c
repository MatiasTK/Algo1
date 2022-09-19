#include <stdio.h>

const int CANTIDAD_COLABORADORES = 6;
const int MAXIMO_BAJITO = 165;
const char SI = 'S';

void mostrar_resultados(int colabs_bajito,int colabs_rieron){

       if(colabs_bajito >= (CANTIDAD_COLABORADORES/2) && colabs_rieron > (CANTIDAD_COLABORADORES/2)){
        printf("Me wa a mata wiiii\n");
    }else if( colabs_bajito <= (CANTIDAD_COLABORADORES/2) && colabs_bajito > (CANTIDAD_COLABORADORES/2)){
        printf("Tu criticando y yo creando mi legado, amen\n");
    }else if( colabs_bajito >= (CANTIDAD_COLABORADORES/2) && colabs_rieron >= (CANTIDAD_COLABORADORES/2)){
        printf("Y es que la noche me gusta a mi, salimo en un coche corte rally.\n");
    }else{
        printf("No es lo que esperaba pero estoy satisfecho\n");
    }

}

void encuestar_colabs(int* colabs_rieron, int* colabs_bajito){

     int altura;
     char te_reiste;  // NO SE USA BOOL YA QUE NO PUEDE SER INGRESADO POR TECLADO TRUE O FALSE EL USUARIO

        for(int i = 1;i <= CANTIDAD_COLABORADORES;i++){

    printf("Hola colaborador numero %i!\n", i);

    printf("¿Cuanto crees que mido? (entre 0 y 20 cm):\n");
    scanf(" %i", &altura);

    printf("¿Te reiste de mi ultimo chiste? (S/N)\n");
    scanf(" %c",&te_reiste);

    if(altura < MAXIMO_BAJITO){
        (*colabs_bajito)++;
    }

    if(te_reiste == SI){
        (*colabs_rieron)++;
        }
    }
}

int main(){

    int colabs_bajito = 0;
    int colabs_rieron = 0;

    encuestar_colabs(&colabs_bajito, &colabs_rieron);
    mostrar_resultados(colabs_bajito,colabs_rieron);

   return 0; 
}