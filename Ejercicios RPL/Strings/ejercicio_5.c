#include <string.h>
#define MAX_FRASE 40
// Aca van las constantes

void intercambiar_frase(char frase[MAX_FRASE]) {
	int longitud = strlen(frase);
    char guardar;

    for(int i = 0, j = longitud - 1; i < (longitud / 2); i++, j--){
        guardar = frase[i];
        frase[i] = frase[j];
        frase[j] = guardar;
    }
}