#include <string.h>
#define MAX_RECETA 250
// Aca van las constantes

void copiar_receta(char receta_jerry[MAX_RECETA], char recetario_tom[MAX_RECETA]) {
	strcpy(recetario_tom, receta_jerry);
}