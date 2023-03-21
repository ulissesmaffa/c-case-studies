/*
Considere um vetor de trajetórias de 9 elementos, onde cada elemento possui o valor do próximo elemento do vetor a ser lido. 
    Índice  1    2    3    4    5    6    7     8     9  
	Valor   5    7    6    9    2    8    4     0     3 
Assim, a seqüência da leitura seria 1, 5, 2, 7, 4, 9, 3, 6, 8, 0
Faça um algoritmo que seja capaz de ler esse vetor e seguir a trajetória.
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