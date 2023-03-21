/*
Crie um vetor de 20 posições de inteiros.  
Após o vetor estar todo preenchido com valores informados pelo teclado, 
solicite ao usuário a informação de um número, o qual será procurado no vetor. 
Se o valor for encontrado informe em que posição ele se encontra 
(a primeira, caso ele esteja armazenado em mais de uma posição). 
Utilize mensagem adequada para o caso do valor não estar armazenado no vetor.
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