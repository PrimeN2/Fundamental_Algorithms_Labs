#ifndef STUDENT_H
#define STUDENT_H

#include <vector.h>

typedef struct {
    unsigned int id;
    char *name;
    char *surname;
    char *group;
    vector marks;
} Student;

#endif