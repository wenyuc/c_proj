#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int row=3, col=4;

    // Allocate memory for a 2D array
    int **arr = (int **)malloc(row * sizeof(int *));
    //printf("arr=%p\n", (void*)arr);
    for (int i = 0; i < row; i++) { 
        arr[i] = (int *)malloc(col * sizeof(int));
        //printf("arr[%d]=%p\n", i, (void*)arr[i]);
    }

    // Initialize the 2D array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = i * col + j; // Fill with some values
        }
    }

    // Print the 2D array
    printf("2D Array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);   
        }
        printf("\n");
    }

    //free the allocated memory
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;

}
