/*função recursiva mdc(x,y) que recebe dois valores inteiros e que devolve o maior divisor comum aos dois valores recebidos*/

#include <stdio.h>

int mdc(int x, int y){
    return 1;
}

int main(){
    int x,y,z;
    x=2;
    y=4;

    z=mdc(x,y);
    printf("z=%i\n",z);

    return 0;
}
/*
2 4 | 2
1 2 | 2
1 1 |
-------
2*2=4

1) n=2
do{
    z=x%n
    if(z==0){
        v=x/n
    }
}while(x+y==2)


3 5 | 3
1 5 | 5
1 5
-------
3*5=15

16 10 | 2
8  5  | 2
4  5  | 2
2  5  | 2
1  5  | 5
1  5  |
--------
2*2*2*2*5=80
 
*/