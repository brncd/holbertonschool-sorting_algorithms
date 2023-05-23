#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	if (!(*list) || !((*list)->next))
		return;

	listint_t *current;
	
	current = (*list)->next;

	while (current)
	{
		listint_t *insert_point = current->prev;
		listint_t *compar_node = current;

		while ((insert_point) && 
				(compar_node->n < insert_point->n))
		{
			if (insert_point->prev)
				insert_point->prev->next = compar_node;
			else
				*list = compar_node;

			compar_node->next = insert_point;
			insert_point->prev = compar_node;

			insert_point->next = compar_node->next;
			if (compar_node->next)
				compar_node->next->prev = insert_point;

			compar_node->prev = insert_point->prev;

			insert_point = insert_point->prev;
		}

		current = current->next;
	}
}
