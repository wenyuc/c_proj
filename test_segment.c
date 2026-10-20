#include <stdio.h>

/* .rodata: 字符串常量 */
const char *g_rodata_str = "Hello from .rodata!";

/* .data: 已初始化的全局/静态变量 */
int g_data_var = 42;
static int s_data_var = 100;

/* .bss: 未初始化或初始化为 0 的全局/静态变量 */
int g_bss_var;
static int s_bss_var = 0;

int sub_function(int a, int b) {
    const int ratio = 1;
    int local_var = (a + b) * ratio;
    return local_var;
}

int main(void) {
    printf("%s\n", g_rodata_str);

    int result = sub_function(g_data_var, s_data_var);

    g_bss_var = result;
    s_bss_var = result * 2;
    
    return 0;
}
