#include<stdio.h>
#include<string.h>

#define MAX_CANCION 100
#define MAX_ARTISTA 100
#define MAX_COLAB 50
#define MAX_GENERO 30

typedef struct cancion {
	char nombre[MAX_CANCION];
	char artista[MAX_ARTISTA];
	char colaborador[MAX_COLAB];
	int duracion;
	int id_genero;
} cancion_t;

typedef struct genero {
	char nombre[MAX_GENERO];
	int id;
} genero_t;

void quitar_canciones_goma(char colaborador[MAX_COLAB], int dureishon){
	FILE* canciones_colab = fopen("canciones.dat", "r");
	/* chequeo de apertura */

	FILE* canciones_aux = fopen("canciones_aux", "w");
	/* chequeo de apertura */

	cancion_t canchion;

	int leidos = fread(&canchion, sizeof(cancion_t), 1, canciones_colab);
	while(leidos == 1){
		
		/* ----- */
		if (strcmp(canchion.colaborador, colaborador) != 0 || canchion.duracion < dureishon){
			fwrite(&canchion, sizeof(cancion_t), 1, canciones_aux);
		}
		/* ----- */

		leidos = fread(&canchion, sizeof(cancion_t), 1, canciones_colab);
	}

	fclose(canciones_colab);
	fclose(canciones_aux);
}

int main(){

	int dureishon = 3;
	quitar_canciones_goma("Nico", dureishon);
	
	cancion_t canchion;
	
	FILE* canciones_aux_2 = fopen("canciones_aux", "r");
	int leidos = fread(&canchion, sizeof(cancion_t), 1, canciones_aux_2);
	while(leidos == 1){
		
		printf("%s %s %i\n", canchion.nombre, canchion.colaborador, canchion.duracion);

		leidos = fread(&canchion, sizeof(cancion_t), 1, canciones_aux_2);
	}
	fclose(canciones_aux_2);
	
	rename("canciones_aux", "canciones");
}