/*
 * Cálculo de Série Matemática Usando Recursão
 * Este programa calcula o valor de uma série matemática definida pela relação S(n) = (1 + n²)/n + S(n-1), 
 * com S(1) = 2, para um valor positivo de n fornecido pelo usuário.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função serieS(float n) é recursiva e calcula o valor da série para um dado n.
 * - A condição de parada da recursão é quando n é igual a 1.
 * - A função main() solicita ao usuário um valor positivo para n e exibe o resultado calculado.
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