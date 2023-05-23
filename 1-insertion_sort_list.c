#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_point, *compar_node;

	if (!(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		insert_point = current->prev;
		compar_node = current;

		while (insert_point != NULL && compar_node->n < insert_point->n)
		{
			if (insert_point->prev != NULL)
				insert_point->prev->next = compar_node;
			else
				*list = compar_node;

			compar_node->next = insert_point;
			insert_point->prev = compar_node;

			insert_point->next = compar_node->next;
			if (compar_node->next != NULL)
				compar_node->next->prev = insert_point;

			compar_node->prev = insert_point->prev;

			insert_point = insert_point->prev;
			
		}

		current = current->next;
	}
	print_list(*list);
}
