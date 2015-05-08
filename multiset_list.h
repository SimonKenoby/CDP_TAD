#ifndef __MULTISET_LIST__
#define __MULTISET_LIST__

#include "boolean.h"
#include <stdlib.h>


typedef struct list_t list;
typedef struct list_t cell;

list *create_empty();

bool is_empty(list *L);

int count(list *L);

int occurrences(list *L, void *element, bool (*compare)(const void *, const void *));

bool part_of(list *L, void *element, bool (*compare)(const void *, const void *));

bool equals(list *L1, list *L2, bool (*compare)(const void *, const void *));

list *join(list *L1, list *L2);

list *add_to(list *L, void *element);

list remove_from(list *L, void *element, bool (*compare)(const void *, const void *));

#endif
