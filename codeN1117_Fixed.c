/* This example asks the user for a height and width of an m X n game board with a maximum dimension of 100 squares.*/

#define MAX_DIM 100
#include <stdio.h>
#include <stdlib.h>

struct board_square_t {
   int height;
   int width;
};

int main(){
    /* board dimensions.*/
    int m, n, error;
    struct board_square_t *board;

    printf("Please specify the board height: \n");
    error = scanf("%d", &m);
    if (error == EOF){
        printf("No integer passed: Die evil hacker!\n");
        return 1;
    }

    printf("Please specify the board width: \n");
    error = scanf("%d", &n);
    if (error == EOF){
        printf("No integer passed: Die evil hacker!\n");
        return 1;
    }

    if (m > MAX_DIM || n > MAX_DIM) {
        printf("Value too large: Die evil hacker!\n");
        return 1;
    }

    board = (struct board_square_t*) malloc(m * n * sizeof(struct board_square_t));
    if (board == NULL) {
        printf("Memory allocation error: Die evil hacker!\n");
        return 1;
    }

    /* Initialize the board to 0 */
    for (int i = 0; i < m * n; i++) {
        board[i].height = 0;
        board[i].width = 0;
    }

    /* Use the board */
    // ...

    free(board); // Release memory
    return 0;
}
