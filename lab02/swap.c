#include <stdio.h>

void swap(int *x, int *y);

int main(void) {
    int a = 5;
    int b = 7;

    printf("Before Swap:-\na = %i,\tb = %i\n", a, b);

    swap(&a, &b);

    printf("After Swap:-\na = %i,\tb = %i\n", a, b);
}

void swap(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}
