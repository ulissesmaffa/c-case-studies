/* 
Elabore um programa que cria um vetor de 5 posições de inteiros
utilizando uma função altere os valores do vetor lido com o valor de cada elemento do vetor pela multiplicação
dele pelo número lido
*/

#include <stdio.h>

#define SIZE 5

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