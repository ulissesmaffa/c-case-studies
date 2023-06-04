/*
Faça um programa que pergunte ao usuário quantos valores ele deseja armazenar em um vetor de doubles, 
depois use a função MALLOC para reservar (alocar) o espaço de memória de acordo com o especificado pelo usuário. 
Use este vetor dinâmico como um vetor comum, atribuindo aos 10 primeiros elementos do vetor valores aleatórios (rand) 
entre 0 e 100. Exiba na tela os valores armazenados nos 10 primeiros elementos do vetor 
(O vetor deve ter pelo menos um tamanho igual a 10 doubles, ou mais). 
*/

#include <stdio.h>
#include <stdlib.h>

void insertVector(double *v, int size){
    int i;
    for(i=0;i<size;i++){
        v[i]=rand()%50;
    }
}

void printVector(double *v, int size){
    int i,tam=0;
    for(i=0;i<size;i++){
        printf("%2.f ",v[i]);
        tam++;
    }
    printf("\ntam:%i\n",tam);
}

int main(){
    int qtd;
    double *v;
    printf("Digite quantidade:\n");
    scanf("%d",&qtd);

    v = (double *) malloc(qtd * sizeof(double)); 

    insertVector(v,qtd); 
    printVector(v,qtd); 

    free(v);
    
    return 0;
}