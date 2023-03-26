#ifndef STRUCT_H_
#define STRUCT_H_

#include <sys/types.h>

typedef struct student_t student_t;

student_t *student_new(char *name, int ID, int age);
void print_student(student_t *student);
void delete_student(student_t *student);

#endif
