/*
 * Implementação da Função de Ackermann
 * Este programa calcula a função de Ackermann, uma função matemática recursiva que é um exemplo notável
 * de uma função que é recursiva mas não é primitivamente recursiva.
 * Os usuários podem inserir valores para 'm' e 'n', e o programa calculará a(m, n) usando a definição clássica da função de Ackermann.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * A função de Ackermann é definida recursivamente como segue:
 * - a(m, n) = n + 1, se m == 0
 * - a(m, n) = a(m - 1, 1), se m != 0 && n == 0
 * - a(m, n) = a(m - 1, a(m, n - 1)), se m != 0 && n != 0
 * Esta implementação segue diretamente a definição, usando chamadas recursivas para calcular os valores.
 * Devido à natureza da função, para grandes valores de 'm' e 'n', o programa pode consumir muitos recursos ou levar muito tempo para ser concluído.
 */

#include <stdio.h>

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0 && m != 0) {
        return ackermann(m - 1, 1);
    } else if (m != 0 && n != 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    } else {
        return 0;
    }
}

int main() {
    int m, n;
    printf("Enter values for m and n:\n");
    scanf("%d %d", &m, &n);
    printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
    return 0;
}