#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the Insertion Sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* Détacher current */
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			/* Repositionner current */
			current->next = current->prev;
			current->prev = current->prev->prev;

			/* Raccorder les voisins */
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			current->next->prev = current;

			/* Affichage demandé par Holberton */
			print_list((const listint_t *)*list);
		}

		current = next_node;
	}
}
