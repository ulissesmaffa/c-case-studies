#include <stdio.h>
#include <stdbool.h>

void teste(bool *p){
    *p=false;
    printf("teste %d\n",*p);
}

int main(){
    bool a = true;
    bool *pt_a;
    pt_a=&a;
    
    printf("a: %d\n",a);
    teste(pt_a);
}