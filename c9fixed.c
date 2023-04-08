// Use C-Lang Static Analyzer to analyze and fix the bugs
// Hint this code has bugs that can be identified using static analyzer
// Also review the output generated to find any bugs/vulnerabilities that the static analyzer misses.

#include <stdio.h>
#include <stdlib.h>

// custom function for printing an array
void array_print(int* ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Array is: %d\n", ptr[i]);
    }
}

int main()
{
    // variable initializations 
    int* ptr_to_arr;
    int size_array = 10;

    // allocate memory for array
    ptr_to_arr = (int*)malloc(size_array * sizeof(int));

    // check if memory allocation was successful
    if (ptr_to_arr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // initialize array
    for (int i = 0; i < size_array; i++) {
        ptr_to_arr[i] = i;
    }

    // function call statement
    array_print(ptr_to_arr, size_array);

    // free allocated memory
    free(ptr_to_arr);

    return 0;
}
