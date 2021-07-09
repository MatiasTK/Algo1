    #include <stdbool.h>
    #define MAX_FILAS 5
    #define MAX_COLUMNAS 5

    const char ROJO = 'R';
    const char AZUL = 'A';
    const char VERDE = 'V';
    const char NADA = '-';


    bool caramelos_suficientes(char cajon[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int cantidad_caramelos, char color_caramelo) {

        int contador_caramelos = 0;

        if(cantidad_caramelos == 0){
            return true;
        }

        for(int i = 0; i < tope_filas; i++){
            for(int j = 0; j < tope_columnas; j++){
                if(cajon[i][j] == color_caramelo){
                    contador_caramelos++;
                }
            }
        }

int temp_contador = 0;

        if(contador_caramelos >= cantidad_caramelos){
            for(int i = 0; i < tope_filas; i++){
                for(int j = 0; j < tope_columnas; j++){
                    if(cajon[i][j] == color_caramelo && temp_contador < cantidad_caramelos){
                        cajon[i][j] = NADA;
                        temp_contador++;
                }
            }
        }
            return true;
        } else {
            return false;
        }

    }

    int main(){

        char cajon[MAX_FILAS][MAX_COLUMNAS] = {{VERDE,AZUL,NADA},{NADA,VERDE,VERDE},{NADA,VERDE,ROJO}};
        int tope_filas = 4;
        int tope_columnas = 4;
        int cantidad_caramelos = 2;
        char color_caramelo = VERDE;

        caramelos_suficientes(cajon,tope_columnas,tope_filas,cantidad_caramelos,color_caramelo);




        return 0;
    }
