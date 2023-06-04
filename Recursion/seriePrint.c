/*
4) Escreva uma função recursiva, ImprimeSerie(i,j,k: inteiro), que imprime na tela a
série de valores do intervalo [i,j], com incremento k. 
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