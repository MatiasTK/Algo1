#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int ERROR = -1;
const int EN_CONTRA = 0;
#define MAX_NOMBRE 50

typedef struct firma {
	char nombre[MAX_NOMBRE];
	int voto;
} firma_t;

int main(){

	// abrir el archivo
	FILE* firmas = fopen("firmas_para_la_liberacion_del_insta.txt", "r");
	if (!firmas) {
		printf("No hay firmas Master, a tu casa!\n");
		return ERROR;
	}

	FILE* firmas_aux = fopen("firmas_aux.txt", "w");
	if (!firmas_aux) {
		fclose(firmas);
		printf("No se puede abrir firmas_aux Rey, jajode!\n");
		return ERROR;
	}

	firma_t firma;
	bool i_charly = false;

	// trabajarlo
	int leidos = fscanf(firmas, "%[^;];%i\n", firma.nombre, &(firma.voto));
	while (leidos == 2){

		if (strcmp(firma.nombre, "Charly") != 0 || !i_charly){
			fprintf(firmas_aux, "%s;%i\n", firma.nombre, firma.voto);
			if (strcmp(firma.nombre, "Charly") == 0){
				i_charly = true;
			}
		}

		leidos = fscanf(firmas, "%[^;];%i\n", firma.nombre, &(firma.voto));
	}

	// cerrar el archivo
	fclose(firmas);
	fclose(firmas_aux);
	rename("firmas_aux.txt", "firmas_para_la_liberacion_del_insta.txt");

	return 0;
}