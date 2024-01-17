/*
 * Implementação da Função de Máximo Divisor Comum (MDC) - Método Recursivo
 * Este programa calcula o maior divisor comum (MDC) de dois números inteiros usando o algoritmo de Euclides de forma recursiva.
 * O usuário é solicitado a inserir dois números, e o programa retorna o MDC desses números.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função mdc(int x, int y) implementa o algoritmo de Euclides para o cálculo do MDC.
 *   Se o segundo número (y) é zero, a função retorna o primeiro número (x) como MDC.
 *   Caso contrário, a função chama a si mesma com os argumentos y e o resto da divisão de x por y.
 * - Esta abordagem recursiva simplifica a implementação do algoritmo e é eficiente para calcular o MDC.
 */

#include <stdio.h>

// Função recursiva para calcular o MDC
int mdc(int x, int y){
    if (y == 0) {
        return x;
    } else {
        return mdc(y, x % y);
    }
}

int main(){
    int x, y, z;
    printf("Digite dois números para calcular o MDC: \n");
    scanf("%i %i", &x, &y);

    z = mdc(x, y);
    printf("O MDC de %i e %i é %i\n", x, y, z);

    return 0;
}
