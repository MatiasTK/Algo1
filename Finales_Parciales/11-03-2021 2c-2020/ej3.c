#include <stdio.h>

#define MAX_FIGURITAS 100

//Hago interseccion para ver que esten en los dos vectores
void nuevo_vector(char vector_bombom[MAX_FIGURITAS], int tope_bombom, char vector_bellota[MAX_FIGURITAS], int tope_bellota, char vector_final[MAX_FIGURITAS],int* tope_final){
    int i = 0;
    int j = 0;
    (*tope_final) = 0;

    while((i < tope_bombom) && (j < tope_bellota)){
        if(vector_bombom[i] == vector_bellota[j]){
            vector_final[(*tope_final)] = vector_bombom[i];
            (*tope_final)++;
            i++;
            j++;
        }else if(vector_bombom[i] < vector_bellota[j]){
            i++;
        }else{
            j++;
        }
    }
}
//Parte 2 -> Si quieren tener anotada las figuritas que tienen sin repetir 
void nuevo_vector(char vector_bombom[MAX_FIGURITAS], int tope_bombom, char vector_bellota[MAX_FIGURITAS], int tope_bellota, char vector_final[MAX_FIGURITAS],int* tope_final){
    int i = 0;
    int j = 0;
    (*tope_final) = 0;

    int contador_no_repetidas = 0;

    while((i < tope_bombom) && (j < tope_bellota)){
        if(vector_bombom[i] == vector_bellota[j]){
            vector_final[(*tope_final)] = vector_bombom[i];
            (*tope_final)++;
            i++;
            j++;
        }else if(vector_bombom[i] < vector_bellota[j]){
            i++;
            contador_no_repetidas++;
        }else{
            j++;
            contador_no_repetidas++;
        }
    }
}


int main(){

    return 0;
}