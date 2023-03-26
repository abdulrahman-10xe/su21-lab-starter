#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

struct student_t {
    char *name;
    int ID;
    int age;
};

student_t *student_new(char *name, int ID, int age) {
    student_t *std;
    std = malloc(sizeof(student_t));

    if(std == NULL)
    {
    	free(std);
    	exit(1);
    }
    std->name = name;
    std->ID = ID;
    std->age = age;
    return std;
}

void print_student(student_t *student) {
    printf("\nName: %s\n", student->name);
    printf("ID  : %d\n", student->ID);
    printf("Age : %d\n", student->age);
}

void delete_student(student_t *student) {
    free(student);
}
