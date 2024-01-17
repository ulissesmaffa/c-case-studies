/*
 * Pesquisa de Valor em um Vetor de Inteiros
 * Este programa cria um vetor de 20 posições de inteiros, preenchido com valores inseridos pelo usuário.
 * Após o preenchimento, o programa solicita um número para pesquisa e identifica se ele está presente no vetor,
 * informando a primeira posição de sua ocorrência ou indicando se o valor não foi encontrado.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - O vetor é preenchido com valores fornecidos pelo usuário.
 * - A função printVector exibe o vetor.
 * - A função searchVector procura pelo valor informado no vetor e exibe a posição da primeira ocorrência ou uma mensagem caso não seja encontrado.
 */

#include <stdio.h>
#define SIZE 20

void insertVector(int *v, int size){
    int i;

    printf("Digite %i número(s):\n",size);
    for(i=0;i<size;i++){
        scanf("%i",&v[i]);
    }
}

void printVector(int *v, int size){
    int i;

    for(i=0;i<size;i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}

void searchVector(int *v, int size, int search){
    int i;

    for(i=0;i<size;i++){
        if(v[i]==search){
            printf("Valor %i encontrado na posição %i\n",search,i);
        }
    }
    printf("O valor %i não foi encontrado!\n",search);
}

int main(){
    int v[SIZE];
    int search,res;

    insertVector(v,SIZE);
    printVector(v,SIZE);
    printf("Digite um número para procurar:");
    scanf("%i",&search);
    searchVector(v,SIZE,search);

    return 0;
}