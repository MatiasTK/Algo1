#include <stdio.h>
#include <string.h>

#define MAX_PALABRA 256
const int MAX_PALABRA_CARTA = 10;
char const BAJITO[MAX_PALABRA] = "bajito";
char const MUYMUYALTO[MAX_PALABRA] = "muymuyalto";

int main(){

    char carta[2000] = "";
    char palabra[MAX_PALABRA] = " . ";

    printf("A continuacion, escriban la carta palabra a palabra. %s \n");
    while(strcmp(palabra,"@") != 0){
        scanf("%s", palabra);
        if(strlen(palabra) <= MAX_PALABRA_CARTA){
            if(strcmp(palabra, BAJITO) == 0){
                strcpy(palabra, MUYMUYALTO);
            }

        strcat(carta, palabra);
        strcat(carta, " ");
        }
    }
    printf("%s\n",carta);
    return 0;
}