#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

void buildMatrix(unsigned int matrix_size) {
    char **square = calloc(matrix_size, sizeof(char *));
    if (square == NULL) {
        printf("Memory allocation error!");
        free(square); // Free memory allocated for square
        return;
    }
    for (unsigned int i = 0; i < matrix_size; ++i) {
        square[i] = calloc(matrix_size, sizeof(char));
        if (square[i] == NULL) {
            printf("Memory allocation error!");
            for (unsigned int j = 0; j < i; ++j) {
                free(square[j]);
            }
            free(square); // Free memory allocated for square
            return;
        }
    }
    system("cls");
    printf("\tMatrix\n");

    for (unsigned int i = 0; i < matrix_size; i++) {
        printf("\n");
        for (unsigned int j = 0; j < matrix_size; j++) {
            square[i][j] = i + j;
            printf("  %d  |", i + j);
        }
    }
    for (unsigned int i = 0; i < matrix_size; ++i) {
        free(square[i]);
    }
    free(square);
}

int main() {
    unsigned int matrix_size = 3;
    printf("Enter size of n x n matrix: ");
    scanf("%u", &matrix_size);
    if (matrix_size > MAX_LEN) {
        printf("Exceeded max length!");
        return 1;
    }
    buildMatrix(matrix_size);
    return 0;
}
