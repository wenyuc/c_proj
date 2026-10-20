#include <stdio.h>
#include <stdlib.h>

/*
本程序是用“指针的指针的指针”方式创建三维数组，它有两个致命缺点：
内存碎片：总共要调用 1 + L + L*R 次 malloc，堆上全是零散的小块。
缓存不命中：遍历时，每次跨行、跨层都会跳转到内存的不同位置，CPU 缓存命中率极低。

在 LLDB 中：
arr 本身是 1 次 malloc(L * 8)。
arr[i] 是 L 次 malloc(R * 8)。
arr[i][j] 是 L * R 次 malloc(C * 4)。
*/
int main(void) {
    int L = 2;  // 层数
    int R = 3;  // 行数
    int C = 4;  // 列数

    // 1. 分配最外层（指向二维数组的指针数组）
    int ***arr = (int ***)malloc(L * sizeof(int **));
    if (arr == NULL) return 1;

    for (int i = 0; i < L; i++) {
        // 2. 分配每一层（指向一维数组的指针数组）
        arr[i] = (int **)malloc(R * sizeof(int *));
        if (arr[i] == NULL) return 1;

        for (int j = 0; j < R; j++) {
            // 3. 分配每一行（真正的 int 数据）
            arr[i][j] = (int *)malloc(C * sizeof(int));
            if (arr[i][j] == NULL) return 1;
        }
    }

    // --- 赋值 ---
    int val = 1;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                arr[i][j][k] = val++;
            }
        }
    }

    // --- 打印 ---
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                printf("%3d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("---\n");
    }

    // --- 释放（必须和分配顺序相反） ---
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            free(arr[i][j]);  // 先释放每一行
        }
        free(arr[i]);         // 再释放每一层
    }
    free(arr);                // 最后释放最外层

    return 0;
}
