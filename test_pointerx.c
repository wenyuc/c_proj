#include <stdio.h>
#include <stdlib.h>

void func(int **p) {
  int *q = (int *)malloc(sizeof(int));
  *q = 20;
  *p = q;
}

int main() {
  int *ptr = NULL;
  func(&ptr);
  if (ptr != NULL) {
    printf("*ptr的值: %d\n", *ptr);
    free(ptr);
  }
  return 0;
}
