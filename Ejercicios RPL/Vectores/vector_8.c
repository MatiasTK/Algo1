#define MAX_DIAS  7

void intercambiar_comidas(int comidas_original[MAX_DIAS], int comidas_intercambiadas[MAX_DIAS]){


    comidas_intercambiadas[MAX_DIAS] = comidas_original[MAX_DIAS];
    comidas_intercambiadas[0] = comidas_original[3];
    comidas_intercambiadas[1] = comidas_original[5];
    comidas_intercambiadas[2] = comidas_original[2];
    comidas_intercambiadas[3] = comidas_original[0];
    comidas_intercambiadas[4] = comidas_original[4];
    comidas_intercambiadas[5] = comidas_original[1];
    comidas_intercambiadas[6] = comidas_original[6];

    

}

int main(){

int comidas_original[MAX_DIAS] = {1, 4, 6, 2, 5, 1, 7};
int comidas_intercambiadas[MAX_DIAS];

intercambiar_comidas(comidas_original, comidas_intercambiadas);
  
return 0;  


}
