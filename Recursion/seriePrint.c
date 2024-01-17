/*
 * Impressão de Série Numérica com Função Recursiva
 * Este programa imprime uma série de números no intervalo [i, j] com um incremento de k, usando uma função recursiva.
 * O usuário fornece os valores de i, j e k, e a função recursiva ImprimeSerie(i, j, k) imprime os números correspondentes.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função seriePrint(int i, int j, int k) é recursiva e imprime os valores de i até j, incrementando por k a cada chamada.
 * - A função main() garante que o usuário forneça valores válidos para i, j e k, com i menor que j e k adequado para o intervalo.
 */

#include <stdio.h>
#include <stdlib.h>

void seriePrint(int i, int j, int k){
    if(i>j){
        return;
    }else{
        printf("i=%d\n",i);
        seriePrint(i+k,j,k);
    }
}

int main(){
    int i,j,k,ctl;
    do{
        printf("digite i,j e k:\n");
        scanf("%d %d %d",&i,&j,&k);
        if(i>=j){
            printf("Erro: i é maior do que j\n");
            ctl=0;
        }else if(k>=(abs(i)+abs(j))){
            printf("Erro: k é maior do que o tamanho da série\n");
            ctl=0;
        }else{
            ctl=1;
        }
        printf("tamanho da série:%d\n",abs(i)+abs(j));
    }while(ctl==0);

    seriePrint(i,j,k);

    return 0;
}