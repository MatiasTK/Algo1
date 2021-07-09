//                                   CREO Q NO CORRE NI A GANCHO
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 80
#define MAX_CELULAR 12
#define MAX_DIRECCION 50
#define MAX_CONTACTOS 100
#define MAX_GRUPO 4

typedef struct contacto {

char nombre [MAX_NOMBRE];
char celular [MAX_CELULAR];
char direccion [MAX_DIRECCION];
int favoritismo; //siendo 5 el max, 0 el min.
bool borrado;
} contacto_t;

typedef struct agenda {

char duenio_agenda [MAX_NOMBRE];
char celular [MAX_CELULAR];
char grupo_sanguineo[MAX_GRUPO];
contacto_t contactos[MAX_CONTACTOS];
int cantidad_contactos;
} agenda_t;

void agregar_contactos(contacto_t contactos[MAX_CONTACTOS], int* cantidad_contactos){
    //FALTA SEGUIR LLENANDO

    (*cantidad_contactos) = 0;
    strcpy(contactos[0].nombre,"Charly");
    strcpy(contactos[0].celular,"15987327752");
    strcpy(contactos[0].direccion,"Trapetiro 234");
    contactos[0].favoritismo = 0;
    contactos[0].borrado = false;
    (*cantidad_contactos)++;
}

void crear_agenda(agenda_t* agenda){
    strcpy(agenda->duenio_agenda, "Marian");
    strcpy(agenda->celular,"1543759346");
    strcpy(agenda->grupo_sanguineo,"A+");
    agregar_contactos(agenda->cantidad_contactos, &(agenda->cantidad_contactos));
}

int buscar_contacto(contacto_t contactos[MAX_CONTACTOS], int cantidad_contactos, char nombre[MAX_NOMBRE]){
    int i = 0;
    int posicion = -1; // PARA PODER CORTAR EL WHILE Y GUARDAR SU POSICION
    while(i < cantidad_contactos && posicion == -1){
        if(strcmp(contactos[i].nombre,nombre) == 0 && contactos[i].borrado == false){
            posicion = i;
        }
        i++;
    }
    return posicion;
}

void borrar_contacto(agenda_t* agenda, char nombre[MAX_NOMBRE]){
    int posicion = buscar_contacto(agenda->contactos,agenda->cantidad_contactos, nombre);
    if(posicion != -1){
        agenda->contactos[posicion].borrado = true;
        printf("Te saque a un colab\n");
    }
}

void crear_contacto(agenda_t* agenda, char nombre[MAX_NOMBRE], char direccion[MAX_DIRECCION], char celular[MAX_CELULAR]){
    int posicion = buscar_contacto(agenda->contactos,agenda->cantidad_contactos,nombre);
    if(posicion == -1){
        strcpy(agenda->contactos[agenda->cantidad_contactos].nombre,nombre);
        strcpy(agenda->contactos[agenda->cantidad_contactos].direccion,direccion);
        strcpy(agenda->contactos[agenda->cantidad_contactos].celular,celular);
        agenda->contactos[agenda->cantidad_contactos].favoritismo = 0;
        agenda->contactos[agenda->cantidad_contactos].borrado = false;
        printf("Se agrego un nuevo contacto");
    }
}

void modificar_contacto(agenda_t* agenda, char nombre[MAX_NOMBRE], char direccion[MAX_DIRECCION], char celular[MAX_CELULAR]){
    int posicion = buscar_contacto(agenda->contactos,agenda->cantidad_contactos, nombre);
    if(posicion = -1){
        if(strlen(direccion) > 0){
            strcpy(agenda->contactos[posicion].direccion, direccion);
            printf("Modifique la direccion de un contacto");
        }
        if(strlen(celular) > 0){
            strcpy(agenda->contactos[posicion].celular, celular);
            printf("Modifique el celular de un contacto");
        }
    }
}

int main(){

    agenda_t agenda;
    crear_agenda(&agenda);

    char nombre[MAX_NOMBRE];
    strcpy(nombre,"Charly");
    borrar_contacto(&agenda,nombre);
    char nombre_a_agregar[MAX_NOMBRE];
    strcpy(nombre_a_agregar, "Rosi");
    char direccion[MAX_DIRECCION];
    strcpy(direccion, "Calle falsa 123");
    char celular[MAX_CELULAR];
    strcpy(celular,"1533333333");
    char direccion_nueva[MAX_DIRECCION];
    strcpy(direccion_nueva,"Petisito street 156");
    char celular_nuevo[MAX_CELULAR];
    strcpy(celular_nuevo, "");

    crear_agenda(&agenda);
    for(int i = 0; i < agenda.cantidad_contactos; i++){
        if(agenda.contactos[i].borrado == false){
            printf("%s:\n",agenda.contactos[i].nombre);
            printf("\tDireccion: %s\n", agenda.contactos[i].direccion);
            printf("\tTelefono: %s\n\n",agenda.contactos[i].celular);
        }
    }

    borrar_contacto(&agenda,nombre);
    crear_contacto(&agenda,nombre_a_agregar,direccion,celular);

    for(int i = 0; i < agenda.cantidad_contactos; i++){
        if(agenda.contactos[i].borrado == false){
            printf("%s:\n",agenda.contactos[i].nombre);
            printf("\tDireccion: %s\n", agenda.contactos[i].direccion);
            printf("\tTelefono: %s\n\n",agenda.contactos[i].celular);
        }
    }

    

    return 0;
}