/**
 * Linked List Library Header File
 * 
 * This file contains the function prototypes for the linked list library. 
 * 
 * @file gks_double_linked_list.h
 * @version 1.0
 * @date 2023-12-30
 * @author Ayse Goksu KAYa OZSAN
*/

#ifndef GKS_DOUBLE_LINKED_LIST_H
#define GKS_DOUBLE_LINKED_LIST_H

# include <stdlib.h> // calloc
# include <stdio.h> // printf
# include <stdbool.h> // bool
# include <time.h> // clock

/**
 * A double linked node in a linked list.
*/

typedef struct Dode {
	int         value; /**< the value stored in the node */
	struct Dode *next; /**< pointer to the next node in the list */
	struct Dode *prev; /**< pointer to the previous node in the list */
} Dode;

void    db_print_list(Dode **head);
Dode	*db_insert_at_head(Dode **head, int value);
Dode	*db_insert_at_tail(Dode **head, int value);

#endif