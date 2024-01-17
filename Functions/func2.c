/*
 * Nome do Programa: Programa simples funções
 * Descrição: 
 *    Programa simples para lidar com funções
 * 
 * Autor: Ulisses Maffazioli
 */
#include <stdio.h>

int func(int *n){
    int mod;
    float gamb;

    mod=(*n)%10;

    // (*n)=(float)(*n)/10;
    
    gamb=(float)(*n);
    gamb=gamb/10;
    (*n)=gamb;

    return mod;
}

int main(){
    int num;

    printf("\nInforme um número:");
    scanf("%d",&num);
    printf("Resto da divisão por 10: %i\n",func(&num));
    printf("[1] Novo valor de num: %.2f\n",(float)num/10);
    printf("[3] Novo valor de num: %.2f\n\n",(float)num);

    return 0;
}