#include <stdio.h>

int fatorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

float serieAny(int n){
    if(n==0){
        return 1;
    } else {
        return (1.0/fatorial(n))+serieAny(n-1);//essa merda desse 1.0 tem que ser assim, se não a porra do C entende que é inteiro. PQP, perdi preciosos minutos debugando essa merda!
    }
}

int main(){
    int n, ctl;
    float z;

    do {
        printf("Digite N maior do que zero: ");
        scanf("%i", &n);
        if(n <= 0){
            printf("Erro: digite um número maior que zero.\n");
            ctl = 0;
        } else {
            ctl = 1;
        }
    } while(ctl == 0);

    z = serieAny(n);
    printf("z=%.5f\n",z);

    return 0;
}
