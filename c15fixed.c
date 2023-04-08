#include <stdio.h>
#include <stdlib.h>

int size = 5;

void recurse() {
    void (*foo)(void) = recurse; // initialize the function pointer with the address of the current function
    if (size-- > 0) { // add a valid recursive check mechanism to avoid infinite recursion
        foo();
    }
}

int main() {
    recurse();
    return 0;
}
