#include "multiset_list.h"
#include "seatest.h"

#include <assert.h>
#include <stdlib.h>

struct list_t
{
	void *data;
	struct list_t *next;
};


list *create_empty(void)
{
	list *L = malloc(sizeof(list));
	assert(L);
	L->next = NULL;
	return L;
}

bool is_empty(list *L)
{
	assert(L);
	if(L->data)
	{
		return FALSE;
	}
	else
		return TRUE;
}

int count(list *L)
{
	assert(L);
	cell *current = L;
	int element_count = 0;
	while(current)
	{
		++element_count;
		current = current->next;
	}
	return element_count;
}

int occurrences(list *L, void *element, bool (*compare(const void *, const void *)))
{
	assert(L);
	cell *current = L;
	int occurrences = 0;
	while(current)
	{
		if(compare(current->data, element))
			++occurrences;
		current = current->next;
	}
	return occurrences;
}

bool part_of(list *L, void *element, bool (*compare(const void *, const void *)))
{
	assert(L && element);
	cell *current = (cell *)L;
	while(current)
	{
		if(compare(current->data, element))
			return TRUE;
	}
	return FALSE;
}

bool equals(list *L1, list *L2, bool (*compare(const void *, const void *)))
{
	assert(L1 && L2);
	cell *current = (cell *)L1;
	if(count(L1) != count(L2))
	{
		return FALSE;
	}
	else
	{
		while(current)
		{
			if(occurrences(L1, current->data, compare) != occurrences(L2, current->data, compare))
				return FALSE;
			current = current->next;
		}
	}
	return TRUE;
}
