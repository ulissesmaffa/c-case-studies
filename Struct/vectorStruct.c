/*
1)Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas. 
Cada pessoa deve ser representada por uma struct dentro de um vetor. 
O nome, a data de nascimento e a altura de cada pessoa devem ser informados pelo teclado.
Posteriormente imprima os nomes das pessoas que possuem altura superior a 1,78.
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 3

typedef struct{
    char nome[50];
    float altura;
    int dataNascimento[3];
} Pessoa;

void insertPessoas(Pessoa *p){
    int i;
    for(i=0;i<TAMANHO;i++){
        do{
            printf("\nInserindo pessoa %i\n",i);
            printf("Nome:");
            scanf("%s",p[i].nome);

            printf("Altura:");
            scanf("%f",&p[i].altura);

            printf("Data Nascimento (DIA MES ANO):");
            scanf("%i %i %i",&p[i].dataNascimento[0],&p[i].dataNascimento[1],&p[i].dataNascimento[2]);
        }while(p[i].altura<=0 || p[i].dataNascimento[0]<=0 || p[i].dataNascimento[0]>31 || p[i].dataNascimento[1]<=0 || p[i].dataNascimento[1]>12 || p[i].dataNascimento[2]<=0);
    }
}

void imprimirPessoas(Pessoa *p){
    int i;
    printf("\nImpressão de todas pessoas\n");
    for(i=0;i<TAMANHO;i++){
        printf("[%i] Nome: %s - Altura: %.2f - Data Nascimento: %i/%i/%i\n",i,p[i].nome,p[i].altura,p[i].dataNascimento[0],p[i].dataNascimento[1],p[i].dataNascimento[2]);
    }
}

void imprimirPessoasFiltro(Pessoa *p, float filtro){
    int i;

    printf("\nPessoas acima de %f\n",filtro);

    for(i=0;i<TAMANHO;i++){
        if(p[i].altura>1.78){
            printf("[%i] Nome: %s - Altura: %.2f - Data Nascimento: %i/%i/%i\n",i,p[i].nome,p[i].altura,p[i].dataNascimento[0],p[i].dataNascimento[1],p[i].dataNascimento[2]);
        }
    }
}

int main(){
    Pessoa pessoas[TAMANHO];
    float filtro=1.78;

    insertPessoas(pessoas);
    imprimirPessoas(pessoas);
    imprimirPessoasFiltro(pessoas,filtro);

    return 0;
}