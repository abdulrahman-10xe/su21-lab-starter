#include <stdio.h>
#include <assert.h>

#define A 10
#define B 9

static_assert(A == 10, "A is NOT equal to 10. Static Assertion Failed.");
static_assert(B > 10, "B is NOT greater than 10. Static Assertion Failed.");

int main(int argc, int **argv) {
    printf("Static Assertions Passed.\n");
    return 0;
}
