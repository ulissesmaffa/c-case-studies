/*
 * Implementação de Equação de Diferenças Lineares
 * Este programa resolve uma equação de diferenças lineares definida pela relação:
 * y[n] + 0.2y[n-1] - 0.5y[n-2] = x[n-1], onde y[n] = x[n-1] - 0.2y[n-1] + 0.5y[n-2]
 * A sequência de entrada x[n] é definida como {1, 2, 3, ..., 10}, e as condições iniciais são zero.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função calc_x(int n) calcula os valores de x[n] de forma recursiva com base na condição x = n(u[n] - u[n-11]),
 *   onde u é a função degrau unitário.
 * - A função calc_y(int n) resolve a equação de diferenças para y[n] utilizando recursão.
 * - As condições iniciais para y[n] são estabelecidas como zero.
 * - O programa solicita ao usuário o número de amostras 'n' e calcula o valor correspondente de y[n].
 */

#include <stdio.h>

float calc_x(int n){
    if(n<=0||n>=11){
        return 0;
    }else{
        return 1+calc_x(n-1);
    }
}

float calc_y(int n){
    if(n<=0){
        return 0;
    }else{
        return calc_x(n-2)-0.2*calc_y(n-2)+0.5*calc_y(n-3);
    }
}

int main(){
    float res;
    int n;

    printf("Digite o valor de amostras 'n': ");
    scanf("%i",&n);

    res=calc_y(n);
    printf("%f \n",res);

    return 0;
}
