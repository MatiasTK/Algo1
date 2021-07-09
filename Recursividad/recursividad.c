// f(x) = !n; si x = 0 -> 0! = 1 || si x>0 x!=x*(x-1)! -> caso general
#include <stdio.h>

long factorial_iter(int un_numero){

    int i;
    long acumulador = 1;

    for(i = 1; i <= un_numero; i++){
        acumulador = acumulador*i;
    }
    
    return acumulador;
}

long factorial(int un_numero){      //version recursiva
    
    if(un_numero == 0){
        return 1;
    } else {
        return un_numero * factorial(un_numero - 1);
    }

}

int main(){

    printf("%ld\n", factorial_iter(5));
    printf("%ld\n", factorial(10));

    return 0;
}