/*
Desenvolva algoritmos recursivos para os seguinte problema:
a(m,n) = n+1, se m==0
a(m,n) = a(m-1,1), se m!=0 && n==0
a(m,n) = a(m-1,a(m,n-1)), se m!=0 && n!=0
*/
#include <stdio.h>

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0 && m != 0) {
        return ackermann(m - 1, 1);
    } else if (m != 0 && n != 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    } else {
        return 0;
    }
}

int main() {
    int m, n;
    printf("Enter values for m and n:\n");
    scanf("%d %d", &m, &n);
    printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
    return 0;
}