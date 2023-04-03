/* 
Faça um programa que leia 3 números inteiros obrigatoriamente 
com três dígitos e depois utilizando uma função imprima o número lido de forma invertida 
(os números que foram passados por parâmetro).  Ex: 234 saída: 432
*/

#include <stdio.h>

#define SIZE 3

void printVector(int *v, int size){
    int i;

    for(i=size-1;i>=0;i--){
        printf("%i ",v[i]);
    }
    printf("\n");

}

void insertVector(int *v, int size){
    int i;

    printf("Digite %i número(s) inteiro(s):",size);
    for(i=0;i<size;i++){
        scanf("%i",&v[i]);
    }
}

int main(){
    int v[SIZE];

    insertVector(v,SIZE);
    printVector(v,SIZE);

    return 0;
}