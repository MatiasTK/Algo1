#include <stdio.h>

int main(){
    
    printf("Charly tirate esa letra pa: ");

    char letra_charly;

    scanf("%c", &letra_charly);    // %c es de caracter, %i es de enteros, %f es para float, %lf para double
                                    //el & indica que va a modificar la variable

    printf("la letra que eligio charly es: %c", letra_charly);  

    return 0;
}