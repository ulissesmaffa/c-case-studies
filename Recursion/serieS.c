/*
6) Faça uma função recursiva, em linguagem C, que calcule o valor da série S descrita a
seguir para um valor n>0 a ser fornecido como parâmetro para a mesma. 
*/
#include <stdio.h>
#include <math.h>

float serieS(float n){
    if(n==1){
        return 2;
    }else{
        return ((1+(n*n))/n)+serieS(n-1);
    }
}

int main(){
    int n,ctl;
    float z;

    do{
        printf("digite N maior do que zero:\n");
        scanf("%i",&n);
        if(n<0){
            printf("Erro, digitar número maior que zero\n");
            ctl=0;
        }else{
            ctl=1;
        }
    }while(ctl==0);

    z=serieS(n);
    printf("z=%.2f\n",z);

    return 0;
}