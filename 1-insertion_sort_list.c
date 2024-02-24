#include "sort.h"
void move_left(listint_t *curr, listint_t *insertion, listint_t **head);
/**
 * insertion_sort_list - sort a doubly linked list of integer
 * in ascending order
 * @list: pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *insertion = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	insertion = curr->prev;
	while (curr != NULL)
	{
		insertion = curr->prev;
		while (insertion != NULL && insertion->n > curr->n)
		{
			move_left(curr, insertion, list);
			insertion = curr->prev;
		}
		curr = curr->next;
	}
}
/**
* move_left - swaps two members of a list
*
* @curr: current node to be moved at left of insertion
* @insertion: insertion pointer
* @head: head of list
*/
void move_left(listint_t *curr, listint_t *insertion, listint_t **head)
{
	listint_t *swap1 = curr->next;
	listint_t *swap2 = insertion->prev;

	if (swap1 != NULL)
		swap1->prev = insertion;
	if (swap2 != NULL)
		swap2->next = curr;
	curr->prev = swap2;
	insertion->next = swap1;
	curr->next = insertion;
	insertion->prev = curr;
	if (*head == insertion)
		*head = curr;
	print_list(*head);
}

