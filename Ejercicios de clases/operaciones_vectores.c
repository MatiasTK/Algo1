#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//---------------------------> PARA REALIZAR CUALQUIERA DE ESTAS OPERACIONES LOS VECTORES DEBEN ESTAR ORDENADOS
#define MAX_VECTOR 100

/*
Datos a considerar:
-Fseek solo se utiliza en archivos binarios de acceso directo
Formato: fseek(archivo,(int)sizeof(registro_t)*(registro.id -1),SEEK_SET)
Convierto el sizeof en int por las dudas y lo multiplico por los bytes que me quiero mover en este caso el id -1 ya que sino me paso
SEEK_SET -> Establece que ahora el principio del archivo es eso
SEEK_CUR -> Me muevo desde donde estoy parado
*/

// Crea un vector que contiene la informacion de los dos vectores (NO ES INTERSECCION, COPIA TODO SIN IMPORTAR SI ESTAN EN LOS DOS)
void mezcla(int primer_vector[MAX_VECTOR],int primer_tope, int segundo_vector[MAX_VECTOR], int segundo_tope, int vector_resultado[MAX_VECTOR],int* tope_resultado){
    int i = 0;
    int j = 0;
    (*tope_resultado) = 0;

    while((i < primer_tope) && (j < segundo_tope)){
        if(primer_vector[i] <= segundo_vector[j]){
            vector_resultado[(*tope_resultado)] = primer_vector[i];
            i++;
        }else{
            vector_resultado[(*tope_resultado)] = segundo_vector[j];
            j++;
        }
        (*tope_resultado)++;
    }

    while(i < primer_tope){
        vector_resultado[(*tope_resultado)] = primer_vector[i];
        i++;
        (*tope_resultado)++;
    }

    while(j < segundo_tope){
        vector_resultado[(*tope_resultado)] = segundo_vector[j];
        j++;
        (*tope_resultado)++;
    }
}

//Es igual que mezcla -> copia la informacion que esta en los dos vectores(NO ES INTERSECCION COPIA TODO MENOS LO REPETIDO SIN IMPORTAR SI NO ESTA EN EL OTRO)
void union_vector(int primer_vector[MAX_VECTOR],int primer_tope, int segundo_vector[MAX_VECTOR], int segundo_tope, int vector_resultado[MAX_VECTOR],int* tope_resultado){
    int i = 0;
    int j = 0;
    (*tope_resultado) = 0;

    while((i < primer_tope) && (j < segundo_tope)){
        if(primer_vector[i] <= segundo_vector[j]){
            vector_resultado[(*tope_resultado)] = primer_vector[i];
            i++;
        }else{
            vector_resultado[(*tope_resultado)] = segundo_vector[j];
            j++;
        }
        (*tope_resultado)++;
    }
}

//Crea un vector que contiene los elementos del primer vector que NO esten en el segundo
void diferencia(int primer_vector[MAX_VECTOR],int primer_tope, int segundo_vector[MAX_VECTOR], int segundo_tope, int vector_resultado[MAX_VECTOR],int* tope_resultado){
    int i = 0;
    int j = 0;
    (*tope_resultado) = 0;

    while((i < primer_tope) && (j < segundo_tope)){
        if(primer_vector[i] == segundo_vector[j]){ //Ya que esta en los dos no copio nada
            i++;
            j++;
        }else if(primer_vector[i] < segundo_vector[j]){ //Ya que esta en el primero y no en el segundo lo copio
            vector_resultado[(*tope_resultado)] = primer_vector[i];
            i++;
            (*tope_resultado)++;
        }else if(primer_vector[i] > segundo_vector[j]){//Esta en el segundo pero no el primero, pero como estoy haciendo diferencia del primero solo copio lo que esta en el primero
            j++;
        }
    }

    while(i < primer_tope){
        vector_resultado[(*tope_resultado)] = primer_vector[i];
        i++;
        (*tope_resultado)++;
    }
}

//Crea un vector que contiene los elementos que estan en los dos vectores -> Osea tiene que estar la misma informacion en el vector 1 y en el vector 2 para que copie
void interseccion(int primer_vector[MAX_VECTOR],int primer_tope, int segundo_vector[MAX_VECTOR], int segundo_tope, int vector_resultado[MAX_VECTOR],int* tope_resultado){
    int i = 0;
    int j = 0;
    (*tope_resultado) = 0;

    while((i < primer_tope) && (j < segundo_tope)){
        if(primer_vector[i] == segundo_vector[j]){
            vector_resultado[(*tope_resultado)] = primer_vector[i];
            i++;
            j++;
            (*tope_resultado)++;
        }else if(primer_vector[i] < segundo_vector[j]){
            i++;
        }else{
            j++;
        }
    }
}

//Ordena un vector por metodo de ordenamiento de burbuja
void bubble_sort(int vector[MAX_VECTOR], int tope){
    int i = 0;
    int j = 0;
    int aux; // -> Puede ser size_t si estamos haciendo bubble_sort de un archivo binario con struct

    for(i = 0; i < tope; i++){
        for(j = 0; j < (tope-i-1); j++){
            if(vector[j] > vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

//Inserta un valor en un vector ordenado
void insertar_ordenado(int vector_ordenado[MAX_VECTOR],int* tope, int numero_insertar){
    int i = (*tope);
    while(i > 0 && vector_ordenado[i-1] > 0){
        vector_ordenado[i] = vector_ordenado[i-1]; //Muevo todo una posicion a la derecha desde donde tengo que insertar
        i--;
    }
    vector_ordenado[i] = numero_insertar; //lo inserto en la nueva posicion vacia
    (*tope)++;
}

//Elimina un valor en un vector ordenado
void eliminar_ordenado(int vector_ordenado[MAX_VECTOR],int* tope, int numero_remover){
    int i = -1;
    bool encontre = false;
    int posicion = 0;
    while(i < (*tope) && !encontre){
        if(vector_ordenado[i] == numero_remover){
            encontre = true; // Con esto no sigo analizando el vector
            posicion = i; // guardo la posicion donde esta el numero a remover
        }
        i++;
    }

    if(encontre){
        for(int j = posicion; j < (*tope); j++){
            vector_ordenado[j] = vector_ordenado[j+1]; //Muevo todo una posicion a la izquierda pisando el numero que tengo que eliminar
        }
        (*tope)--;
    }
}

void insertar_desordenado(int vector_desordenado[MAX_VECTOR],int* tope, int numero_insertar){
    vector_desordenado[(*tope)] = numero_insertar;
    (*tope)++;
}

void eliminar_desordenado(int vector_desordenado[MAX_VECTOR],int* tope, int numero_eliminar){
    bool encontre = false;
    int i = 0;
    int posicion = -1;
    while(i < (*tope) && !encontre){
        if(vector_desordenado[i] == numero_eliminar){
            encontre == true;
            posicion = i;
        }
    }
    if(encontre){
        vector_desordenado[posicion] = vector_desordenado[(*tope) -1];
        (*tope)--;
    }
}
