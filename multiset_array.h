#ifndef __MULTISET_ARRAY__
#define __MULTISET_ARRAY__

#include "boolean.h"
#include <stdlib.h>

typedef struct Array Array;

Array *create_empty(void);

bool is_empty(Array *array);

int count(Array *array);

int occurrences(void* element, Array *array, bool (*compare) (const void *, const void *));

bool part_of(void* element, Array *array, bool(*compare) (const void *, const void *));

bool equals(Array *array1, Array *array2, bool(*compare) (const void *, const void *));

Array *join(Array *array1, Array *array2);

Array *add_to(void* element, Array *array);

Array *remove_from(void* element, Array *array, bool(*compare) (const void *, const void *));

#endif