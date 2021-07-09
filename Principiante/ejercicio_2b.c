#include <stdio.h>

int main(){

    char letra_charly;
    int numero_charly;

    char letra_participante;
    int numero_participante;

    printf("Charly tirate una letra pa:");
    scanf(" %c", &letra_charly);

    printf("Charly tirate un numero pa:");
    scanf("%i", &numero_charly);

    printf("participante tirate una letra pa:");        // cuando pedimos %c tiene que haber SI O SI un espacio en blanco antes
    scanf(" %c", &letra_participante);

    printf("participante tirate un numero pa:");
    scanf("%i", &numero_participante);

    if(letra_charly == letra_participante && numero_charly == numero_participante){
        printf("Charly larga los dolarucos");
    }
        else {
            printf("Dame ese pesito bb");
        }
    

    return 0;
}