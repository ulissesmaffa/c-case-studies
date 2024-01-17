/*
 * Nome do Programa: Programa simples funções
 * Descrição: 
 *    Programa simples para lidar com funções
 * 
 * Autor: Ulisses Maffazioli
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