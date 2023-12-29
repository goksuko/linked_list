/**
 * Linked List Library Functions
 * 
 * This file contains the function definitions for the linked list library. 
 * 
 * @file gks_linked_list_utils.c
 * @version 1.0
 * @date 2023-12-25
 * @author Ayse Goksu KAYa OZSAN
*/

#include "gks_linked_list.h"

void print_list(Node **head)
{
	Node    *current;
	int     i;

	current = *head;
	i = 0;
	printf("===Printing List===\n");
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

//mine first solution
void delete_list_memory(Node **head)
{
	Node    *current;
	Node    *temp;

	current = *head;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;
}

//portfolio courses
Node *delete_list(Node *node)
{
	if (node != NULL)
	{
		delete_list(node->next);
		free(node);
	}
	return (NULL);
}

int length(Node **head)
{
	Node    *current;
	int     i;

	current = *head;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}         

int recursive_length(Node *node)
{
	if (node == NULL)
		return (0);
	else
		return (1 + recursive_length(node->next));
}

bool is_member(Node *node, int find_value)
{
   if (node == NULL)
	   return (false);
   else if (node->value == find_value)
	   return (true);
   else
	   return (is_member(node->next, find_value));
}

int count_matches(Node *node, int find_value)
{
	if (node == NULL)
		return (0);
	else if (node->value == find_value)
		return (1 + count_matches(node->next, find_value));
	else
		return (count_matches(node->next, find_value));
}

void replace_matches(Node *node, int find_value, int replace_value)
{
	if (node != NULL)
	{
		if (node->value == find_value)
			node->value = replace_value;
		replace_matches(node->next, find_value, replace_value);
	}
}

Node *append_list(Node **head1, Node **head2)
{
	Node    *current;

	current = *head1;
	if (current == NULL)
		return (*head2);
	if (*head2 == NULL)
		return (*head1);
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = *head2;
		return (*head1);
	}
}

//copilot
Node *reverse_list2(Node **head)
{
	Node    *current;
	Node    *previous;
	Node    *following;

	current = *head;
	previous = NULL;
	while (current != NULL)
	{
		following = current->next;
		current->next = previous;
		previous = current;
		current = following;
	}
	return (previous);
}

//portfolio courses
Node *reverse_list(Node **head)
{
	Node    *current;
	Node    *next_node;
	Node    *temp;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	next_node = current->next;
	current->next = NULL;
	while (next_node != NULL)
	{
		temp = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = temp;
	}
	return (current);
}

//portfolio courses with memory leak
void    sum_values2(Node **head1, Node **head2)
{
	Node    *current1;
	Node    *current2;

	current1 = *head1;
	current2 = *head2;
	if (current1 == NULL || current2 == NULL) 
		return ;
	current1->value = current1->value + current2->value;
	sum_values2(&current1->next, &current2->next);
}

//my solution without memory leak and returns new list
Node *sum_values(Node **head1, Node **head2)
{
	Node    *current1;
	Node    *current2;
	Node    *new_head;
	int     new_value;

	current1 = *head1;
	current2 = *head2;
	if (current1 == NULL)
		return (current2);
	if (current2 == NULL)
		return (current1);
	new_head = NULL;
	while (current1 != NULL && current2 != NULL)
	{
		new_value = current1->value + current2->value;
		new_head = insert_at_tail(&new_head, new_value);
		current1 = current1->next;
		current2 = current2->next;
	}
	if (current1 == NULL)
	{
		while (current2 != NULL)
		{
			new_head = insert_at_tail(&new_head, current2->value);
			current2 = current2->next;
		}
	}
	else if (current2 == NULL)
	{
		while (current1 != NULL)
		{
			new_head = insert_at_tail(&new_head, current1->value);
			current1 = current1->next;
		}
	}
	delete_list(*head1);
	delete_list(*head2);
	return (new_head);
}

//my solution
Node *duplicate_list(Node **head)
{
	Node    *current;
	Node    *new_head;

	current = *head;
	if (current == NULL)
		return (NULL);
	new_head = NULL;
	while (current != NULL)
	{
		new_head = insert_at_tail(&new_head, current->value);
		current = current->next;
	}
	return (new_head);
}

