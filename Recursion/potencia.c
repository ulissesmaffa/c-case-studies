/*
 * Cálculo de Potência Usando Função Recursiva
 * Este programa calcula x elevado à potência y utilizando uma função recursiva.
 * O usuário fornece os valores inteiros para a base x e o expoente y, e o programa retorna x^y.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A função potencia(int x, int y) é recursiva. Ela multiplica x por si mesmo y vezes.
 * - A condição de parada é quando y se torna 0, caso em que a função retorna 1, pois qualquer número elevado a 0 é 1.
 * - O programa demonstra o conceito de recursão reduzindo o valor de y em 1 a cada chamada recursiva.
 * - Resumo do Processo Recursivo:
 *   A função "potencia" chama a si mesma reduzindo gradualmente o valor de "y" até que ele atinja 0,
 *   momento em que a função retorna 1. Por exemplo, potencia(2,3) faz as seguintes chamadas:
 *   [1] potencia(2,3) = 2 * potencia(2,2), 
 *   [2] potencia(2,2) = 2 * potencia(2,1),
 *   [3] potencia(2,1) = 2 * potencia(2,0),
 *   [4] potencia(2,0) retorna 1.
 *   Assim, potencia(2,3) calcula 2 * 2 * 2 * 1 = 8.
 */

#include <stdio.h>

int potencia(int x, int y){
    if(y==0){//qualquer número quando elevado na zero, vai dar um, essa é a condição de parada
        return 1;
    }else{
        return x * potencia(x,y-1);//x multiplica 
    }
}

int main(){
    int x,y,z;

    printf("Digite um valor inteiro para x:");
    scanf("%i",&x);

    printf("Digite um valor inteiro para y:");
    scanf("%i",&y);

    z=potencia(x,y);
    printf("z=%i\n",z);

    return 0;
}