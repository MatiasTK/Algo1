#include <stdio.h>

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

	firma_t firma;
	// trabajarlo
	int leidos = fscanf(firmas, "%[^;];%i\n", firma.nombre, &(firma.voto));
	while (leidos == 2){

		if (firma.voto == EN_CONTRA){
			printf("%s votó en contra. No hay helado para él. >:c\n", firma.nombre);
		} else {
			printf("%s votó a favor! Ya te mando el cuarto de helado prometido.\n", firma.nombre);
		}

		leidos = fscanf(firmas, "%[^;];%i\n", firma.nombre, &(firma.voto));
	}

	// cerrar el archivo
	fclose(firmas);

	return 0;
}