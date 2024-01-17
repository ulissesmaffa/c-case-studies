/*
 * Impressão de Vetor em Ordem e Ordem Inversa Usando Recursão
 * Este programa armazena valores de 1 a 10 em um vetor de inteiros e implementa duas funções recursivas:
 * uma para imprimir os elementos do vetor em ordem e outra para imprimi-los na ordem inversa.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função printVectorInverso(int *v, int size) imprime os elementos do vetor na ordem inversa.
 * - A função printVectorOrdenado(int *v, int size) imprime os elementos do vetor em ordem.
 * - Ambas as funções utilizam recursão para percorrer o vetor, ajustando o ponteiro e o tamanho do vetor a cada chamada.
 */

#include <stdio.h>

void printVectorInverso(int *v, int size){
    int i;
    if(size==0){
        return;
    }else{
        printVectorInverso(v+1,size-1);
        printf("%i ",*v);
    }
}

void printVectorOrdenado(int *v, int size){
    int i;
    if(size==0){
        return;
    }else{
        printf("%i ",*v);
        printVectorOrdenado(v+1,size-1);
    }
}

int main(){
    int size=5;
    int v[5]={1,2,3,4,5};

    printVectorInverso(v,size);
    printf("\n");
    printVectorOrdenado(v,size);

    return 0;
}