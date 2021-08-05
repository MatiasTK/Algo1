#define MAX_NOMBRE 50
#define MAX_CARAMELOS 50

const char VERDE = 'V';
const char ROJO = 'R';
const char AZUL = 'A';

const char GRANDE = 'G';
const char PEQUENIO = 'P';

const char FRUTILLA = 'F';
const char LIMON = 'L';
const char MENTA = 'M';


typedef struct caramelo{
    char nombre[MAX_NOMBRE];
    char color;
    char sabor;
    int tamanio;
    int cantidad;
    int precio;
    bool contiene_azucar;
} caramelo_t;
/*
* PRE: el tope debe estar inicializado
* POST: Genera 3 vectores, 1 con caramelos de ed, 1 con caramelos de edd, 1 con caramelos de eddy
*/
void caramelos_preferidos(caramelo_t caramelos[MAX_CARAMELOS], int tope, caramelo_t caramelos_ed[MAX_CARAMELOS],
caramelo_t caramelos_edd[MAX_CARAMELOS], caramelo_t caramelos_eddy[MAX_CARAMELOS], char caramelo_pedido_eddy[MAX_NOMBRE]){
    for(int i = 0; i < tope; i++){
        if(caramelos[i].color == VERDE && caramelos[i].precio > 2){
            caramelos_ed[i] = caramelos[i];
        }
        if(caramelos[i].tamanio == GRANDE && caramelos[i].contiene_azucar == true){
            caramelos_edd[i] = caramelos[i];
        }
        if(strcmp(caramelos[i].nombre, caramelo_pedido_eddy) == 0 && caramelos[i].sabor != MENTA){
            caramelos_eddy[i] = caramelos[i];
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
//Falto añadir topes, arreglado:

#define MAX_NOMBRE 50
#define MAX_CARAMELOS 50

const char VERDE = 'V';
const char ROJO = 'R';
const char AZUL = 'A';

const char GRANDE = 'G';
const char PEQUENIO = 'P';

const char FRUTILLA = 'F';
const char LIMON = 'L';
const char MENTA = 'M';


typedef struct caramelo{
    char nombre[MAX_NOMBRE];
    char color;
    char sabor;
    int tamanio;
    int cantidad;
    int precio;
    bool contiene_azucar;
} caramelo_t;
/*
* PRE: el tope debe estar inicializado
* POST: Genera 3 vectores, 1 con caramelos de ed, 1 con caramelos de edd, 1 con caramelos de eddy
*/
void caramelos_preferidos(caramelo_t caramelos[MAX_CARAMELOS], int tope, caramelo_t caramelos_ed[MAX_CARAMELOS],
caramelo_t caramelos_edd[MAX_CARAMELOS], caramelo_t caramelos_eddy[MAX_CARAMELOS], char caramelo_pedido_eddy[MAX_NOMBRE], int tope_ed, int tope_edd, int tope_eddy){
    for(int i = 0; i < tope; i++){
        if(caramelos[i].color == VERDE && caramelos[i].precio > 2){
            caramelos_ed[i] = caramelos[i];
            tope_ed++;
        }
        if(caramelos[i].tamanio == GRANDE && caramelos[i].contiene_azucar == true){
            caramelos_edd[i] = caramelos[i];
            tope_edd++;
        }
        if(strcmp(caramelos[i].nombre, caramelo_pedido_eddy) == 0 && caramelos[i].sabor != MENTA){
            caramelos_eddy[i] = caramelos[i];
            tope_eddy++;
        }
    }
}

