#include <stdio.h>
#include <stdbool.h>
#include "test_de_personalidad.h"

#define RESULTADO_MENSAJE_POLAR "- Polar (I) - Polar, el menor de los tres hermanos, suele estar en un segundo plano y no decir palabra. Pero aunque sea un oso de pocas palabras, no hay que subestimarlo. Con todos sus talentos ocultos, Polar es prácticamente un genio y hace todo el trabajo sucio de los osos. Tanta genialidad también hace que sea un poco raro y excéntrico."
#define RESULTADO_MENSAJE_PANDA "- Panda (P) - Panda es el mediano y no se parece en nada a sus hermanos. A ellos les gusta bailar; Panda se queda contra la pared. Ellos comen carne; Panda es vegetariano. Panda participa voluntariamente en casi todas las ideas de Pardo, aunque sea un poco más inteligente."
#define RESULTADO_MENSAJE_PARDO "- Pardo (G) - Pardo es el mayor de los hermanos. Aunque es un líder carismático, alegre y muy motivado, no es demasiado listo. A lo mejor comió pintura siendo osezno, nadie lo sabe. Pero lo que le falta de sentido común lo compensa con energía y entusiasmo desenfrenados."

const char POLAR = 'I';

const char PARDO = 'G';

const char PANDA = 'P';

const char ANIME = 'A', MUSICA_POP = 'M', LIMPIEZA = 'L';

const char BAMBU = 'B', PESCADO = 'P', FOCAS = 'F';

const int PUNTO_ANIME = 2, PUNTO_POP = 3, PUNTO_LIMPIEZA = 1;

const int PUNTO_BAMBU = 6, PUNTO_PESCADO = 9, PUNTO_FOCA = 3; 

const int PISO_MAX = 18, PISO_MIN = 1;

const int GRITO_MAX = 18, GRITO_MIN = 1;

const int MENOR_POLAR = 5, MAYOR_POLAR = 24;

const int MENOR_PANDA = 25, MAYOR_PANDA = 43;

const int MENOR_PARDO = 44, MAYOR_PARDO = 63;

/*
* PRE: 
* POST: Devuelve True si la pregunta_tv es Anime,musica pop o limpieza o false en caso contrario
*/
bool es_pregunta_tv_valida(char pregunta_tv){
    return (pregunta_tv == ANIME || pregunta_tv == MUSICA_POP || pregunta_tv == LIMPIEZA);
}

/*
* PRE: 
* POST: Imprime la pregunta al usuario y la modifica en base a su respuesta, verifica si la respuesta del usuario es valida
*/
void pedir_pregunta_tv(char* pregunta_tv){

    printf("Vas a ver television un rato, pones el canal de: Anime (A), Musica Pop (M), Limpieza (L):\n");
    scanf(" %c", pregunta_tv);

    while(!es_pregunta_tv_valida(*pregunta_tv)){
        printf("Ese caracter no es valido, te vuelvo a preguntar\nVas a ver television un rato, pones el canal de: Anime (A), Musica Pop (M), Limpieza (L):\n");
        scanf(" %c", pregunta_tv);
    }


}
/*
* PRE: 
* POST: Devuelve True si la pregunta_alimento es Anime,musica pop o limpieza o false en caso contrario
*/
bool es_pregunta_alimento_valida(char pregunta_alimento){
    return (pregunta_alimento == BAMBU || pregunta_alimento == PESCADO || pregunta_alimento == FOCAS);
}
/*
* PRE: 
* POST: Imprime la pregunta al usuario y la modifica en base a su respuesta, verifica si la respuesta del usuario es valida
*/
void pedir_pregunta_alimento(char* pregunta_alimento){
    
    printf("Solo podes guardar un alimento en tu vianda: Bambu (B), Pescado (P), Focas (F):\n");
    scanf(" %c", pregunta_alimento);

    while(!es_pregunta_alimento_valida(*pregunta_alimento)){
        printf("Ese caracter no es valido, te vuelvo a preguntar\nSolo podes guardar un alimento en tu vianda: Bambu (B), Pescado (P), Focas (F):\n");
        scanf(" %c", pregunta_alimento);
    }

}

/*
* PRE: 
* POST: Devuelve True si la pregunta_piso esta entre el piso minimo y el piso maximo o false en caso contrario
*/
bool es_pregunta_piso_valida(int pregunta_piso){
    return (pregunta_piso >= PISO_MIN && pregunta_piso <= PISO_MAX);
}
/*
* PRE: 
* POST: Imprime la pregunta al usuario y la modifica en base a su respuesta, verifica si la respuesta del usuario es valida
*/
void pedir_pregunta_piso(int* pregunta_piso){
    
    printf("Te compras una torre con tus dos hermanos de 18 pisos. ¿En que piso te gustaria vivir?:\n");
    scanf(" %i", pregunta_piso);

    while(!es_pregunta_piso_valida(*pregunta_piso)){
        printf("Ese numero no es valido, te vuelvo a preguntar\nTe compras una torre con tus dos hermanos de 18 pisos. ¿En que piso te gustaria vivir?:\n");
        scanf(" %i", pregunta_piso);
    }
}

