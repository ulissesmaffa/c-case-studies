#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=5, *p;
    p = &i;
    printf("%d ,%d, %d\n", **&p, (3**p),(**&p+4));
    return 0;
}