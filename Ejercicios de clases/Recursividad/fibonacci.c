#include <stdio.h>

//Si n = 0 -> 0 | si n = 1 -> 1 | si n > 1 -> fib(n-1)+fib(n-2)
int fibonacci(unsigned int n){

    if(n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return fibonacci(n-1)+fibonacci(n-2);
    }

}

int main(){

    unsigned int n = 6;

    printf("El numero de fibonacci de la posicion %i es:  %i\n", n-1, fibonacci(n));

    return 0;
}