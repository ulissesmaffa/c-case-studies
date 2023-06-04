/*potencia (x,y) que devolva o x elevado a potencia y*/
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
/*
A função "potencia" é recursiva, ou seja, ela chama a si mesma dentro de sua própria definição, 
reduzindo gradualmente o valor de "y" até que ele atinja 0, 
momento em que a função retorna 1 (pois qualquer número elevado a 0 é igual a 1).

Por exemplo, se o usuário digitar "2" para "x" e "3" para "y", 
[1] o programa chama a função "potencia(2,3)", 
[2] que por sua vez chama "potencia(2,2)", "potencia(2,1)",
[3] "potencia(2,0)", 
[4] e finalmente retorna 1. 

[1] Então, a função "potencia(2,1)" retorna 2 * potencia(2,0) = 2 * 1 = 2,  ---começa pela condição de parada, resultado é 1, então 2*1=2
[2] a função "potencia(2,2)" retorna 2 * potencia(2,1) = 2 * 2 = 4, 
[3] e a função "potencia(2,3)" retorna 2 * potencia(2,2) = 2 * 4 = 8.
[4] O resultado final é impresso na tela como "z=8".
*/