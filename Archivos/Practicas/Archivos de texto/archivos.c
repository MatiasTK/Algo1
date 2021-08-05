#include <stdio.h>

#define ARCHIVO_CANCION "cancion_especial.txt"
#define MAX_LETRAS 100

const int ERROR = -1;
const int EXITO = 0;

// Recibe un archivo valido y abierto
void mostrar_cancion(FILE* cancion){
	char cancion_leida[MAX_LETRAS];
	int leidos = fscanf(cancion,"%[^\n]\n",cancion_leida);
	printf("%i\n",leidos);

	while(!feof(cancion)){
		printf("%s\n",cancion_leida);
		leidos = fscanf(cancion,"%[^\n]\n",cancion_leida);
		printf("%i",leidos);
	}
}

//Devuelve ERROR si no se encuentra el archivo, EXITO si se pudo abrir bien.
int imprimir_cancion_charly(){
	FILE* cancion = fopen(ARCHIVO_CANCION,"r");
	if(!cancion){
		perror("No se pudo abrir el archivo");
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