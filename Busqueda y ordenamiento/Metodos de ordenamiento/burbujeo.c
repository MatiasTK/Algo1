#include <stdio.h>

void swap(int* a,int* b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

void bubble_sort(int array[], int tope){
    for(int i=0;i<tope-1;i++){
        for(int j=0; j<tope-i-1;j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

int main(){

    int array[10]={9,10,8,7,5,6,2,3,1,4};
    int tope = 10;
    bubble_sort(array,tope);

    for(int i=0;i < tope; i++){
        printf(" %i ", array[i]);
    }

    return 0;
}