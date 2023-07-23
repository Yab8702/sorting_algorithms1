#include "sort.h"

void swap_node_fun(listint_t **, listint_t **, listint_t *);
/**
 * insertion_sort_list - sort a  list of integers in ascending order
 * @list: doubly linked list
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *next_p, *prev_p, *tmp;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	next_p = (*list)->next;
	while (next_p != NULL)
	{
		tmp = next_p->next;
		prev_p = next_p->prev;
		while (prev_p != NULL && next_p->n < prev_p->n)
		{
			swap_node_fun(list, &prev_p, next_p);
			print_list(*list);
		}
		next_p = tmp;

	}
}

/**
 * swap_node_fun - swap two node in list
 * @node1: the first node
 * @node2: the second node
 * @lst: list
 */

void swap_node_fun(listint_t **lst, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = (*node1);
	node2->next = (*node1);
	node2->prev = (*node1)->prev;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*lst = node2;
	(*node1)->prev = node2;
	(*node1) = node2->prev;
}
