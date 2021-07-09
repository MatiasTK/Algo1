#define MAX_FILAS 10
#define MAX_COLUMNAS 23

const char AMARILLO = 'A';
const char ROJO = 'R';
const char NEGRO = 'N';
const char FUERA = 'X';

int calcular_puntaje_tiro(char blanco[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int fila_tiro, int columna_tiro) {

    char color_tiro = blanco[fila_tiro][columna_tiro];
    int puntaje_tiro = 0;

    if(fila_tiro > tope_filas || columna_tiro > tope_columnas){
        color_tiro = FUERA;
    }

    if(color_tiro == FUERA){
        puntaje_tiro = 0;
    } else if(color_tiro == ROJO){
        puntaje_tiro = 5;
    } else if(color_tiro == AMARILLO){
        puntaje_tiro = 10;
    } else if(color_tiro == NEGRO){
        puntaje_tiro = 2;
    }

    return puntaje_tiro;
}

