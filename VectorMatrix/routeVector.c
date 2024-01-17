/*
 * Leitura de Vetor de Trajetórias
 * Este programa lê um vetor de 9 elementos, onde cada elemento especifica o índice do próximo elemento a ser lido na sequência.
 * A função routeVector segue a trajetória definida pelos valores do vetor e exibe a sequência resultante.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - O vetor de trajetórias é inicializado com valores pré-definidos, representando os índices a serem seguidos.
 * - A função printVector exibe o vetor original.
 * - A função routeVector determina e exibe a sequência de leitura com base na trajetória definida pelo vetor.
 */

#include <stdio.h>
#define SIZE 10

void printVector(int *v, int size){
    int i;

    for(i=0;i<size;i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}

void routeVector(int *v, int size){
    int i,j;
    int vaux[size];

    j=0;
    for(i=0;i<size;i++){
        vaux[i]=v[j];
        j=v[j];
    }
    printVector(vaux,size);
}

int main(){
    int v[]={1,5,7,6,9,2,8,4,0,3};

    printVector(v,SIZE);
    routeVector(v,SIZE);

    return 0;
}