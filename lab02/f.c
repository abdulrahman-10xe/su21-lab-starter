#include <stdio.h>

void main(void) {
    int *ptr;
    *ptr = 5;
    printf("Addr of ptr: %ix\nValue of ptr: %i\n", (int *) ptr, *ptr);
}
