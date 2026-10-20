#include <stdio.h>

int add(int a, int b) {
    int res=a+b;
    return res;
}

int main(void) {
    int i=5,j=7;
    int sum = add(i, j);
    printf("sum = %d\n", sum);
    return 0;
}
