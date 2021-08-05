#include<stdio.h>
#include<string.h>

#define MAX_GENERO 30
#define MAX_GENEROS 20

typedef struct genero {
	char nombre[MAX_GENERO];
	int id;
} genero_t;

int main(){
	FILE* generos_archivo = fopen("genero.dat", "r");
	/* chequeo de apertura */

	genero_t generos_vector[MAX_GENERO];
	size_t tope = fread(generos_vector, sizeof(genero_t), MAX_GENEROS, generos_archivo);
	
	fclose(generos_archivo);

	printf("Tope: %li\n", tope);
	for (int i = 0; i < tope; i++) {
		printf("Genero: %i - %s\n", generos_vector[i].id, generos_vector[i].nombre);
	}

	generos_archivo = fopen("genero.dat", "w");
	/* chequeo de apertura */

	fwrite(generos_vector, sizeof(genero_t), tope, generos_archivo);

	fclose(generos_archivo);

}


