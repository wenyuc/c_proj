#include <stdio.h>

/* Read and print the contents of a file in the current folder. */
int main(void)
{
    const char *filename = "example.txt";
    FILE *file = fopen(filename, "r");
    int ch;

    if (file == NULL) {
        perror(filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}
