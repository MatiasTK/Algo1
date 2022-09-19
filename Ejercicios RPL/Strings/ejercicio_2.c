#include <string.h>
#include <stdbool.h>
#define MAX_FRASE 50
// Aca van las constantes

bool frase_digna(char frase[MAX_FRASE]) {

    return(strlen(frase) < 19);
}