#include "wrapped_malloc.h"
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

void* shelf[MAX_ALLOC];
unsigned numAlloc = 0;

void* w_malloc(int numBytes){
    void* ptr = malloc(numBytes);
    if (ptr == NULL) {
        printf("Error: malloc failed to allocate memory\n");
        return NULL;
    }
    if (numAlloc < MAX_ALLOC) {
        shelf[numAlloc++] = ptr;
    } else {
        printf("Error: MAX_ALLOC exceeded\n");
        return NULL;
    }
    return ptr;
}

void w_free(void* ptr){
    for (unsigned i = 0; i < numAlloc; i++) {
        if (shelf[i] == ptr) {
            free(ptr);
            shelf[i] = shelf[--numAlloc];
            return;
        }
    }
    printf("Error: w_free failed to free pointer\n");
}

void whole_free(){
    for (unsigned i = 0; i < numAlloc; i++) {
        free(shelf[i]);
    }
    numAlloc = 0;
}
