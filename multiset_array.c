#include "multiset_array.h"
#include "assert.h"

struct Array{
	void** elements;
	int count;
};

Array *create_empty(void) {
	Array *array = malloc(sizeof(Array));
	assert(array);
	array->count = 0;
	return array;
}

bool is_empty(Array *array) {
	assert(array);
	if (array->count)
		return FALSE;
	return TRUE;
}

int count(Array *array) {
	assert(array);
	return array->count;
}

int occurrences(void* element, Array *array) {
	assert(array);
	int occurrences = 0;
	for (int i = 0; i < array->count; i++)
		if (array->elements[i] == element)
			occurrences++;
	return occurrences;
}

bool part_of(void* element, Array *array) {
	assert(array);
	for (int i = 0; i < array->count; i++)
		if (array->elements[i] == element)
			return TRUE;
	return FALSE;
}

bool equals(Array *array1, Array *array2) {
	assert(array1 && array2);
	if (array1->count != array2->count)
		return FALSE;
	for (int i = 0; i < array1->count; i++)
		if (array1->elements[i] != array2->elements[i])
			return FALSE;
	return TRUE;
}

Array *join(Array *array1, Array *array2) {
	assert(array1 && array2);
	for (int i = 0; i < array2->count; i++)
		array1 = add_to(array2->elements[i], array1);
	return array1;
}

Array *add_to(void* element, Array *array) {
	assert(array);
	Array *r_array = create_empty();
	r_array->count = array->count + 1;
	r_array->elements = malloc(sizeof(void*)*(array->count + 1));
	for (int i = 0; i < array->count; i++)
		r_array->elements[i] = array->elements[i];
	r_array->elements[array->count] = element;
	if (array->count)
		free(array->elements);
	return r_array;
}

Array *remove_from(void* element, Array *array) {
	assert(array && array->count);
	Array *r_array = create_empty();
	r_array->count = array->count - 1;
	if (r_array->count)
		r_array->elements = malloc(sizeof(void*)*(array->count - 1));
	if (occurrences(element, array)) {
		bool removed = FALSE;
		for (int i = 0; i < r_array->count; i++){
			if (array->elements[i] != element || removed)
				r_array->elements[i] = array->elements[i];
			else
				removed = TRUE;
		}
	}
	return r_array;
}