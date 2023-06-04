/*
Elabore um programa que armazene valores em um vetor de inteiros com 10 posições 
e inicie cada elemento com o valor de 1 a 10. Codifique uma função recursiva  que 
imprima todos os elementos em ordem e uma função recursava que imprima todos os elementos na ordem inversa.
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