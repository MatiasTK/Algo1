#include <stdio.h>

int main(){

    char letra_charly;
    int numero_charly;

    printf("Charly tirate una letra pa:");
    scanf("%c", &letra_charly);

    printf("Charly tirate un numero pa:");
    scanf("%i", &numero_charly);

    printf("la letra que eligio charly es %c y el numero que eligio charly es %i", letra_charly, numero_charly);

    return 0;
}