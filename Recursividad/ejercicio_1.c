#include <stdio.h>
                            // ES UNA PARTE DE UN EJERCICIO

void listar_agenda(contacto_t contactos[MAX_CONTACTOS], int tope, int actual){

    // Si actual es = Tope termina la recursividad y la funcion 
    if(actual == tope){
        return;
    }
    //Imprime los contactos de forma ascendente
    printf("%s\n", contactos[actual].nombre);
    //Repite todo y suma 1 al actual
    listar_agenda(contactos, tope, actual +1);

}



// Lo mismo pero comenzando por el final
void listar_agenda_reves_aux(contacto_t contactos[MAX_CONTACTOS], int tope, int actual){

    // Si actual es = Tope termina la recursividad y la funcion 
    if(actual == tope){
        return;
    }
    //Llega hasta el final sin imprimir nada
    listar_agenda(contactos, tope, actual +1);
    //Imprime los contactos desde el ultimo hasta el primero
    printf("%s\n", contactos[actual].nombre);
}

void listar_agenda_reves(contacto_t contactos[MAX_CONTACTOS], int tope){
    listar_agenda_reves_aux(contactos,tope,0);
}

//Otra forma
void listar_agenda_reves_aux_2(contacto_t contactos[MAX_CONTACTOS], int tope){

    if(tope <= 0){
        return 0;
    }

    printf("%s\n", contactos[tope-1].nombre);

    listar_agenda(contactos,tope-1);
}

int main(){

    listar_agenda(agenda.contactos, agenda.cantidad_contactos, 0);
    //En esta segunda manera no solo lo hago al reves sino que hago otra manera para no utilizar el 0
    listar_agenda_reves(agenda.contactos, agenda.cantidad_contactos);


    return 0;
}