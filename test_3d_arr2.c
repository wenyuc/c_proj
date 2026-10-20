#include <stdio.h>
#include <stdlib.h>

/*
这是更优的连续内存分配优点：

真正的数据（data）在内存中是连续的，arr[0][0][0] 和 arr[1][2][3] 在物理内存上紧挨着。
只需要分配 1 + L 次 malloc（前一种方案需要 1 + L + L*R 次），大幅减少碎片。
CPU 缓存效率极高。
*/
int main(void) {
    int L = 2, R = 3, C = 4;

    // 1. 分配指针数组（用于索引访问 arr[i][j]）
    int ***arr = (int ***)malloc(L * sizeof(int **));
    if (arr == NULL) return 1;

    // 2. 分配一块真正存放数据的巨大连续内存
    int *data = (int *)malloc(L * R * C * sizeof(int));
    if (data == NULL) return 1;

    // 3. 分配每一层的指针数组，并让它们指向连续数据的对应位置
    for (int i = 0; i < L; i++) {
        arr[i] = (int **)malloc(R * sizeof(int *));
        if (arr[i] == NULL) return 1;
        for (int j = 0; j < R; j++) {
            // 指针算数：第 i 层，第 j 行的起始地址
            arr[i][j] = data + (i * R * C) + (j * C);
        }
    }

    // --- 赋值和访问 ---
    int val = 1;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                arr[i][j][k] = val++;
            }
        }
    }

    // 打印验证
    printf("arr[1][2][3] = %d\n", arr[1][2][3]); // 应该输出 24

    //int arr[2][3][4];
    //int (*p)[3][4] = arr;   // p 指向整个三维数组

    // 访问方式
    //(*p)[1][2][3] = 100;    // 等价于 arr[1][2][3] = 100
    // --- 释放 ---
    free(data);       // 释放大数据块
    for (int i = 0; i < L; i++) {
        free(arr[i]); // 释放每一层的指针数组
    }
    free(arr);        // 释放最外层

    return 0;
}