/*
* PRE: 
* POST: Devuelve True si la pregunta_grito esta entre el grito minimo y el grito maximo o false en caso contrario
*/
bool es_pregunta_grito_valida(int pregunta_grito){
    return (pregunta_grito >= GRITO_MIN && pregunta_grito <= GRITO_MAX);
}
/*
* PRE: 
* POST: Imprime la pregunta al usuario y la modifica en base a su respuesta, verifica si la respuesta del usuario es valida
*/
void pedir_pregunta_grito(int* pregunta_grito){ 
    
    printf("¡Oh, una rata! ¿Que tan fuerte gritas del 1 al 18? Siendo 1 no gritar y 18 desgarrarse la garganta:\n");
    scanf(" %i", pregunta_grito);

    while(!es_pregunta_grito_valida(*pregunta_grito)){
        printf("Ese numero no es valido, te vuelvo a preguntar\n¿Que tan fuerte gritas del 1 al 18?:\n");
        scanf(" %i", pregunta_grito);
    }

}
/*
* PRE: La primer pregunta tiene que ser un canal de television 
* POST: Le doy un valor numerico a la respuesta de la primer pregunta en base a los puntos 
*/
void puntos_pregunta_tv(char pregunta_tv, int* puntos_television){

    if(pregunta_tv == ANIME){
        *puntos_television = PUNTO_ANIME;
    } else if(pregunta_tv == MUSICA_POP){
        *puntos_television = PUNTO_POP;
    } else {
        *puntos_television = PUNTO_LIMPIEZA;
    } 
}
/*
* PRE: La primer pregunta tiene que ser un tipo de alimento
* POST: Le doy un valor numerico a la respuesta de la segunda pregunta en base a los puntos 
*/
void puntos_pregunta_alimento(char pregunta_alimento, int* puntos_alimento){
    
    if(pregunta_alimento == BAMBU){
    *puntos_alimento = PUNTO_BAMBU;
    } else if(pregunta_alimento == PESCADO){
    *puntos_alimento = PUNTO_PESCADO;
    } else {
    *puntos_alimento = PUNTO_FOCA;
    }

}
/*
* PRE: Puntos de television son los puntos de la primer pregunta, puntos alimento de la segunda, tomo los valores numericos de la tercer y cuarta pregunta, establezco unos puntos totales, todos los datos deben ser enteros
* POST: calculo el porcentaje de puntos totales basandome en los puntos de las 4 preguntas 
*/
int puntos_finales(int puntos_television, int puntos_alimento, int pregunta_piso, int pregunta_grito, int* puntos){

    *puntos = ((puntos_television) * (puntos_alimento)) + pregunta_piso + pregunta_grito;

    return *puntos;
}
/*
* PRE: Puntos debe ser un entero previamente calculado
* POST: muestro el valor de los puntos totales en pantalla y imprimo la personalidad definida por esos puntos 
*/
void mostrar_resultado_test(int puntos,char* personalidad_detectada){
    printf("tus puntos totales son %i\n",puntos);
    
    if((puntos >= MENOR_POLAR) && (puntos <= MAYOR_POLAR)){
    printf("Tu personalidad es %s\n", RESULTADO_MENSAJE_POLAR);
    (*personalidad_detectada) = POLAR;
    } else if ((puntos >= MENOR_PANDA) && (puntos <= MAYOR_PANDA)){
    printf("Tu personalidad es %s\n", RESULTADO_MENSAJE_PANDA);
    (*personalidad_detectada) = PANDA;
    } else if((puntos >= MENOR_PARDO) && (puntos <= MAYOR_PARDO)){
    printf("Tu personalidad es %s\n", RESULTADO_MENSAJE_PARDO);
    (*personalidad_detectada) = PARDO;
    }

    printf("\n");
}

void test_de_personalidad(char* personalidad_detectada){

    char pregunta_tv, pregunta_alimento;
    int pregunta_piso, pregunta_grito;

    int puntos_television = 0, puntos_alimento = 0;
    int puntos = 0;

    pedir_pregunta_tv(&pregunta_tv);
    pedir_pregunta_alimento(&pregunta_alimento);
    pedir_pregunta_piso(&pregunta_piso);
    pedir_pregunta_grito(&pregunta_grito);
    puntos_pregunta_tv(pregunta_tv,&puntos_television);
    puntos_pregunta_alimento(pregunta_alimento,&puntos_alimento);
    puntos_finales(puntos_television, puntos_alimento, pregunta_piso, pregunta_grito, &puntos);
    mostrar_resultado_test(puntos,personalidad_detectada);

}

