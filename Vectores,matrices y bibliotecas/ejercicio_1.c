#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPANADAS 150

const char JAMON_QUESO = 'J';
const char CARNE = 'C';
const char POLLO = 'P';
const char HUMITA = 'H';
const char VERDURA = 'V';
const char FIN = 'X';

bool es_gusto_valido(char gusto){
    return(gusto == JAMON_QUESO || gusto == CARNE || gusto == POLLO || gusto == HUMITA || gusto == VERDURA || gusto == FIN);
}

void pedir_gusto(char* gusto){

    printf("Gusto (%c,%c,%c,%c,%c) o %c(para terminar): \n", JAMON_QUESO, CARNE, POLLO, HUMITA, VERDURA, FIN);
    scanf(" %c", gusto);

    while(!es_gusto_valido(*gusto)){
        printf("Ese gusto no existe. Pedi bien rey (%c,%c,%c,%c,%c) o %c(para terminar): \n", JAMON_QUESO, CARNE, POLLO, HUMITA, VERDURA, FIN);
        scanf(" %c", gusto);
    }
}

/*
* PRE:  El tope tiene que ser >= 0, es un gusto valido(JAMON_QUESO,CARNE,POLLO,HUMITA,VERDURA)
* POST: El vector tendra una empanada mas, el tope se aumenta en 1 
*/
void cargar_gusto_empanada(char empanadas[MAX_EMPANADAS], int* tope, char gusto){

    if((*tope) < MAX_EMPANADAS){
    empanadas[*tope] = gusto;
    (*tope)++;
    } else {
        printf("No hay lugar :( \n");
    }
}
/*
* PRE: 
* POST:
*/
void cargar_empanadas(char empanadas[MAX_EMPANADAS], int* tope){

    char gusto;
    pedir_gusto(&gusto);
    while(gusto != FIN){
        cargar_gusto_empanada(empanadas, tope, gusto);
        pedir_gusto(&gusto);
    }
}

void mostrar_empanadas(char empanadas[MAX_EMPANADAS], int tope){
    for(int i = 0;i < tope ;i++){
        printf("%c \n", empanadas[i]);
    }
}

int cantidad_empanadas_segun_gusto(char empanadas[MAX_EMPANADAS], int tope, char gusto){

    int contador = 0;
    for(int i = 0;i < tope;i++){
        if(empanadas[i] == gusto){
            contador++;
        }
    }
    return contador;
}

int main(){

    char empanadas[MAX_EMPANADAS];
    int tope = 0;                               // SE INICIALIZA YA QUE ES UN INT QUE NUNCA SE LE PIDE AL USUARIO.

    cargar_empanadas(empanadas, &tope);         // EL VECTOR SIEMPRE VA CON EL TOPE

    mostrar_empanadas(empanadas, tope);

    int cantidad_pollo = cantidad_empanadas_segun_gusto(empanadas, tope, POLLO);
    int cantidad_carne = cantidad_empanadas_segun_gusto(empanadas, tope, CARNE);

    printf("De pollo dieron %i de carne dieron %i \n", cantidad_pollo, cantidad_carne);

    return 0;
}