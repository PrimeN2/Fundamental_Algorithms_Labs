#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#define VECTOR_TYPE int
#include "custom_vector.h"

VECTOR_TYPE *copy_int(const VECTOR_TYPE *value);
void delete_int(VECTOR_TYPE *value);
int compare_int(const VECTOR_TYPE *v1, const VECTOR_TYPE *v2);

#endif

