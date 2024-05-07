#include "lists.h"

/**
 * find_listint_loop - program that finds the loop in a linked list using
 * Floyd's Cycle Detection Algorithm
 *
 * Floyd's Cycle Detection Algorithm, also known as the "tortoise and hare"
 * algorithm, is a method to detect cycles or loops in a data structure
 * by using two pointers that move at different speeds through the structure;
 * if there is a cycle, these pointers will eventually meet;
 * otherwise, they will reach the end of the structure without meeting
 *
 * @head: a pointer to the head of the linked list
 *
 * Return: the address of the node where the loop starts,
 *         or NULL if there is no loop
 */


listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head;
	listint_t *hare = head;

	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;

			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (tortoise);
		}
	}
	return (NULL);
}
