#define MAX_COMIDAS 100

typedef struct comida{
    char nombre[MAX_NOMBRE];
    int cantidad_veces_hecha;
} comida_t;
/*
* PRE: inicio debe estar inicializado, tope debe estar inicializado,cantidad_comidas debe estar inicializado
* POST: devuelve la cantidad de comidas que puede cocinar
*/
int cantidad_comidas_cocinar(comida_t comidas[MAX_COMIDAS],int inicio, int tope, int cantidad_comidas){
    if(inicio < tope){
        if(comidas[inicio].cantidad_veces_hecha < 7){
            cantidad_comidas++;
        }
        cantidad_comidas_cocinar(comidas, inicio+1, tope, cantidad_comidas);
    }
    
    
    return cantidad_comidas;
}

//-------------------------------------------------------------------------------------
//ESTA MAL HECHO: LO ARREGLO

#define MAX_COMIDAS 100

const int veces_hecha = 7;

typedef struct comida{
    char nombre[MAX_NOMBRE];
    int cantidad_veces_hecha;
} comida_t;
/*
* PRE: inicio debe estar inicializado, tope debe estar inicializado,cantidad_comidas debe estar inicializado
* POST: devuelve la cantidad de comidas que puede cocinar
*/
int cantidad_comidas_cocinar(comida_t comidas[MAX_COMIDAS],int inicio, int tope){
    if(inicio < tope){
        if(comidas[inicio].cantidad_veces_hecha < veces_hecha){
            return 1 + cantidad_comidas_cocinar(comidas,inicio+1,tope)
        }
        return cantidad_comidas_cocinar(comidas,inicio+1,tope);
    }
    return 0;
}