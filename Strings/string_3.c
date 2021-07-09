#include <stdio.h>
#include <string.h>

int main(){

    char nombre[100];
    char apellido[100];

    // strcpy(nombre, "Matias");
    printf("Escriba su nombre y apellido\n");
    scanf("%[^\n]", nombre); // ESTO QUIERE DECIR QUE LEA HASTA QUE SE ENCUENTRRE UN \n
    printf("%s\n", nombre);
    // strcpy(apellido,"Vallejos");
    // printf("%s\n", apellido);

    // strcat(nombre,apellido); // SOLO LA CADENA nombre TIENE LAS DOS CONCATENACIONES NO LA ULTIMA
    // printf("%s\n", nombre);

    strcat(nombre, " ");        // para agregar un espacio sin tener que romper el "Vallejos"
    strcat(nombre,apellido); 
    printf("%s\n", nombre);



    return 0;
}