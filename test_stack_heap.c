#include <stdio.h>
#include <stdlib.h>

void stack_demo(void) {
    int stack_var = 100;
    printf("栈变量 stack_var 地址: %p 值: %d\n", (void*)&stack_var, stack_var);
}

void heap_demo(void) {
    int *heap_var = malloc(sizeof(int));
    *heap_var = 200;
    printf("堆变量 heap_var 地址: %p\n", (void*)heap_var);
    free(heap_var);  // 主动释放
    //printf("free 后 heap_var 地址: %p 值: %d(值仍可读，但已失效)\n", (void*)heap_var, *heap_var);
}

int main(void) {
    printf("=== 栈变量 ===\n");
    stack_demo();
    stack_demo();  // 两次调用地址相同
    stack_demo();
    
    printf("\n=== 堆变量 ===\n");
    heap_demo();
    printf("hello world\n");
    heap_demo();  // 两次调用地址可能不同
    heap_demo();
    
    return 0;
}
