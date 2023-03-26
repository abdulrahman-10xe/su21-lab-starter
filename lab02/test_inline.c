#include <stdio.h>

inline static int add(int a, int b) {
    return (a+b);
}

int main(int argc, char **argv) {
    int a = 5, b = 7;
    printf("Sum of %d and %d is %d.\n", a, b, add(a,b));
    return 0;
}
