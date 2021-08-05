#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_FECHA_NACIMIENTO 8

typedef struct hobbit {
    char nombre[MAX_NOMBRE];
    char fecha_nacimiento[MAX_FECHA_NACIMIENTO];
    char pareja_de[MAX_NOMBRE];
    int dni;
}hobbit_t;

//2 binarios secuencial -> mama_sam.dat y papa_sam.dat
//Ambos ordenados por dni de hobbit de hobbit_t

/*
* PRE: hobbit_t debe ser un struct valido
* POST: crea el archivo familiares.dat con la informacion de los antepasados en comun y devuelve la cantidad de antepasados en comun con diferente pareja
*/
int parientes_en_comun(){
    FILE* madre_archivo = fopen("mama_sam.dat","r");
    FILE* padre_archivo = fopen("papa_sam.dat","r");
    FILE* familiares_comun = fopen("familiares.dat","w");

    if(madre_archivo == NULL || padre_archivo == NULL || familiares_comun == NULL){
        fclose(madre_archivo);
        fclose(padre_archivo);
        fclose(familiares_comun);
        perror("No se pudo abrir algun archivo");
        return -1;
    }

    hobbit_t madre;
    hobbit_t padre;
    hobbit_t familiares;

    int leer_madre = fread(&madre,sizeof(hobbit_t),1,madre_archivo);
    int leer_padre = fread(&padre,sizeof(hobbit_t),1,padre_archivo);

    int diferentes_parejas = 0;

    while(!feof(madre_archivo) && !feof(padre_archivo)){
        if(strcmp(madre.nombre,padre.nombre) == 0){
            fwrite(&familiares,sizeof(hobbit_t),1,familiares_comun);
            if(strcmp(madre.pareja_de,padre.pareja_de) != 0){
                diferentes_parejas++;
            }
            leer_madre = fread(&madre,sizeof(hobbit_t),1,madre_archivo);
            leer_padre = fread(&padre,sizeof(hobbit_t),1,padre_archivo);
        }else if(strcmp(madre.nombre,padre.nombre) < 0){
            leer_madre = fread(&madre,sizeof(hobbit_t),1,madre_archivo);
        }else{
            leer_padre = fread(&padre,sizeof(hobbit_t),1,padre_archivo);
        }
    }

    fclose(madre_archivo);
    fclose(padre_archivo);
    fclose(familiares_comun);

    return diferentes_parejas;
}

int main(){
    parientes_en_comun();
    return 0;
}