/*
 * Cálculo de Série Matemática Usando Recursão
 * Este programa calcula o valor de uma série matemática definida pela soma dos inversos dos fatoriais de 1 até n.
 * O usuário fornece um valor inteiro positivo para n, e o programa retorna o valor da série.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função fatorial(int n) retorna o fatorial de n.
 * - A função serieAny(int n) calcula a soma dos inversos dos fatoriais de 1 até n de forma recursiva.
 * - O programa utiliza um loop para garantir que o usuário forneça um número maior que zero.
 */

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
