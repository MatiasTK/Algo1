#include <stdio.h>
//---------------------------> Para realizar estas operaciones los archivos deben estar ordenados por el mismo registro
//---------------------------> En estos ejemplos utilizo el caso de tener archivos binarios,no de texto!
#define MAX_VECTOR 100

/*
Datos a considerar:
-Fseek solo se utiliza en archivos binarios de acceso directo
Formato: fseek(archivo,(int)sizeof(registro_t)*(registro.id -1),SEEK_SET)
Convierto el sizeof en int por las dudas y lo multiplico por los bytes que me quiero mover en este caso el id -1 ya que sino me paso
SEEK_SET -> Establece que ahora el principio del archivo es eso
SEEK_CUR -> Me muevo desde donde estoy parado
*/

//Mezcla de menor a mayor dos archivos
//TIENEN QUE SER ARCHIVOS BINARIOS SECUNECIALES Y ORDENADOS BAJO EL MISMO CRITERIO Y REGISTRO
void mezcla_archivos(){
    FILE* archivo1 = fopen("archivo1.dat","r");
    FILE* archivo2 = fopen("archivo2.dat","r");
    FILE* resultado = fopen("resultado.dat","w");

    if(archivo1 == NULL || archivo2 == NULL || resultado == NULL){
        fclose(archivo1);
        fclose(archivo2);
        fclose(resultado);
        printf("No se pudo abrir un archivo");
        return;
    }

    //Estos datos de arriba tambien los puedo reccibir en la firma de la funcion seria algo tipo -> firma(FILE* archivo1, FILE* archivo2, FILE* resultado)

    registro_t reg_1;
    registro_t reg_2;

    fread(&reg_1,sizeof(registro_t),1,archivo1);
    fread(&reg2,sizeof(registro_t),1,archivo2);

    while(!feof(archivo1) && !feof(archivo2)){
        if(reg_1.numero <= reg_2.numero){// Uso numero como ejemplo de campo a comparar
        fwrite(&reg_1,sizeof(registro_t),1,resultado);
        fread(&reg_1,sizeof(registro_t),1,archivo1);
        }else{
            fwrite(&reg_2,sizeof(registro_t),1,resultado);
            fread(&reg2,sizeof(registro_t),1,archivo2);
        }
    }

    if(feof(archivo1)){
        while(!feof(archivo2)){
            fwrite(&reg_2,sizeof(registro_t),1,resultado);
            fread(&reg2,sizeof(registro_t),1,archivo2);
        }
    }

    if(feof(archivo2)){
        while(!feof(archivo1)){
            fwrite(&reg_1,sizeof(registro_t),1,resultado);
            fread(&reg_1,sizeof(registro_t),1,archivo1);
        }
    }

    fclose(archivo1);
    fclose(archivo2);
    fclose(resultado);
}

//Union de menor a mayor archivos
//Pone todo lo que hay en los dos archivos exceptuando repetidos
void union_archivos(){
    FILE* archivo1 = fopen("archivo1.dat","r");
    FILE* archivo2 = fopen("archivo2.dat","r");
    FILE* resultado = fopen("resultado.dat","w");

    if(archivo1 == NULL || archivo2 == NULL || resultado == NULL){
        fclose(archivo1);
        fclose(archivo2);
        fclose(resultado);
        printf("No se pudo abrir un archivo");
        return;
    }

    //Estos datos de arriba tambien los puedo reccibir en la firma de la funcion seria algo tipo -> firma(FILE* archivo1, FILE* archivo2, FILE* resultado)

    registro_t reg_1;
    registro_t reg_2;

    fread(&reg_1,sizeof(registro_t),1,archivo1);
    fread(&reg2,sizeof(registro_t),1,archivo2);

    while(!feof(archivo1) && !feof(archivo2)){
        if(reg_1.numero <= reg_2.numero){// Uso numero como ejemplo de campo a comparar
        fwrite(&reg_1,sizeof(registro_t),1,resultado);
        fread(&reg_1,sizeof(registro_t),1,archivo1);
        }else{
            fwrite(&reg_2,sizeof(registro_t),1,resultado);
            fread(&reg2,sizeof(registro_t),1,archivo2);
        }
    }

    fclose(archivo1);
    fclose(archivo2);
    fclose(resultado);
}

