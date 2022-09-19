# include < stdio .h >
# include < string .h >
# include " alumnos .h"

int fileunion ( const char * name_one_file , const char * name_second_file , const char *
name_result_file ){

FILE * one_file ;
FILE * second_file ;
FILE * result_file ;
alumno_t reg_one_file ;
alumno_t reg_second_file ;

/*
*
* apertura de los archivos y validaci´on
*
*/
one_file = fopen ( name_one_file ,"r");
if (! one_file ) {
perror (" Error apertura primer archivo ");
return -1;
}

second_file = fopen ( name_second_file ,"r");
if (! second_file ){
perror (" Error apertura segundo archivo ");
return -1;
}

result_file = fopen ( name_result_file ,"w");
if (! result_file ){
perror (" Error apertura archivo de salida ");
return -1;
}

/*
*
* proceso de los archivos
*
*/

fread (& reg_one_file , sizeof reg_one_file ,1 , oneFile ) ;
fread (& reg_second_file , sizeof reg_second_file ,1 , secondFile ) ;

while (! feof ( oneFile ) && ! feof ( secondFile ) ) {
if( reg_one_file . padron == reg_second_file . padron ){
fwrite (& reg_one_file , sizeof reg_one_file ,1 , result_file );
fread (& reg_one_file , sizeof reg_one_file ,1 , oneFile ) ;
fread (& reg_second_file , sizeof reg_second_file ,1 , secondFile ) ;
} else if ( reg_one_file . padron < reg_second_file . padron ) {
fwrite (& reg_one_file , sizeof reg_one_file ,1 , result_file
);
fread (& reg_one_file , sizeof reg_one_file ,1 , oneFile ) ;
} else {
fwrite (& reg_second_file , sizeof reg_second_file ,1 ,
result_file );
fread (& reg_second_file , sizeof reg_second_file ,1 ,
secondFile );
}
}
while (! feof ( secondFile ) ){
fwrite (& reg_second_file , sizeof reg_second_file ,1 , result_file );
fread (& reg_second_file , sizeof reg_second_file ,1 , secondFile );
}
while (! feof ( oneFile )){
fwrite (& reg_one_file , sizeof reg_one_file ,1 , result_file );
fread (& reg_one_file , sizeof reg_one_file ,1 , oneFile ) ;
}
/*
*
* cierre de los archivos
*
*/
fclose ( oneFile );
fclose ( secondFile );
fclose ( result_file );
return 1;
}
void mostrarArchivo ( const char * nameFile ){
FILE * unStream ;
Talumno unRegistro ;
unStream = fopen ( nameFile ,"r") ;
printf (" Registros del archivo : %s \n", nameFile );
fread (& unRegistro , sizeof unRegistro ,1 , unStream );
while ( ! feof ( unStream ) ){
printf (" %li\t %s\t %li\n", unRegistro . padron , unRegistro . nombre , unRegistro . dni ) ;
fread (& unRegistro , sizeof unRegistro ,1 , unStream );
}
printf ("\n") ;
fclose ( unStream ) ;
}
int main () {
mostrarArchivo (" licsist . dat ");
mostrarArchivo (" inginfo . dat ");
if ( fileunion (" licsist . dat "," inginfo . dat "," union . dat ") >0 ) mostrarArchivo (" union .
dat ") ;
return 0;
}