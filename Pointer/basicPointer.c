#include <stdio.h>
#include <stdbool.h>

void teste(bool *p){//func receve ponteiro como parametro
    *p=false;//func atualiza valor da variável
    printf("teste %d\n",*p);
}

int main(){
    bool a = true;//declaração de variável
    bool *pt_a=&a;//declaração de um ponteiro
    // pt_a=&a;//o ponteiro recebe o endereço da váriável
    
    printf("a: %d\n",a);//imprimi variável
    teste(pt_a);//envia endereço para func para atualizar valor da variável
    printf("a: %d\n",a);//imprimi variável
}