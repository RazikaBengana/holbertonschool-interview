#ifndef LISTS_H
#define LISTS_H


#include <stdio.h>
#include <stdlib.h>



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


/* functions for testing */   /* linked_lists.c */
size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);


/* 0-insert_number.c */
listint_t *insert_node(listint_t **head, int number);


#endif /* LISTS_H */
