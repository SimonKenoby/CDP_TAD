#include "multiset.h"
#include "seatest.h"

#include <assert.h>
#include <stdlib.h>

struct list
{
	void *data;
	struct list_t *next;
};

typedef struct list_t cell

list *create_empty()
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
		return FALSE;
	else
		return TRUE;
}

int count(list *L)
{
	assert(L);
	cell *current = L;
	int count = 0;
	while(current)
	{
		++count;
		current = current->next;
	}
	return count;
}

int occurrences(list *L, void *element, bool (*compare(const void *, const void *)))
{
	assert(L);
	cell current = L;
	int occurrences = 0;
	while(current)
	{
		if(compare(current->data, element))
			++occurrences;
		current = current->next;
	}
	return count;
}

bool part_of(list *L, void *element, bool (*compare(const void *, const void *)))
{
	assert(L && element);
	cell *current = L;
	while(current)
	{
		if(compare->data, element)
			return TRUE;
	}
	return FALSE;
}

