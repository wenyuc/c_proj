#include <stdio.h>

/* 存储有四种类型：
auto: 自动变量，由编译器自动回收变量所占的内存。
static: 静态变量，在程序运行期间只初始化一次，不随作用域的结束而销毁。生命周期从创建开始到程序运行结束。
        如果静态变量没有初始化，编译器初始化，当不要依赖编译器设置默认值。
extern: 外部变量，定义在函数外部，可以在多个文件中共享。
register: 寄存器变量，尽量存储在CPU寄存器中，以提高访问速度。当不能对寄存器取地址。
*/

void foo(void) {
    static int cnt = 0;
    cnt++;
    printf("count=%d\n",cnt);
    return;
}
int main(void)
{
    foo();
    foo();
    foo();
    int i=0;
    //register int i=0;   //compilation error, cannot take the address of a register variable
    scanf("%d", &i);
    printf("You entered: %d\n", i);
    return 0;
}
