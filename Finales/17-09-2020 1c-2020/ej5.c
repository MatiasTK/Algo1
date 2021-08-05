//1- Le recomendaria que lo guarde en un archivo binario csv con formato nombre;fecha_cumpleaños; usando un struct con nombre y fecha de cumpleaños y la funcion seria para crear
// un archivo de texto


#include <stdio.h>

#define MAX_NOMBRE 50


typedef struct cumpleanios{
    char nombre[MAX_NOMBRE];
    int dia;
    int mes; 
} cumpleanios_t;

//PRE: devuelve -1 si no se pudo abrir el archivo o 0 si todo se realizo bien
int guardar_cumpleanios(cumpleanios_t cumpleanios){
    FILE* lista = fopen("lista.dat","a");

    if(lista == NULL){
        fprintf("No se pudo abrir el archivo lista.dat");
        return -1;
    }

    printf("Nombre del cumpleañero: \n");
    scanf(" %s;", cumpleanios.nombre);
    printf("Dia de cumpleaños: \n");
    scanf("%i;", cumpleanios.dia);
    printf("Mes de cumpleaños: \n");
    scanf("%i;",cumpleanios.mes);

    fwrite(&cumpleanios,sizeof(cumpleanios_t),1,lista);

    fclose(lista);

    return 0;
}