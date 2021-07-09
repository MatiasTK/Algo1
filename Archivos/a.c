//Se busca leer un archivo csv con empanadas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

typedef struct respuesta{
    char gusto_preferido[MAX];
    int cuantas_se_come;
    bool carne_con_pasas;
} respuesta_t;

int main(){

    FILE * archivo = fopen("./empanadas.csv","r"); //NO EXISTE EL ARCHIVO PERO SUPONGAMOS QUE SI
    if(!archivo){
        printf("Error de apertura de empanadas.csv\n");
        return -1;
    }
    int contador = 0;
    int leidos;
    respuesta_t reg;

    leidos = fscanf(archivo,"[^;]%i;%i\n",reg.gusto_preferido,&(reg.cuantas_se_come),&(reg.carne_con_pasas)); //Del archivo lee la primer linea, hasta el primer ; y pone en el registro cuantas se come y carne con pasas un valor

    while(leidos != EOF){
        if(strcmp("Humita",reg.gusto_preferido) == 0){ //Sumo en el contador los que prefieren de humita
            contador++;
        }
        leidos = fscanf(archivo,"[^;]%i;%i\n",reg.gusto_preferido,&(reg.cuantas_se_come),&(reg.carne_con_pasas));
    }
    printf("Los que aman a humita son %i\n",contador);
    fclose(archivo);

    return 0;
}