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
	if(!L)
	{
		return FALSE;
	}
	else
		return TRUE;
}

int count(list *L)
{
	cell *current = L;
	int element_count = 0;
	while(current)
	{
		++element_count;
		current = current->next;
	}
	return element_count;
}

int occurrences(list *L, void *element, bool (*compare)(const void *, const void *))
{
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

bool part_of(list *L, void *element, bool (*compare)(const void *, const void *))
{
	assert(element);
	if(is_empty(L))
		return FALSE;
	cell *current = L;
	while(current)
	{
		if(compare(current->data, element))
			return TRUE;
	}
	return FALSE;
}

bool equals(list *L1, list *L2, bool (*compare)(const void *, const void *))
{
	cell *current = L1;
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

list *join(list *L1, list *L2)
{
	if(is_empty(L1))
		return L2;
	else if(is_empty(L2))
		return L1;

	list *joined_list = malloc(sizeof(list));
	assert(joined_list);
	cell *current = L1;
	while(current)
	{
		joined_list = add_to(joined_list, current->data);
		current = current->next;
	}
	current = L2;
	while(current)
	{
		joined_list = add_to(joined_list, current->data);
		current = current->next;
	}
}

list *add_to(list *L, void *element)
{
	assert(element);
	if(is_empty(L))
		L = create_empty();
	L->next = malloc(sizeof(cell));
	assert(L->next);
	cell *current = L->next;
	current->next = NULL;
	current->data = element;
	return L;
}

list remove_from(list *L, void *element, bool (*compare)(const void *, const void *))
{
	assert(element);
	cell *current = L, tmp = NULL;
	if(is_empty(L))
		return L;
	else
	{
		while(current)
		{
			if(compare(current->data, element))
			{
				tmp->next = current->next;
				free(current);
			}
			tmp = current;
			current = current->next;
		}
	}
	return L;
}