#include <stdio.h>

#define ARCHIVO_CANCION "cancion_especial.txt"
#define MAX_LETRAS 100

const int ERROR = -1;
const int EXITO = 0;
/*
* PRE: Recibe un archivo valido y abierto
* POST: 
*/
void mostrar_cancion(FILE* cancion){

    char cancion_leida[MAX_LETRAS];
    //En el formato de fscanf lee una linea y lo posiciona para la siguiente pero no lee la siguiente
    int leidos = fscanf(cancion,"%[^\n]\n",cancion_leida); //Cuando lee el archivo devuelve 1, cuando ya no lee nada va a devolver cualquier cosa
    
    while(leidos == 1){
        printf("%s\n", cancion_leida);
        leidos = fscanf(cancion,"%[^\n]\n",cancion_leida); 
    } 

}
/*
* PRE: 
* POST: Devuelve ERROR si no se encuentra al archivo, EXITO si se pudo abrir bien.
*/
int imprimir_cancion_charly(){
    FILE* cancion = fopen(ARCHIVO_CANCION, "r");
    if(!cancion){
        perror("No se pudo abrir abrchivo\n");
        return ERROR;
    }

    mostrar_cancion(cancion);

    fclose(cancion);

    return EXITO;
}

int main(){

    imprimir_cancion_charly();

    return 0;
}