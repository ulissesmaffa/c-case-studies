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
    // scanf("%i",&x);
    x=2;

    printf("Digite um valor inteiro para y:");
    // scanf("%i",&y);
    y=4;

    z=potencia(x,y);
    printf("z=%i\n",z);

    return 0;
}