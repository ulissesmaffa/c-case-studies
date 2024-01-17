/*
 * Gerenciamento de Informações de Pessoas
 * Este programa armazena e exibe informações de até 10 pessoas, incluindo nome, altura e data de nascimento.
 * Permite inserir dados pelo teclado e imprime os nomes das pessoas com altura superior a 1,78 metros.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - Utiliza uma struct chamada Pessoa para armazenar as informações de cada pessoa.
 * - As informações são inseridas pelo usuário e armazenadas em um vetor de Pessoa.
 * - Inclui funções para inserir dados, imprimir todos os dados e imprimir dados com filtro de altura.
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