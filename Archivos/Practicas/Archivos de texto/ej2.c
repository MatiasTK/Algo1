#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 50

const char VOTO_FAVOR = 1;
const char VOTO_CONTRA = 0;

void imprimir_votos(){
    FILE* archivo = fopen("firmas_para_la_liberacion_del_insta.txt","r");

    if(!archivo){
        perror("No se pudo abrir firmas_para_la_liberacion_del_insta.txt");
        return;
    }

    char nombre[MAX_NOMBRE];
    int voto;

    size_t leer = fscanf(archivo,"%[^;];%i\n",nombre,&voto);
    
    while(leer == 2){
        if(voto == VOTO_FAVOR){
            printf("%s votó a favor! Ya te mando el cuarto de helado prometido.\n",nombre);
        }else{
            printf("%s votó en contra. No hay helado para él. >:c\n",nombre);
        }
        leer = fscanf(archivo,"%[^;];%i\n",nombre,&voto);
    }

    fclose(archivo);
}

void borrar_charly_repetido(){
    FILE* archivo = fopen("firmas_para_la_liberacion_del_insta.txt","r");

    if(!archivo){
        perror("No se pudo abrir firmas_para_la_liberacion_del_insta.txt");
        return;
    }

    FILE* arreglado = fopen("firmas_arregladas.txt","w");

    if(!arreglado){
        perror("No se pudo crear firmas_arreglado.txt");
        return;
    }

    char nombre[MAX_NOMBRE];
    int voto;
    bool hay_charly = false;

    size_t leer = fscanf(archivo,"%[^;];%i\n",nombre,&voto);

    while(leer == 2){
        if(strcmp(nombre,"Charly") == 0 && hay_charly == false){
            fprintf(arreglado,"%s;%i\n",nombre,voto);
            hay_charly = true;
        }else if(strcmp(nombre,"Charly") != 0){
            fprintf(arreglado,"%s;%i\n",nombre,voto);
        }
        leer = fscanf(archivo,"%[^;];%i\n",nombre,&voto);
    }

    fclose(archivo);
    fclose(arreglado);

    //Esto es para no crear un archivo nuevo sino reemplazar el ya existente con la informacion corregida
    // remove("firmas_para_la_liberacion_del_insta.txt");
    // rename("firmas_arreglado.txt","firmas_para_la_liberacion_del_insta.txt"); 

int main(){

    imprimir_votos();
    borrar_charly_repetido();

    return 0;
}