#include <stdio.h>
#define SIZE 7

int odd_one(int *array) {
    int odd = 0;
    for(int i = 0; i < SIZE; ++i) {
    	odd = odd ^ array[i];
    }
    return odd;
}

int main(int argc, int **argv) {
    int array[SIZE] = {12,12,14,90,14,14,14};
    int odd = odd_one(array);
    printf("Odd number is %i.\n",odd);
    return 0;
}
