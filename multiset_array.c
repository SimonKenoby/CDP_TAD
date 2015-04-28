#include "multiset_array.h"

struct Array{
	void** elements;
	unsigned int count;
};

Array *create_empty(void) {
	Array *array = malloc(sizeof(Array));
	if (!array)
		return NULL;
	array->count = 0;
	return array;
}

bool is_empty(Array *array) {
	if (!array || !array->count)
		return TRUE;
	return FALSE;
}