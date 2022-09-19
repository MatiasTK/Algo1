#include <stdio.h>
#include <string.h>

int fileUnion()

int main(int argc,char* argv[]){
    if(argc == 2){
        if(strcmp(argv[1], "--show") ==0){
            mostrarArchivo("archivo1.dat");
            mostrarArchivo("archivo2.dat");
        }else if(strcmp(argv[1], "--union") == 0){
            if(fileUnion("archivo1.dat","archivo2.dat","union.dat") >0){
                mostrarArchivo("union.dat");
            }
        }else if(strcmp(argv[1], "--help") == 0){
            printf("--show muestra los dos archivos\n");
            printf("--union realiza la union de los dos archivos\n");
            printf("--help muestra el help\n");
        }
    } else{
        printf("Mal invocado el programa\n");
    }

    return 0;
}