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
	return NULL;
}

bool is_empty(list *L)
{
	if(!L)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int count(list *L)
{
	if(is_empty(L))
	{
		return 0;
	}
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
	if(is_empty(L))
		return 0;
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
		current = current->next;
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

	list *joined_list = create_empty();
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
	return joined_list;
}

list *add_to(list *L, void *element)
{
	assert(element);
	cell *current = L;
	if(is_empty(L))
	{
		L = malloc(sizeof(cell));
		assert(L);
		L->next = NULL;
		L->data = element;
		return L;
	}
	else
	{
		while(current->next)
		{
			current = current->next;
		}
		current->next = malloc(sizeof(cell));
		assert(L->next);
		current = current->next;
		current->next = NULL;
		current->data = element;
		return L;
	}
}

list *remove_from(list *L, void *element, bool (*compare)(const void *, const void *))
{
	assert(element);
	cell *current = L->next, *tmp = L;
	if(is_empty(L))
		return L;
	else if(!tmp->next && compare(tmp->data, element))
		{
			free(tmp);
			return NULL;
		}
	else
	{
		while(current)
		{
			if(compare(current->data, element))
			{
				tmp->next = current->next;
				free(current);
			}
			tmp = tmp->next;
			current = tmp->next;
		}
		return L;
	}
}