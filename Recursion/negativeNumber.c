/*
3) Escreva uma função recursiva que faça o seguinte: leia um número; se o número for
negativo, a função para; caso contrário, a função imprime o número e faz uma
chamada recursiva a si mesma. 
*/

#include <stdio.h>

void negativeNum(int n){
    if(n<0){
        return;
    }else{
        printf("valor de n=%d\n",n);
        negativeNum(n-1);
    }


}

int main(){
    int z,n;
    printf("Digite um número:");
    scanf("%d",&n);
    negativeNum(n);
    return 0;
}