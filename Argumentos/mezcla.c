#include <stdio.h>

typedef struct registro{



} registro_t;


int main(){

    FILE* numeros1 = fopen("numeros1","r");
    
    if(!numeros1){
        printf("No se pudo abrir numeros1\n");
        return -1;
    }

    FILE* numeros2 = fopen("numeros2","r");

    if(!numeros2){
        printf("No se pudo abrir numeros2\n");
        fclose(numeros1);
        return -1;
    }

    FILE* mezcla = fopen("mezcla_numeros", "w");

    if(!mezcla){
        printf("No se pudo crear mezcla\n");
        fclose(numeros1);
        fclose(numeros2);
        return -1;
    }

    fread(registroprimero,sieof registroprimero,1,primero);
    fread(registrosegundo,sizeof segundo,1,segundo);

    while(!feof(primero) && !feof(segundo)){
        if(reg1.padron == reg2.padron){

        }
    }

    while(!feof(segundo)){
        fwrite()
    }




    fclose(numeros1);
    fclose(numeros2);
    fclose(mezcla);

    return 0;
}