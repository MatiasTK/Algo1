#include <stdio.h>
#include <stdbool.h> // Sirve para que funcione el dato bool

const int MAXIMA_VECES_CACA = 100; // NO SE PUEDE USAR EN SWITCH 

#define MINIMA_VECES_CACA 1 // es lo mismo q const int pero se usa mas para switch 

bool es_cantidad_caca_valido(int bolsas){
    if(bolsas >= MINIMA_VECES_CACA || bolsas <= MAXIMA_VECES_CACA){
        return true;
    } else {
        return false;
    }
}

int cantidad_de_rollitos(int bolsas_x_dia, int dias, int bolsas_x_rollito){ 
    
    int rollitos = ((bolsas_x_dia * dias) / bolsas_x_rollito);

    if ((bolsas_x_dia * dias) % bolsas_x_rollito !=0){
        rollitos++;
    }
    return rollitos;
}


int main(){
    
    int bolsas_diarias;
    int dias = 180;
    int bolsas_por_rollitos = 100;

    printf("Charly, cuantas veces por dia hace caca Alma?\n");
    scanf("%i", &bolsas_diarias);

    while (!es_cantidad_caca_valido(bolsas_diarias)){  
    printf("Charly, cuantas veces por dia hace caca Alma? (entre %i y %i)\n", MINIMA_VECES_CACA, MAXIMA_VECES_CACA);
    scanf("%i", &bolsas_diarias);
    }

    /* Terminar de pedir los demas datos */

    printf("Charly, vas a tener que llevar %i rollitos\n", cantidad_de_rollitos(bolsas_diarias, dias, bolsas_por_rollitos));

    return 0;
}