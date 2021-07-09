#include <stdio.h>
#include <stdbool.h>


#define MAX_RESPUESTAS 300

const char SI = 'S';
const char NO = 'N';
const char EDD_SI = 'E';
const char EDDY_SI = 'D';

const char LIBRA = 'L';
const char PISCIS = 'P';
const char ACUARIO = 'A';
const char CANCER = 'C';


bool tienen_mismo_signo(char respuestas[MAX_RESPUESTAS], int tope_respuestas) {
    
    int contador_ed = 0;
    int contador_eddy = 0;

    char SIGNO_ED;
    char SIGNO_EDDY;

    bool resultado;

    for(int i = 0; i < tope_respuestas; i++){
        if(respuestas[i] == 'S'){
            contador_ed++;
            contador_eddy++; 
        } else if(respuestas[i] == 'E'){
            contador_ed++;
        } else if(respuestas[i] == 'D'){
            contador_eddy++;
        }
    }

    if(contador_ed > 0 && contador_ed <= 2){
        SIGNO_ED = LIBRA;
    } else if(contador_ed >= 3 && contador_ed <= 5){
        SIGNO_ED = PISCIS;
    } else if(contador_ed >= 6 && contador_ed <= 8){
        SIGNO_ED = ACUARIO;
    } else if(contador_ed > 8){
        SIGNO_ED = CANCER;
    }

    if(contador_eddy > 0 && contador_eddy <= 2){
        SIGNO_EDDY = LIBRA;
    } else if(contador_eddy >= 3 && contador_eddy <= 5){
        SIGNO_EDDY = PISCIS;
    } else if(contador_eddy >= 6 && contador_eddy <= 8){
        SIGNO_EDDY = ACUARIO;
    } else if(contador_eddy > 8){
        SIGNO_EDDY = CANCER;
    }

    if(SIGNO_ED == SIGNO_EDDY){
        resultado = true;
    } else if (SIGNO_ED != SIGNO_EDDY){
        resultado = false;
    }

    return resultado;
}