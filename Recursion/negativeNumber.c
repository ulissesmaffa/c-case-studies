/*
 * Função Recursiva para Impressão de Números Não Negativos
 * Este programa utiliza uma função recursiva para imprimir números não negativos em ordem decrescente
 * até atingir um número negativo, onde a recursão é interrompida.
 * 
 * Autor: Ulisses Maffazioli
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