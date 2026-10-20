#include <stdio.h>

void func_a(void) {
    int local_a = 0xAAAAAAAA;
    int arr_a[4] = {0x11111111, 0x22222222, 0x33333333, 0x44444444};
    
    printf("=== func_a 内部 ===\n");
    printf("local_a 地址: %p, 值: 0x%X\n", (void*)&local_a, local_a);
    printf("arr_a 地址  : %p\n", (void*)arr_a);
    for (int i = 0; i < 4; i++) {
        printf("  arr_a[%d] 地址: %p, 值: 0x%X\n", i, (void*)&arr_a[i], arr_a[i]);
    }
}

void func_b(void) {
    // 故意定义相同数量的局部变量，占用相同栈空间
    int local_b = 0xBBBBBBBB;
    int arr_b[4] = {0x55555555, 0x66666666, 0x77777777, 0x88888888};
    
    printf("\n=== func_b 内部 ===\n");
    printf("local_b 地址: %p, 值: 0x%X\n", (void*)&local_b, local_b);
    printf("arr_b 地址  : %p\n", (void*)arr_b);
    for (int i = 0; i < 4; i++) {
        printf("  arr_b[%d] 地址: %p, 值: 0x%X\n", i, (void*)&arr_b[i], arr_b[i]);
    }
}

int main(void) {
    func_a();
    func_b();  // 调用 func_b，它可能复用 func_a 的栈空间
    return 0;
}
