#include <stdio.h>

int main(void) {
    // 在 for 循环内声明变量是 C99 的特性
    for (int i = 0; i < 1; i++) {
        printf("Hello, ANSI C99! %d\n", i);
    }

    // 测试size_t数据类型
    size_t size = 10;
    printf("Size is %zu\n", size);
    
    return 0;
}
