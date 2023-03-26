#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int main(int argc, char **argv) {
    /* Creating profiles of 3 students */
    student_t *student1, *student2, *student3;
    
    student1 = student_new("Abdul Rahman", 1001, 26);
    student2 = student_new("Zeeshan Rahman", 1002, 25);
    student3 = student_new("Wajahat Ali", 1003, 27);
    
    /* Printing profiles of 3 students */
    printf("Student 1:-");
    print_student(student1);
    printf("\nStudent 2:-");
    print_student(student2);
    printf("\nStudent 3:-");
    print_student(student3);
    
    /* Freeing memory space */
    delete_student(student1);
    delete_student(student2);
    delete_student(student3);
    
    return 0;
}
