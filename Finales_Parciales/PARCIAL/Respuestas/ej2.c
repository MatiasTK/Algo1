#define MAX_VECTOR 50

const char SUMA = 'S';
const char RESTA = 'R';

typedef struct cuenta{
    int numero;
    char operacion; // Solo sabe sumar y restar
} cuenta_t;


/*
* PRE: el tope debe estar inicializado 
* POST: Ordena el vector en forma ascendente y imprime por pantalla el resultado de la suma o resta de los elementos del vector
*/
void ordenar_vector(cuenta_t vector[MAX_VECTOR],int tope){
    int i, j;
    cuenta_t auxiliar;
    int resultado = 0;
    for(i = 0; i < tope; i++){
        for(j = 0; j < (tope-1); j++){ // UNICO ERROR ES ->    j < (tope-i-1)
            if(vector[j].numero > vector[j+1].numero){
                auxiliar = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = auxiliar;
            }
        }
    }
    
    for(i = 0; i < tope; i++){
        if(vector[i].operacion == SUMA){
            resultado = resultado + vector[i].numero;
        }else if(vector[i].operacion == RESTA){
            resultado = resultado - vector[i].numero;
        }
    }
    
    printf("El resultado de las cuentas es: %i", resultado);
}
//El metodo de ordenamiento utilizado fue: Burbujeo

//Parte 2
-Como el vector esta ordenado para poder insertar una nueva cuenta y mantener el vector ordenado lo inserto ordenadamente, osea:
1-Empiezo analizando el vector por la derecha(Osea desde el final hasta el principio), como quiero insertar una cuenta
solo analizo los numeros del vector,no las operaciones.
2-Si encuentro un numero mayor al que tengo que insertar entonces a partir desde ahi hasta el tope del vector muevo todo una
posicion hacia la derecha.
3-Como ahora me va a quedar una posicion vacia(Ya que movi todo una posicion a la derecha a partir del elemento encontrado)
en esa posicion vacia inserto la cuenta deseada con su operacion y numero.
4-Finalmente como movi todo una posicion a la derecha para no eliminar un numero del vector aumento el tope.