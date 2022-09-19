#define MAX_FILAS 10
#define MAX_COLUMNAS 10
// Aca van las constantes

void posicionar_serpiente(unsigned int casa[MAX_FILAS][MAX_COLUMNAS], unsigned int tope_filas, unsigned int tope_columnas, unsigned int id, unsigned int largo, int fila) {

    int i = 0;

    if(largo > tope_columnas){
       tope_columnas = largo;
    }

    while(i != (largo)){
    casa[fila][i] = id;
    ++i;
    }

}

int main(){

    unsigned int casa[MAX_FILAS][MAX_COLUMNAS] = {0};
    unsigned int tope_filas = 9;
    unsigned int tope_columnas = 9;
    unsigned int largo = 2;
    int fila = 1;
    unsigned int id = 3;

    posicionar_serpiente(casa, tope_columnas, tope_filas, id, largo, fila);

    return 0;
}


