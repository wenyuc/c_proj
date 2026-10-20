#include <stdio.h> 

long get_unit_price(void) {
    return 6;
}

long calc_area(long width, long length) {
    return width * length;
}

long calc_price(long width, long length) {
    long area_size = calc_area(width, length);
    long unit_price = get_unit_price();
    long total_price = area_size * unit_price;
    return total_price;
}

int main(int argc, char *argv[]) {
    long width = 4;
    long length = 5;
    long total_price = calc_price(width, length);
    if (argc>1) {printf("%s\n", *argv);}
    return total_price;
}

/*
函数运行时栈
$lldb test_stack
(lldb) b main
(lldb) target stop-hook add
Enter your stop hook command(s).  Type 'DONE' to end.
> di -p 
> re r rip rsp rbp rdi rsi rdx rcx r8 r9 rax 
> DONE
Stop hook #2 added.
(lldb) run hello world
(lldb) si
(lldb) quit
Y
$

|偏移量|地址|内容|备注|
|---|---|---|---|

|rdi| |0x1||
|rsi|0xe0a8|0x00007fffffffe347|me read -fs 0x00007fffffffe347 "/home/wenyuc/work/c_proj/test_stack"
|+32|0xdfa0|0x0000000155554040|
|+24|0xdf98|0x00007fffffffe0a8|
|+16|0xdf90|0x00007fffffffdfd0|
|+8|0xdf88|0x00007ffff7c2a1ca|
|0|0xdf80|0x00007fffffffe020|main 函数基地址|
|-8|0xdf78|0x00007fffffffe0a8|main 函数的栈帧指针|
|-16|0xdf70|0x4



#read the content of rbp(0x00007fffffffdf80)
(lldb) me read -fx -s8 -c1 0x00007fffffffdf80
(lldb) me read -fs 0xxxxx
*/
