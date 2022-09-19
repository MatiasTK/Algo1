#define MAX_FILAS 3             // ARREGLAR ESTO ANTES DE ENTREGAR
#define MAX_COLUMNAS 5
const char ENEMIGO = 'E';
const char VACIO = '-';

void distanciar_formacion(char formacion[MAX_FILAS][MAX_COLUMNAS], int* tope_filas, int* tope_columnas) {
    for(int i = 0; i < (*tope_filas);i++){
        for(int j = 0; j < (*tope_columnas);j++){
            if(formacion[i][j] == ENEMIGO && formacion[i][j + 1] == ENEMIGO){
                if(formacion[i][j + 2] == '\0'){
                (*tope_columnas)++;
                formacion[i][j + 1] = VACIO;
                formacion[i][j + 2] = ENEMIGO;
                }else if((*tope_columnas) == MAX_COLUMNAS && (*tope_filas) != MAX_FILAS){
                (*tope_filas)++;
                formacion[i][j + 1] = VACIO;
                formacion[*tope_filas][j] = ENEMIGO;
                }else {
                formacion[i][j + 1] = VACIO;
                formacion[i][j + 2] = ENEMIGO;
                }
            }
        }
    }
}

int main(){

    char formacion[MAX_FILAS][MAX_COLUMNAS] ={{ENEMIGO,ENEMIGO,VACIO,ENEMIGO},{VACIO,VACIO,ENEMIGO,VACIO},{ENEMIGO,ENEMIGO,ENEMIGO,ENEMIGO}};
    int tope_filas = 3;
    int tope_colmunas = 4;

    distanciar_formacion(formacion,&tope_filas,&tope_colmunas);

    return 0;
}