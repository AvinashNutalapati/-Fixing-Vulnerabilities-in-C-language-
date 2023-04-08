#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int *px = NULL;
    float foo;

    if (px == NULL) {
        px = malloc(sizeof(int));
        if (px == NULL) {
            printf("Error: Failed to allocate memory\n");
            return 1;
        }
    }

    foo = 3.5;
    *px = argc - 1;
    if (*px == 1) {
        printf("%6.1f", foo);
    } else {
        printf("%6.1f", 100.00 / *px);
    }

    free(px); // Free the allocated memory

    return 0;
}
