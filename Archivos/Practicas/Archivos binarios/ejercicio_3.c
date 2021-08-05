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

void mostrar_canciones(char colaborador[MAX_COLAB]){
	FILE* canciones_colab = fopen("canciones.dat", "r");
	/* chequeo de apertura */

	FILE* generos = fopen("genero.dat", "r");
	/* chequeo de apertura */

	cancion_t canchion;
	genero_t genero;

	size_t leidos = fread(&canchion, sizeof(cancion_t), 1, canciones_colab);
	while(leidos == 1){

		if (strcmp(colaborador, canchion.colaborador) == 0){
			fseek(generos, (canchion.id_genero - 1) * (int) sizeof(genero_t), SEEK_SET);
			fread(&genero, sizeof(genero_t), 1, generos);

			printf("%s - %s - %s\n", canchion.colaborador, canchion.nombre, genero.nombre);
		}

		leidos = fread(&canchion, sizeof(cancion_t), 1, canciones_colab);
	}

	fclose(canciones_colab);
}

int main(){

	mostrar_canciones("Sol");
}


