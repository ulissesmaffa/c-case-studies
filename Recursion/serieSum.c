/*
5) Escreva uma função recursiva, SomaSerie(i,j,k: inteiro): inteiro, que devolva a soma
da série de valores do intervalo [i,j], com incremento k. 
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