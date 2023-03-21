/*
Crie um vetor de 16 posições de inteiros (receba os valores pelo teclado para serem armazenados). 
Posteriormente, troque os 8 primeiros valores pelos 8 últimos e vice-e-versa. 
Escreva ao final o vetor obtido.
*/

#include<stdio.h>

#define SIZE 16

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

//Função troca as 8 posições finais do vetor para as primeiras 8 prosições 
//e empurra as antigas 8 para serem as últimas 8 posições
void changeVector(int *v, int size){
    int i,j=0;
    int vaux[size];

    for(i=size/2;i<size;i++){
        vaux[j]=v[i];
        j++;
    }    
    for(i=0;i<size/2;i++){
        vaux[j]=v[i];
        j++;
    }
    printVector(vaux,size);
}

int main(){
    int v[SIZE];
    
    insertVector(v,SIZE);
    printVector(v,SIZE);
    changeVector(v,SIZE);

    return 0;
}