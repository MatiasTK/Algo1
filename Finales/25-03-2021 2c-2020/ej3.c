#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 50

typedef struct heroe {
    char nombre_real [MAX_NOMBRE];
    char nombre_heroe [MAX_NOMBRE];
    int crimenes_combatidos;
} heroe_t;

//Formato resultado-> nombre_real;crimenes_combatidos

void revelar_heroes(){
    FILE* heroes = fopen("heroes.csv","r");
    if(!heroes){
        perror("No se pudo abrir heroes.csv");
        return;
    }
    FILE* identidades = fopen("identidades.dat","r"); // BINARIO
    if(identidades == NULL){
        fclose(heroes);
        perror("No se pudo leer identidades.dat");
        return;
    }
    FILE* resultado = fopen("heroes_revelados.txt","w");
    if(!resultado){
        fclose(heroes);
        fclose(identidades);
        perror("No se pudo crear heroes_revelados.txt");
        return;
    }

    heroe_t heroe;
    char heroe_buscado[MAX_NOMBRE];

    int leer_texto = fscanf(heroes,"%[^\n]\n",heroe_buscado);
    int leer_binario = fread(&heroe,sizeof(heroe_t),1,identidades);
    //Es una especie de union de archivos.
    while((leer_texto == 1) && (!feof(identidades))){
        if(strcmp(heroe.nombre_heroe,heroe_buscado) == 0){
            fprintf(resultado,"%s;%i\n",heroe.nombre_real,heroe.crimenes_combatidos);
            leer_texto = fscanf(heroes,"%[^\n]\n",heroe_buscado);
            leer_binario = fread(&heroe,sizeof(heroe_t),1,identidades);
        }else if(strcmp(heroe.nombre_heroe,heroe_buscado) > 0){
            int leer_binario = fread(&heroe,sizeof(heroe_t),1,identidades);
        }else{
            leer_texto = fscanf(heroes,"%[^\n]\n",heroe_buscado);
        }
    }


    fclose(heroes);
    fclose(identidades);
    fclose(resultado);
}