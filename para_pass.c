#include <stdio.h>
#include <stdlib.h>

// pass by value
void swap (int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

//pass by address
void swap_by_address(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 返回多个值：通过指针输出
int divide(int a, int b, int *quotient, int *remainder) {
    if (b == 0) return -1;  // 错误
    *quotient = a / b;
    *remainder = a % b;
    return 0;  // 成功
}

//const int *arr: pass array by address, cannot modify the array elements,
//  but can change the pointer to point to another array.
/* void func(int *arr, int size)
   void func(int arr[], int size)
   void fund(int arr[10], int size), 10 to be ignored*/
void print_array(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("In print_array(): size of arr = %zu\n", sizeof(arr)); // will print the size of the pointer, not the array itself
}

/* my strlen func*/
size_t my_strlen(const char *str) {
    size_t len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

/* push_back: dynamically add an element to the end of an array, reallocating memory if necessary */
/* Parameters:
 *   arr: pointer to the array pointer
 *   size: pointer to the current size of the array
 *   capacity: pointer to the current capacity of the array
 *   value: the value to be added
 * Returns:
 *   0 on success, -1 on memory allocation failure
 */
int push_back(int **arr, int *size, int *capacity, int value) {
    if (*size >= *capacity) {
        int new_cap = (*capacity == 0) ? 4 : (*capacity) * 2;
        int *new_arr = realloc(*arr, new_cap * sizeof(int));
        if (new_arr == NULL) return -1;
        *arr = new_arr;
        *capacity = new_cap;
    }
    (*arr)[(*size)++] = value;
    return 0;
}
/* function pointer as a parameter */
void for_each(int *arr, int size, void (*callback)(int)) {
    for (int i = 0; i < size; i++) {
        callback(arr[i]);
    }
}

void print_int(int i){
    printf("%d\n", i);
}

/* allocate_right: dynamically allocate memory for an integer and assign it to the pointer passed by reference */
void allocate_right(int **p) {
    *p = malloc(sizeof(int));
}

// 二级指针修改指针
int allocate_array(int **arr, int size) {
    *arr = malloc(size * sizeof(int));
    if (*arr == NULL) return -1;
    for (int i = 0; i < size; i++) {
        (*arr)[i] = i * 10;
    }
    return 0;
}

int main(void)
{
    printf("Scenario 1. pass by value\n");
    int i=5,j=2;
    swap(i, j);
    printf("After swap(): i = %d at address %p; j = %d at address %p.\n", i, (void *)&i, j, (void *)&j);
    
    printf("Scenario 2. pass by address\n");
    swap_by_address(&i, &j);
    printf("After swap_by_address(): i = %d at address %p; j = %d at address %p.\n", i, (void *)&i, j, (void *)&j);
    
    printf("Scenario 3. change caller's variables\n"); 
    swap_by_address(&i,&j);
    int quotient, remainder;
    if (divide(i, j, &quotient, &remainder) == 0) {
        printf("After divide(): quotient = %d, remainder = %d.\n", quotient, remainder);
    } else {
        printf("Error: division by zero.\n");
    }

    printf("Scenario 4. pass array's first element address\n");
    int a [] = {1, 2, 3, 4, 5};
    size_t size = sizeof(a) / sizeof(a[0]);
    print_array(a, size);    //pass array name, i.e., the address of the first element

    printf("Scenario 5. pass string (character array)\n");
    const char *str = "Hello, world!";
    printf("Length of string \"%s\" is %zu.\n", str, my_strlen(str));

    printf("Scenario 6. Dynamic memory allocation for array.\n");
    int *d_array=NULL;
    int d_size=0, capacity=0;
    for(int i=0; i<10; i++) {
        push_back(&d_array, &d_size, &capacity, i*10);
    }
    free(d_array);
    d_array = NULL; // good practice to avoid dangling pointer

    printf("Scenario 7. function pointer as a parameter\n");
    int arr[] = {1, 2, 3, 4, 5};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    for_each(arr, arr_size, print_int);    // 传函数名（函数指针）

    printf("Scenario 8. Secondary pointer\n");
    int value = 42;
    int *ptr = &value;
    int **sec_ptr = &ptr;
    printf("Value through first pointer: %d\n", *ptr);
    printf("Value through secondary pointer: %d\n", **sec_ptr);

    int *p=NULL;
    allocate_right(&p);
    *p=43;
    printf("Value through allocated pointer: %d\n", *p);
    free(p);
    p = NULL; // good practice to avoid dangling pointer

    int *dyn_arr = NULL;
    allocate_array(&dyn_arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", dyn_arr[i]);
    }
    printf("\n");
    free(dyn_arr);
    dyn_arr=NULL;

    return 0;
}
