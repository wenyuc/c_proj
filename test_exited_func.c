#include <stdio.h>

void safe_param(int *out) {
    *out = 0xDEADBEEF;
}
int main(void) {
    int value;
    
    safe_param(&value);
    printf("第一次读取: 0x%X\n", value);  // 可能还是 0xDEADBEEF
    
    return 0;
}
