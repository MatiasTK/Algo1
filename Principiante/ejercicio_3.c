#include <stdio.h>

const int MAX_PERMITIDO = 100;
const int MIN_PERMITIDO = 1;

int main(){

    int numero_manu;
    int numero_charly;

    printf("Elegi un numero manu entre %i y %i:", MAX_PERMITIDO, MIN_PERMITIDO);
    scanf("%i", &numero_manu);

    printf("Elegi un numero charly entre %i y %i:", MAX_PERMITIDO, MIN_PERMITIDO);
    scanf("%i", &numero_charly);


    while(numero_charly < MIN_PERMITIDO || numero_charly > MAX_PERMITIDO) {
        printf("charly te dije entre %i y %i pedazo de boludooo", MAX_PERMITIDO, MIN_PERMITIDO);
        scanf("%i", &numero_charly);
    }

    if(numero_charly > numero_manu){
        printf("Mi numero es mas chico al que elegiste, perdiste \n");
    } else if(numero_charly == numero_manu) {
        printf("Me ganaste adivinaste mi numero");
    }
    else {
        printf("Mi numero es mas grande al que elegiste,perdiste \n");
    }
     // le doy otro intento

     int segunda_oportunidad = 0;

    while(!(numero_charly == numero_manu) && segunda_oportunidad < 1){
        printf("te doy otra oportunidad\n");

         printf("Elegi otro charly entre %i y %i:", MAX_PERMITIDO, MIN_PERMITIDO);
        scanf("%i", &numero_charly);

        if(numero_charly > numero_manu){
            printf("Mi numero es mas chico al que elegiste, perdiste otra vez\n");
        }else if(numero_charly == numero_manu) {
        printf("Me ganaste adivinaste mi numero");
    }
    else {
        printf("Mi numero es mas grande al que elegiste, perdiste otra vez\n");
    }

        

        segunda_oportunidad++;

         printf("Esta vez te doy oportunidades infinitas \n");

    }
    // le doy oportunidades infinitas hasta que adivine el numero

        

    while(!(numero_charly == numero_manu)){
    

        printf("Elegi otro numero hasta adivinar entre %i y %i:", MAX_PERMITIDO, MIN_PERMITIDO);
        scanf("%i", &numero_charly);

         if(numero_charly > numero_manu){
            printf("Mi numero es mas chico al que elegiste \n");
        }else if(numero_charly == numero_manu) {
        printf("Me ganaste adivinaste mi numero");


    }
    }
}