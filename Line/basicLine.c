/*
 * Implementação de Lista Encadeada Simples
 * Cria e gerencia uma lista encadeada para armazenar números inteiros.
 * O programa permite adicionar novos elementos à lista e exibir os elementos armazenados.
 *
 * Autor: Ulisses Maffazioli
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
}nodo;

int main(){
    int num, continua=0;

    nodo *inicio = NULL;
    nodo *proximo;
    nodo *pont;

    while(continua==0){
        pont=(nodo *)malloc(sizeof(nodo)); //pega um novo endereço

        // printf("Estrutura de dados pont criado\n");
        // printf("pont: %p\n",pont);
        // printf("pont->num: %i\n",pont->dado);
        // printf("pont->prox: %p\n",pont->prox);

        if(pont!=NULL){//verifica se pont é um endereço válido
            printf("Informe um valor: ");
            scanf("%i",&num);
            if(inicio==NULL){//verifica se tem inicio
                inicio=pont;
                inicio->dado=num;
                inicio->prox=NULL;
                // printf("inicio: %p\n",inicio);
                // printf("inicio->num: %i\n",inicio->dado);
                // printf("inicio->prox: %p\n",inicio->prox);
            }else{
                pont->dado=num;
                pont->prox=NULL;
                // printf("pont: %p\n",pont);
                // printf("pont->num: %i\n",pont->dado);
                // printf("pont->prox: %p\n",pont->prox);
                proximo=inicio;
                while(continua==0){
                    if(proximo->prox==NULL){
                        // printf("sou o ultimo da lista end:%p\n",proximo);
                        proximo->prox=pont;
                        continua=1;
                    }else{
                        // printf("nao sou o ultimo, sou o end:%p e vou para:%p\n",proximo,proximo->prox);
                        proximo=proximo->prox;
                    }
                }
            }
        }
        printf("\nDigite 0 para continuar: ");
        scanf("%i",&continua);
    }
    //impressão lista
    continua=0;
    pont=inicio;
    while(continua==0){
        if(pont->prox==NULL){//esse é o ultimo cara - imprime e acaba o while
            printf("%i\n",pont->dado);
            continua=1;
        }else{
            printf(" %i ->",pont->dado);
            pont=pont->prox;
        }
    }

    return 0;
}