#include <string.h>

int strlen(char cadena[]); // STRING LENGTH  (LARGO CADENA) cuenta solo los caracteres no el \0

strlen("Tomi") == 4; // EJEMPLO

void strcpy(char destino[], char origen[]) // STRING COPY (COPIAR STRING) 
// Asigna la asignacion destino == origen
destino[0] = origen[0];
destino[1] = origen[1];
//
char nombre[100];
strcpy(nombre,"Tomi");
strcpy(nombre,nombre_ingresado); 

void strcat(char destino[], char origen[]) // STRING CONCATENATE (CONCATENAR STRING)
//Unifica dos caracteres en 1 
"Hola" "como estas?" -> "Hola como estas?"

strcat(nombre, apellido);
strcat(nombre, "Rodriguez");

int strcmp (char cadena1[],char cadena2[]); // STRING COMPARE (COMPARAR STRING)
//Devuelve >0 si cadena1 > cadena2 , ==0 si cadena1 = cadena2, <0 si cadena1 < cadena2
strcmp("aaa","bbb"); < 0 -> porque aaa tiene menor numero ascii que bbb
strcmp("aaa","aaaa") < 0 -> porque aaa vale 291 y aaaa 388 
strcmp("aaa","AAA") > 0 -> porque a vale 97 y A vale 65
strcmp("aaa","abc") < 0 -> porque abc va a ser mayor que aaa 
strcmp("aaa","aaa") == 0 -> son lo mismo 
strcmp("aaa","aAa") > 0 -> porque aAa va a ser menor que aaa

'\0' != '0' -> \0 ES NULL, 0 es un caracter 0

//Imprimir strings
printf("%s", cadena);

//Leer cadenas
scanf("%s",cadena) // LEE HASTA EL PRIMER ESPACIO O \n (osea si quiero ingresar MATIAS VALLEJOS -> solo toma MATIAS)
scanf("%[^\n]", cadena); //LEE HASTA QUE SE ENCUENTRA UN \n osea cuando el usuario presiona enter


