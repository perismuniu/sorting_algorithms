#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail Shaker Sort.
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	 if (list == NULL || *list == NULL || (*list)->next == NULL)
		  return;

	 do
	 {
		 swapped = 0;
		 current = *list;

		 while (current->next != NULL)
		 {
			 if (current->n > current->next->n)
			 {
				 swap_nodes(current, &(current->next), list);
				 swapped = 1;
			 }
			 else
			 {
				 current = current->next;
			 }
		 }
		 if (swapped)
			 print_list(*list);
		 if (!swapped)
			 break;
		 swapped = 0;
		 current = current->prev;

		  while (current->prev != NULL)
		  {
			  if (current->n < current->prev->n)
			  {
				  swap_nodes(current->prev, &current, list);
				  swapped = 1;
			  }
			  else
			  {
				   current = current->prev;
			  }
		  }
		  if (swapped)
			   print_list(*list);
	 }
	 while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @left: Pointer to the left node.
 * @right: Pointer to the right node.
 * @list: Pointer to the head of the list.
 */
void swap_nodes(listint_t *left, listint_t **right, listint_t **list)
{
	 if (left->prev)
		 left->prev->next = *right;
	 else
		 *list = *right;
	 if ((*right)->next)
		 (*right)->next->prev = left;

	 left->next = (*right)->next;
	 (*right)->prev = left;
	 (*right)->next = left;
	 left->prev = *right;
}
