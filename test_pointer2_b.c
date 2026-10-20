#include <stdio.h>
#include <stdlib.h>

/*
在上述代码中，allocate函数试图为p分配内存，但运行后会发现p仍然为NULL 。
因为 C 语言是值传递，allocate(p) 只把 p 的值（NULL）复制给了形参 ptr，ptr 在函数内被重新赋值，不影响 main 中的 p。
修改代码见test_pointer2_g.c
*/
void allocate(int *ptr) {
    ptr = (int *)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 42; // Assign a value to the allocated memory
    }
}

int main(void) {
    int *p = NULL;
    allocate(p);
    if (p == NULL) {
        printf("allocate fail.\n");
    } else {
        *p=10; // Assign a value to the allocated memory
        printf("*p的值: %d\n", *p);
        free(p); // Free the allocated memory
    }
    return 0;
}
