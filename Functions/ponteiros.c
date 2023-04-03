#include<stdio.h>

int f1(int *n){
    int x;
    printf("n=%i\n",(*n));
    (*n)=10;
    x=5;
    printf("n=%i\n",(*n));

    return x;
}

int main(){
    int num,v;
    printf("Digite um valor:");
    scanf("%i",&num);
    v=f1(&num);
    printf("%i %i\n",num,v);

    return 0;
}