#ifndef __MULTISET_ARRAY__
#define __MULTISET_ARRAY__

#include "boolean.h"
#include <stdlib.h>

typedef struct Array Array;

Array *create_empty(void);

bool is_empty(Array *array);

#endif