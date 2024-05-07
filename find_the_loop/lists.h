#ifndef LISTS_H
#define LISTS_H


#include <stddef.h>


/**
 * struct listint_s - Structure that defines a node for a singly linked list
 *
 * @n: the integer value stored in the node
 * @next: a pointer to the next node in the list
 */

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;


/* functions for testing */
listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);


/* 0-find_loop.c */
listint_t *find_listint_loop(listint_t *head);


#endif /* LISTS_H */
