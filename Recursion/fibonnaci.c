/*
f(n)=f(n-1)+f(n-2)
*/

#include <stdio.h>

int fibonacci(int n){
    // printf("sou a func Fibonacci e recebi N:%i\n",n);
    if(n<=2){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    int n,f;
    printf("Digite N:\n");
    scanf("%i",&n);
    f=fibonacci(n);
    printf("Resultado: %i\n",f);

    return 0;
}

//1,1,2,3,5,8,13,21,34

