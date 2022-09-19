#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXIMO_MENSAJE 500

bool es_vocal(char letra){
    return(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}

// void eliminar_posicion(char letra[MAXIMO_MENSAJE], int pos){
//     int tope = strlen(letra);

//     letra[pos] = letra[tope - 1];

//     letra[tope-1] = '\0';
// }

int main(){

    char mensaje[MAXIMO_MENSAJE];
    printf("Ingrese el mensaje a burlar \n");
    scanf("%[^\n]", mensaje);

    //Burlarlo (ES MEJOR ESTA MANERA)

    for(size_t i = 0; i < strlen(mensaje); i++){
        if(es_vocal (mensaje[i])){
            mensaje[i] = 'i';
        }
    }

    //Otra forma(No funciona lol)

    // int i = 0;

    // while(mensaje[i] != '\0'){
    //     if(es_vocal (mensaje[i])){
    //         eliminar_posicion(mensaje, i);
    //     }
    //     i++;
    // }

    // Final

    printf("%s\n", mensaje);
    return 0;
}
