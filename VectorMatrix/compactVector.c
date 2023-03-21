/*
Crie um vetor de 15 posições de inteiros e posteriormente realize a compactação dele, 
isto é, elimine as posições com valor zero avançando uma posição, 
com os com os valores subseqüentes do vetor. 
Dessa forma todos “zeros” devem ficar para as posições finais do vetor.
*/

#include <stdio.h>

#define SIZE 15

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

void compactVector(int *v, int size){
    int i,j;
    int vaux[size];
    //pega apenas números acima de zero e incrementa no vetor aux
    for(i=0;i<size;i++){
        if(v[i]!=0){
            vaux[j]=v[i];
            j++; 
        }
    }
    //coloca zeros ao final final do vetor aux
    for(j=j;j<size;j++){
        vaux[j]=0;
    }
    //atualiza vetor principal
    for(i=0;i<size;i++){
        v[i]=vaux[i];
    }

}

int main(){
    int v[SIZE];

    insertVector(v,SIZE);

    printf("\n");
    printf("Vetor original:   ");
    printVector(v,SIZE);

    compactVector(v,SIZE);
    printf("Vetor compactado: ");
    printVector(v,SIZE);
    printf("\n");
}