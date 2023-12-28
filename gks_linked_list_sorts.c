#include "gks_linked_list.h"

void sort_list_bubble(Node **head)
{
	Node *current;
	Node *previous;
	bool swapped;
	int temp;

	current = *head;
	if (current == NULL)
		return ;
	if (current->next == NULL)
		return ;
	swapped = false;
	do {
		swapped = false;
		current = *head;
		previous = NULL;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;            
			if (current != NULL)
			{
				if (current->value < previous->value)
				{
					temp = current->value;
					current->value = previous->value;
					previous->value = temp;
					swapped = true;
				}
			}
		}
	}while (swapped == true);  
}

Node *sort_list_quick(Node **head)
{
	Node *current;
	Node *pivot;
	Node *smaller;
	Node *larger;
	Node *temp;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	pivot = current;
	smaller = NULL;
	larger = NULL;
	current = current->next;
	while (current != NULL)
	{
		temp = current->next;
		if (current->value <= pivot->value)
		{
			current->next = smaller;
			smaller = current;
		}
		else
		{
			current->next = larger;
			larger = current;
		}
		current = temp;
	}
	smaller = sort_list_quick(&smaller);
	larger = sort_list_quick(&larger);
	pivot->next = larger;
	if (smaller == NULL)
		return (pivot);
	else
	{
		current = smaller;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = pivot;
		return (smaller);
	}
}

