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
   return !array->count;
}

int count(Array *array) {
   assert(array);
   return array->count;
}

int occurrences(void* element, Array *array, bool(*compare)    
   (const void *, const void *)) {
   assert(array);
   int occurrences = 0;
   for (int i = 0; i < array->count; i++)
      if (compare(element, array->elements[i]))
         occurrences++;
   return occurrences;
}

bool part_of(void* element, Array *array, bool(*compare)    
   (const void *, const void *)) {
   assert(array);
   for (int i = 0; i < array->count; i++)
      if (compare(element, array->elements[i]))
         return TRUE;
   return FALSE;
}

bool equals(Array *array1, Array *array2, bool(*compare)    
   (const void *, const void *)) {
   assert(array1 && array2);
   if (array1->count != array2->count)
      return FALSE;
   for (int i = 0; i < array1->count; i++)
      if (occurrences(array1->elements[i], array1, compare) !=    
         occurrences(array1->elements[i], array2, compare))
         return FALSE;
   return TRUE;
}

Array *join(Array *array1, Array *array2) {
   assert(array1 && array2);
   Array* r_array = create_empty();
   r_array->count = array1->count + array2->count;
   r_array->elements = malloc(sizeof(void*)*(r_array->count));
   assert(r_array->elements);
   for (int i = 0; i < array1->count; i++)
      r_array->elements[i] = array1->elements[i];
   for (int i = 0; i < array2->count; i++)
      r_array->elements[array1->count + i] = array2->elements[i];
   return r_array;
}

Array *add_to(void* element, Array *array) {
   assert(array);
   Array *r_array = create_empty();
   r_array->count = array->count + 1;
   r_array->elements = malloc(sizeof(void*)*(array->count + 1));
   assert(r_array->elements);
   for (int i = 0; i < array->count; i++)
      r_array->elements[i] = array->elements[i];
   r_array->elements[array->count] = element;
   if (array->count)
      free(array->elements);
   return r_array;
}

Array *remove_from(void* element, Array *array, bool(*compare)    
   (const void *, const void *)) {
   assert(array);
   if (!array->count)                                    //In case of empty array, the array is returned
      return array;
   Array *r_array = create_empty();
   if (occurrences(element, array, compare)) {                  //If the element is found, it is removed
      r_array->count = array->count - 1;
      r_array->elements = malloc(sizeof(void*)*(array->count - 1));
      bool removed = FALSE;
      for (int i = 0; i < r_array->count; i++){
         if (!compare(array->elements[i], element) || removed)
            r_array->elements[i] = array->elements[i];
         else
            removed = TRUE;
      }
   }
   else                                             //Else the original array is returned, unmodified
      return array;
   return r_array;
}