//portfolio courses
Node *duplicate_list_recursive(Node *node)
{
	Node    *new_node;

	//in order to finish the recursive at tail
	if (node == NULL)
		return (NULL);
	new_node = calloc(1, sizeof(Node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = node->value;
	new_node->next = duplicate_list_recursive(node->next);
	return (new_node);
}

/**
 * Merges two sorted (lowest to highest) linked lists into a single sorted linked list.
 * 
 * @param head1 a pointer to the head of the first sorted linked list
 * @param head2 a pointer to the head of the second sorted linked list
 * @return a pointer to the head of the merged sorted linked list
 */
Node *merge_sorted_lists(Node **head1, Node **head2)
{
	Node *current1;
	Node *current2;
	Node **new_head;
	Node *new_current;

	current1 = *head1;
	current2 = *head2;
	if (current1 == NULL)
		return (current2);
	if (current2 == NULL)
		return (current1);
	if (current1->value <= current2->value)
	{
		new_head = head1;
		current1 = current1->next;
	}
	else
	{
		new_head = head2;
		current2 = current2->next;
	}
	new_current = *new_head;
	while (current1 != NULL && current2 != NULL)
	{
		if (current1->value <= current2->value)
		{
			new_current->next = current1;
			current1 = current1->next;
		}
		else if (current1->value > current2->value)
		{
			new_current->next = current2;
			current2 = current2->next;
		}
		new_current = new_current->next;
	}
	if (current1 == NULL)
		new_current->next = current2;
	if (current2 == NULL)
		new_current->next = current1;
	return (*new_head);
}

//my additional functions below
Node *swap_nodes(Node **head, int pos1, int pos2)
{
	Node *current;
	Node *node1;
	Node *node2;
	Node *previous1;
	Node *previous2;
	Node *temp1;
	Node *temp2;
	int temp_num;
	int i;


	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	if (pos1 == pos2 || pos1 < 0 || pos2 < 0)
		return (current);
	if (pos1 > pos2)
	{
		temp_num = pos1;
		pos1 = pos2;
		pos2 = temp_num;
	}
	if (pos2 > length(head) - 1)
		return (current);
	i = 0;
	if (pos1 == 0)
	{
		node1 = current;
		if (pos2 == 1)
		{
			node2 = current->next;
			temp1 = node2->next; //temp1 shows what will be the next node of node1 in the future
			node1->next = temp1;
			temp2 = node1;
			node2->next = temp2;
			current = node2;
			return (current);
		}
		else
		{
			while (i < pos2 - 1)
			{
				current = current->next;
				i++;
			}
			previous2 = current;
			node2 = current->next;
			temp1 = node2->next; //temp1 shows what will be the next node of node1 in the future
			temp2 = node1->next;
			node2->next = temp2;
			node1->next = temp1;
			previous2->next = node1;
			return (node2);
		}
	}
	else
	{
		while (i < pos1 - 1)
		{
			current = current->next;
			i++;
		}
		previous1 = current;
		node1 = current->next;
		while (i < pos2 - 1)
		{
			current = current->next;
			i++;
		}
		previous2 = current;
		node2 = current->next;
		temp1 = node2->next; //temp1 shows what will be the next node of node1 in the future
		temp2 = node1->next;
		node2->next = temp2;
		node1->next = temp1;
		previous1->next = node2;
		previous2->next = node1;
		return (*head);
	}
}

Node *swap_first_two(Node **head)
{
	Node *current;
	Node *node1;
	Node *node2;
	Node *temp1;
	Node *temp2;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	node1 = current;
	node2 = current->next;
	temp1 = node2->next; //temp1 shows what will be the next node of node1 in the future
	node1->next = temp1;
	temp2 = node1;
	node2->next = temp2;
	current = node2;
	return (current);
}

Node *move_tail_to_head(Node **head)
{
	Node *current;
	Node *previous;
	Node *tail;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	tail = current;
	previous->next = NULL;
	tail->next = *head;
	*head = tail;
	return (*head);
}

Node *move_head_to_tail(Node **head)
{
	Node *current;
	Node *tail;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	tail = current;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tail;
	*head = tail->next;
	tail->next = NULL;
	return (*head);
}

void swap_data(Node **node1, Node **node2)
{
	int temp;

	temp = (*node1)->value;
	(*node1)->value = (*node2)->value;
	(*node2)->value = temp;
}

int max_in_list(Node **head)
{
	Node *current;
	int max;

	current = *head;
	if (current == NULL)
		return (0);
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int min_in_list(Node **head)
{
	Node *current;
	int min;

	current = *head;
	if (current == NULL)
		return (0);
	min = current->value;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

Node *max_node(Node **head)
{
	Node *current;
	Node *max_node;

	current = *head;
	if (current == NULL)
		return (NULL);
	max_node = current;
	while (current != NULL)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

Node *min_node(Node **head)
{
	Node *current;
	Node *min_node;

	current = *head;
	if (current == NULL)
		return (NULL);
	min_node = current;
	while (current != NULL)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

Node *split_from_position(Node **head, int position)
{
	Node *current;
	Node *following;
	Node *new_head;
	Node *temp;
	int i;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	if (position < 0)
		return (current);
	if (position > length(head) - 1)
		return (NULL);
	i = 0;
	while (i < position)
	{
		current = current->next;
		i++;
	}
	following = current->next;
	current->next = NULL;
	new_head = following;
	current = *head;
	i = i + 1;
	while (i--)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	return (new_head);
}

Node *split_from_value(Node **head, int value)
{
	Node    *current;
	Node    *following;
	Node	*temp;
	
	current = *head;
	if (current == NULL)
		return (NULL);
	temp = NULL;
	while (current != NULL)
	{
		if (current->value == value)
		{
			following = current->next;
			temp = current;
			break ;
		}
		current = current->next;
	}
	if (temp != NULL)
	{
		current = *head;
		while (current->next != following)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		current->next = NULL;
		free(current);
		return (following);
	}
	return (*head);
}
