#include <stdio.h>

/*
执行结果：
$./test_pointer
a = 10   &a=0x7ffdcc36b914
p = 0x7ffdcc36b914       &p=0x7ffdcc36b918       *p=10
pp = 0x7ffdcc36b918      &pp=0x7ffdcc36b920      *pp=0x7ffdcc36b914      **pp=10

null_point=(nil)
null_point==NULL? 1

地址                值               size
0x7ffdcc36b914     0xa              4 bytes
0x7ffdcc36b918     0x7ffdcc36b914   8 bytes
0x7ffdcc36b920     0x7ffdcc36b918   8 bytes

解释：
pp points to p, which points to a. The value of a can be accessed through pp by dereferencing it twice (**pp).
pp是一个变量，pp中存放p的地址，p中存放a的地址，
pp第一次解引用(*pp) 得到p的值（即a的地址），pp第二次解引用(**pp)得到a的值。
*/
int main(void) {
    int a = 10;
    int *p = &a;  // 指针 p 指向变量 a 的地址
    int **pp = &p; // 指针 pp 指向指针 p 的地址
    int arr[10];

    printf("a = %d\t &a=%p\n", a, (void*)&a);
    printf("p = %p\t &p=%p\t *p=%d\n", (void*)p, (void*)&p, *p);
    printf("pp = %p\t &pp=%p\t *pp=%p\t **pp=%d\n", (void*)pp, (void*)&pp, (void*)*pp, **pp);

    //int *null_p; //未初始化，值是垃圾，不能解引用。
    int *null_p=NULL; // 指针 null_p 被初始化为 NULL，表示它不指向任何有效的内存地址。但已经初始化了。不能解引用。
    printf("null_p = %p\n", (void*)null_p);
    printf("null_p==NULL? %d\n", null_p==NULL);

    //步长
    p=arr;  //p指向arr[0]
    pp=&p;  //pp指向p

    printf("p + 1  = %p (跳 %ld 字节)\n", (void *)(p+1), (long)((char*)(p+1) - (char*)p));
    printf("pp + 1 = %p (跳 %ld 字节)\n", (void *)(pp+1), (long)((char*)(pp+1) - (char*)pp));

    return 0;
}
