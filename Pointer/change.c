#include <stdio.h>

void change(int *a, int *b){
    printf("recebi a=%i e b=%i\n",*a,*b);
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

int main(){
    int a=1,b=2; 
    change(&a,&b);
    printf("depois da troca a=%i e b=%i\n",a,b);
    return 0;
}

/* 
PONTEIROS SÓ ARMAZENAM ENDEREÇO DE MEMÓRIA
É PRECISO ASSOCIAR UM PONTEIRO A UM ENDEREÇO DE MEMÓRIA
*/