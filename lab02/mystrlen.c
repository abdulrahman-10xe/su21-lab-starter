#include <stdio.h>

int mystrlen(char *str);

int main(void) {
    char *Str = "Abdul Rahman Quraishi";
    printf("My string is:-\n%s\n",Str);
    int len = mystrlen(Str);
    printf("String Length is: %i\n", len);
    return 0;
}

int mystrlen(char *str) {
    int count = 0;
    while(*str++ != '\0') {
	count++;
    }
    return count;
}
