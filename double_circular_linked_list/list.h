#ifndef LIST_H
#define LIST_H


#include <stdlib.h>
#include <string.h>



/**
 * struct List - Structure representing a node in a doubly linked list
 *
 * @str: points to a string stored within the node (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 */

typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;



/* 0-add_node.c */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);


#endif /* LIST_H */
