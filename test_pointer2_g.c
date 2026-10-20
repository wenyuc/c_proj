#include <stdio.h>
#include <stdlib.h>

/*
在上述代码中，allocate函数试图为p分配内存，但运行后会发现p仍然为NULL 。
这是因为allocate函数中的ptr是p的副本，对ptr的修改（如ptr = (int *)malloc(sizeof(int));）只改变了副本的指向，
而外部的p并没有改变。
修改代码见test_pointer2_g.c
*/
void allocate(int **ptr) {
    *ptr = (int *)malloc(sizeof(int));  //执行后，main栈帧中p的值被修改了，指向了新分配的内存。p=0x5555.... *ptr就是main中的p，所以修改*ptr等价于修改p.
                                        //执行后，新创建了堆中的空间，p正确指向堆内存。
    if (*ptr != NULL) {
        **ptr = 42; // Assign a value to the allocated memory
    }
}

int allocate2(void **ptr, size_t size) {
    *ptr = malloc(size);
    return (*ptr != NULL) ? 0 : -1; // Return 0 on success, -1 on failure
}

/*
想修改 int          → 传 int *
想修改 int *        → 传 int **
想修改 int **       → 传 int ***

p 是 int *，想修改 p 的值（即让 p 指向新的内存），需要传入 int **，即 &p.
*/
int main(void) {
    int *p = NULL;
    printf("Before allocate, p = %p\n", (void*)p);
    if (allocate2((void **)&p, sizeof(int)) !=0) { //调用它时main栈帧中p=NULL;allocate栈帧中ptr=&p,ptr是指向p的指针
        printf("allocate fail.\n");
    }
    printf("After allocate, p = %p\n", (void*)p);
    if (p == NULL) {
        printf("allocate fail.\n");
    } else {
        *p=10; // Assign a value to the allocated memory
        printf("*p的值: %d\n", *p);
        free(p); // Free the allocated memory
    }
    return 0;
}
