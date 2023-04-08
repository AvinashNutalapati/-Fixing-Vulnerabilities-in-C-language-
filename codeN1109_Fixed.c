#include <stdio.h>
#include <stdlib.h>

void array_print(int* ptr3, int n) {
    for(int i = 0; i < n; i++) {
        printf("Array is: %d\n", ptr3[i]);
    }
}

int main() {
    int* ptr_to_arr;
    int size_array = 10;

    // allocate memory for 10 integers
    ptr_to_arr = (int*)malloc(size_array * sizeof(int));

    // initialize array with values from 0 to 9
    for (int i = 0; i < size_array; i++) {
        ptr_to_arr[i] = i;
    }

    //function call statements
    array_print(ptr_to_arr, size_array);

    // free dynamically allocated memory
    free(ptr_to_arr);

    return 0;
}
