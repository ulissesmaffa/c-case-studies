/*
 * Implementação da Sequência de Fibonacci
 * Este programa calcula o n-ésimo número na sequência de Fibonacci, onde cada número é a soma dos dois anteriores.
 * A sequência começa com 1, 1, e cada termo subsequente é calculado como f(n) = f(n-1) + f(n-2).
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função fibonacci(int n) é uma função recursiva que retorna o n-ésimo termo da sequência de Fibonacci.
 * - Para n <= 2, a função retorna 1, conforme a definição padrão da sequência.
 * - Para n > 2, a função chama a si mesma para calcular os dois termos anteriores e somá-los.
 * - Este método de cálculo tem uma complexidade de tempo exponencial devido às múltiplas chamadas recursivas para o mesmo valor.
 */

#include <stdio.h>

int fibonacci(int n){
    // printf("sou a func Fibonacci e recebi N:%i\n",n);
    if(n<=2){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    int n,f;
    printf("Digite N:\n");
    scanf("%i",&n);
    f=fibonacci(n);
    printf("Resultado: %i\n",f);

    return 0;
}

