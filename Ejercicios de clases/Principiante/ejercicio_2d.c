#include <stdio.h>

const char PRIMERA_ALFABETO = 'A';
const char ULTIMA_ALFABETO = 'Z';

const int MINIMO_VALOR_PERMITIDO = 1;
const int MAXIMO_VALOR_PERMITIDO = 100;

int main(){

    char letra_charly;
    int numero_charly;

    char letra_participante;
    int numero_participante;

    printf("Charly tirate esa letra pa (entre %c y %c):", PRIMERA_ALFABETO, ULTIMA_ALFABETO);
    scanf(" %c", &letra_charly);

    while(letra_charly < PRIMERA_ALFABETO  || letra_charly > ULTIMA_ALFABETO ){

        printf("Charly te equivocaste");
        scanf(" %c", &letra_charly);
    }

    printf("Charly tirate ese numero (entre %i y %i):", MINIMO_VALOR_PERMITIDO, MAXIMO_VALOR_PERMITIDO);
    scanf("%i", &numero_charly);

    while(numero_charly < MINIMO_VALOR_PERMITIDO || numero_charly > MAXIMO_VALOR_PERMITIDO) {
        printf("charly te equivocaste");
        scanf("%i", &numero_charly);
    }

    printf("Participante tirate esa letra (entre %c y %c):", PRIMERA_ALFABETO, ULTIMA_ALFABETO);
    scanf(" %c", &letra_participante);

    while(letra_participante < PRIMERA_ALFABETO || letra_participante > ULTIMA_ALFABETO){

        printf("Participante te quivocaste");
        scanf(" %c", &letra_participante);
    }
    
    printf("Participante tirate ese numero (entre %i y %i):", MINIMO_VALOR_PERMITIDO, MAXIMO_VALOR_PERMITIDO);
    scanf("%i", &numero_participante);

    while(numero_participante < MINIMO_VALOR_PERMITIDO || numero_participante > MAXIMO_VALOR_PERMITIDO) {
        printf("participante te quivocaste");
        scanf(" %i", &numero_participante);

    }

    // determino intentos

    int intentos = 1;

    while(!(letra_charly == letra_participante && numero_charly == numero_participante) && intentos < 10){

        printf("Intento numero %i\n", intentos);

        printf("Participante tirate esa letra (entre %c y %c):", PRIMERA_ALFABETO, ULTIMA_ALFABETO);
    scanf(" %c", &letra_participante);

            while(letra_participante < PRIMERA_ALFABETO || letra_participante > ULTIMA_ALFABETO){

        printf("Participante te equivocaste");
        scanf(" %c", &letra_participante);
    }


    printf("Participante tirate ese numero (entre %i y %i):", MINIMO_VALOR_PERMITIDO, MAXIMO_VALOR_PERMITIDO);
    scanf("%i", &numero_participante);

            while(numero_participante < MINIMO_VALOR_PERMITIDO || numero_participante > MAXIMO_VALOR_PERMITIDO) {
        printf("participante te equivocaste");
        scanf(" %i", &numero_participante);

    }

        intentos++;

    }

    // determino si gana el participante

    if(letra_charly == letra_participante && numero_charly == numero_participante) {

        printf("Dame los dolarucos charly");
    } else {
        printf("Dame ese pesito bb");
    }

return 0;
}