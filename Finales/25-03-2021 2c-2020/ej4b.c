#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTRASENIAS 200

//-------------------------------------------------------------------- OTRA FORMA QUE SE ME OCURRE

typedef struct contrasenias{
    char contrasenia[MAX_CONTRASENIAS];
    bool testeada;
} contrasenias_t;

#define MAX_NOMBRE 50

//Union -> uno los dos vectores pero no pongo los repetidos
void unir_password(contrasenias_t vector_tom[MAX_NOMBRE], int tope_tom, contrasenias_t vector_jerry[MAX_NOMBRE],int tope_jerry,contrasenias_t vector_final[MAX_NOMBRE],int* tope_final){
    int i = 0;
    int j = 0;
    (*tope_final) = 0;

    while(i < tope_tom && j < tope_jerry){
        if(strcmp(vector_tom[i].contrasenia, vector_jerry[j].contrasenia) <= 0){
            if(strlen(vector_tom[i].contrasenia ) < 10){
                vector_final[(*tope_final)] = vector_tom[i];// No es strcpy ya que estoy copiando el struct no el string
                i++;
                (*tope_final)++;
            }
        }else{
            if(strlen(vector_jerry[j].contrasenia) < 10){
                vector_final[(*tope_final)] = vector_jerry[j];
                j++;
                (*tope_final)++;
            }
        }
    }

    //Seteo todas como no probadas ya que no probe ninguna
    for(int k = 0; k < (*tope_final); k++){
        vector_final[k].testeada == false;
    }

}

//Suponiendo que entre medio de estas dos funciones hay una donde prueba algunas contrasenias y las setea como vector_final[i].testeada == TRUE;

//Esto si queremos chequear si se comprobo una contraseña en especifico
bool se_probo(contrasenias_t vector_final[MAX_NOMBRE],int tope_final, char contrasenia_probar[MAX_NOMBRE]){
    for(int i = 0; i < tope_final; i++){
        if(strcmp(vector_final[i].contrasenia,contrasenia_probar) == 0){
            return(vector_final[i].testeada);
        }
    }
    return false;
}

//Si queremos chequear todas las contraseñas
// CREO QUE NO ME PIDEN ESTO YA QUE NO HAY MANERA QUE RETORNE UN BOOL
void probada(contrasenias_t vector_final[MAX_NOMBRE], int tope_final){

    char SI = 'S';
    char NO = 'N';

    for(int i = 0; i < tope_final; i++){
        if(vector_final[i].testeada == true){
            printf("Contraseña: %s , testeada: %c\n",vector_final[i].contrasenia, SI);
        }else{
            printf("Contraseña: %s , testeada: %c\n",vector_final[i].contrasenia, NO);
        }
    }
}

int main(){

    return 0;
}