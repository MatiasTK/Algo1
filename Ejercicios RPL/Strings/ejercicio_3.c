#include <string.h>
#include <stdbool.h>
#define MAX_FRASE 40
// Aca van las constantes

bool frase_repetida(char frase_blue[MAX_FRASE], char frase_queso[MAX_FRASE]) {
	return(strcmp(frase_blue, frase_queso) == 0);
}