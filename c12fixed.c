#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int *px = NULL; // Initialize to NULL
    float foo;

    if (px == NULL) { // Check if px is NULL before dereferencing it
        px = malloc(sizeof(int)); // Allocate memory for px
        if (px == NULL) { // Check if allocation succeeded
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
        free(px);
    }
    return 0;
}
