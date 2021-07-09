#include <stdio.h>

void insercion(int vector[],int tope){
    int j;
    int aux;
    
    for(int i = 1; i<tope;i++){
        j=i;
        aux = vector[i];
        while(j > 0 && aux < vector[j-1]){
            vector[j] = vector[j-1];
            j--;
        }
        vector[j] = aux;
    }
}

int main(){

    int vector[10] = {9,10,8,7,5,6,2,3,1,4};
    int tope = 10;
    insercion(vector,tope);

    for(int i=0;i < tope; i++){
        printf(" %i ", vector[i]);
    }

    return 0;
}