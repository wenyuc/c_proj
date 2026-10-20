#include <stdio.h>


void print_frame(const char *tag) {
    void *sp;
    void *rbp = __builtin_frame_address(0);
    __asm__ volatile ("mov %%rsp, %0" : "=r"(sp));
    printf("%s: rsp = %p\n", tag, sp);
    printf("%s: rbp = %p\n", tag, rbp);
    return;
}

void print_sp(const char *tag) {
    void *sp;
    __asm__ volatile ("mov %%rsp, %0" : "=r"(sp));
    printf("%s: rsp = %p\n", tag, sp);
    return;
}

void func(void) {
    int local[100];  // 占用 400 字节
    local[0] = 1;
    print_frame("func 内部");
    printf("func 内部: local[0] = %d\n", local[0]);
    return;
}

int main(void) {
    print_frame("main 开始");
    func();
    print_frame("func 返回后");
    return 0;
}
