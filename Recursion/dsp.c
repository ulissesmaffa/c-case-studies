/*
Eq de diferenças:
y[n]+0,2y[n-1]-0,5y[n-2]=x[n-1]
y[n]=x[n-1]-0,2y[n-1]+0,5y[n-2]

x[n]={1,2,3,4,5,6,7,8,9,10}
x=n(u[n]-u[n-11])

condições inicias são zero
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