//Pone lo que hay en el primer archivo si no esta en el segundo
void diferencia_archivos(){
    FILE* archivo1 = fopen("archivo1.dat","r");
    FILE* archivo2 = fopen("archivo2.dat","r");
    FILE* resultado = fopen("resultado.dat","w");

    if(archivo1 == NULL || archivo2 == NULL || resultado == NULL){
        fclose(archivo1);
        fclose(archivo2);
        fclose(resultado);
        printf("No se pudo abrir un archivo");
        return;
    }

    //Estos datos de arriba tambien los puedo reccibir en la firma de la funcion seria algo tipo -> firma(FILE* archivo1, FILE* archivo2, FILE* resultado)

    registro_t reg_1;
    registro_t reg_2;

    fread(&reg_1,sizeof(registro_t),1,archivo1);
    fread(&reg2,sizeof(registro_t),1,archivo2);

    while(!feof(archivo1) && !feof(archivo2)){
        if(reg_1.numero == reg_2.numero){// Uso numero como ejemplo de campo a comparar
            fread(&reg_1,sizeof(registro_t),1,archivo1);
            fread(&reg2,sizeof(registro_t),1,archivo2);
        }else if(reg_1.numero  < reg_2.numero){
            fwrite(&reg_1,sizeof(registro_t),1,resultado);
            fread(&reg_1,sizeof(registro_t),1,archivo1);
        }else{
            fread(&reg2,sizeof(registro_t),1,archivo2);
        }
    }

    if(feof(archivo2)){
        while(!feof(archivo1)){
            fwrite(&reg_1,sizeof(registro_t),1,resultado);
            fread(&reg_1,sizeof(registro_t),1,archivo1);
        }
    }


    fclose(archivo1);
    fclose(archivo2);
    fclose(resultado);
}

//Copia solo lo que esta en ambos archivos , osea tiene que estar en el primero y en el segundo
void diferencia_archivos(){
    FILE* archivo1 = fopen("archivo1.dat","r");
    FILE* archivo2 = fopen("archivo2.dat","r");
    FILE* resultado = fopen("resultado.dat","w");

    if(archivo1 == NULL || archivo2 == NULL || resultado == NULL){
        fclose(archivo1);
        fclose(archivo2);
        fclose(resultado);
        printf("No se pudo abrir un archivo");
        return;
    }

    //Estos datos de arriba tambien los puedo reccibir en la firma de la funcion seria algo tipo -> firma(FILE* archivo1, FILE* archivo2, FILE* resultado)

    registro_t reg_1;
    registro_t reg_2;

    fread(&reg_1,sizeof(registro_t),1,archivo1);
    fread(&reg2,sizeof(registro_t),1,archivo2);

    while(!feof(archivo1) && !feof(archivo2)){
        if(reg_1.numero == reg_2.numero){// Uso numero como ejemplo de campo a comparar
            fwrite(&reg_1,sizeof(registro_t),1,resultado);
            fread(&reg_1,sizeof(registro_t),1,archivo1);
            fread(&reg2,sizeof(registro_t),1,archivo2);
        }else if(reg_1.numero  < reg_2.numero){
            fread(&reg_1,sizeof(registro_t),1,archivo1);
        }else{
            fread(&reg2,sizeof(registro_t),1,archivo2);
        }
    }

    fclose(archivo1);
    fclose(archivo2);
    fclose(resultado);
}

/*
* PRE: el archivo debe estar cargado en un vector -> Para esto nos tienen que aclarar que el archivo tiene un maximo para entrar en el vector, sino NO SE PUEDE
* POST: ordena el vector del archivo
*/
void bubble_sort_archivos(vector_t vector[MAX_VECTOR],int tope){
    /*
    Como cargo el archivo en un vector y obtengo el tope?
    -Creo vector_t vector[MAX_vector]
    -Creo el tope -> size_t tope = fread(vector,sizeof(vector_t),MAX_INDICADO,archivo);
    -Lo envio como referencia a esta funcion
    */

    int i; 
    int j;
    vector_t aux;

    for(i = 0;i < tope; i++){
        for(j = 0; j < (tope-1-i);j++){
            if(strcmp(vector[j].nombre,vector[j+1].nombre) > 0){ //En este caso uso strcmp porque estoy comparando strings si fueran numeros no lo necesito usar
            aux = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = aux;
            }
        }
    }


    /*
    Para finalizar y escribir esto en otra funcion:
    -Abro el archivo donde quiero escribirlo fopen bla bla bla
    -Solo hago fwrite(vector,sizeof(vector_t),MAX_INDICADO,archivo_a_escribir);
    */

}
