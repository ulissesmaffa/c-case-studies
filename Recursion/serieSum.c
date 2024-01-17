/*
 * Cálculo da Soma de uma Série Numérica Usando Função Recursiva
 * Este programa calcula a soma de uma série de números no intervalo [i, j] com um incremento de k usando uma função recursiva.
 * O usuário fornece os valores de i, j e k, e a função recursiva SomaSerie(i, j, k) retorna a soma dos números correspondentes.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função serieSum(int i, int j, int k) é recursiva e calcula a soma dos valores de i até j, incrementando i por k a cada chamada.
 * - A função main() assegura que o usuário forneça valores válidos para i, j e k, com i menor que j e k adequado para o intervalo.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int serieSum(int i, int j, int k){
    if(i>j){
        return 0;
    }else{
        printf("i=%d\n",i);
        return i+serieSum(i+k,j,k);
    }
}

int main(){
    int i,j,k,sum,ctl;

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

    sum=serieSum(i,j,k);
    printf("sum=%d\n",sum);

    return 0;
}