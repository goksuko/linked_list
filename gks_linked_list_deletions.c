#include "gks_linked_list.h"

Node *delete_at_head(Node **head)
{
	Node    *to_return;
	Node    *current;

	current = *head;
	if (current == NULL)
	{
		return (NULL);
	}
	else
	{
		to_return = current->next;
		free(*head);
		return (to_return);
	}
}

Node *delete_at_tail(Node **head)
{
	Node    *current;

	current = *head;
	if (current == NULL)
		return (NULL);
	else if (current->next == NULL)
	{
		free(*head);
		return (NULL);
	}
	else
	{
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		free(current->next);
		current->next = NULL;
		return (*head);
	}
}

Node *delete_first_match(Node **head, int delete_value, bool *was_deleted)
{
	Node    *current;
	Node    *previous;
	Node    *following;
	
	current = *head;
	if (current == NULL)
	{
		*was_deleted = false;
		return (NULL);
	}
	else if (current->value == delete_value)
	{
		*was_deleted = true;
		following = current->next;
		free(current);
		return (following);
	}
	else
	{
		previous = *head;
		current = previous->next;
		while (current != NULL)
		{
			if (current->value == delete_value)
			{
				*was_deleted = true;
				previous->next = current->next;
				free(current);
				return (*head);
			}
			previous = current;
			current = current->next;
		}
		*was_deleted = false;
		return (*head);
	}
}

//most unefficient way to do this
Node *delete_all_matches3(Node **head, int delete_value, bool *was_deleted)
{
	Node    *temp;
	int    i;
	int    j;
	
	temp = *head;
	i = length(head);
	j = i;

	while(i--)
	{
		delete_first_match(&temp, delete_value, was_deleted);
	}
	if (j == length(head))
		*was_deleted = false;
	else
		*was_deleted = true;
	return (*head);
}

//least unefficient way to do this
Node *delete_all_matches2(Node **head, int delete_value, int *number_deleted)
{
	Node    *current;
	bool    was_deleted;

	was_deleted = false;
	current = *head;
	*number_deleted = 0;
	do
	{
		delete_first_match(&current, delete_value, &was_deleted);
		if (was_deleted == true)
			*number_deleted = *number_deleted + 1;
	} while (was_deleted == true);
	return (current);
}

//most efficient way to do this
Node *delete_all_matches(Node **head, int delete_value, int *number_deleted)
{
	Node    *current;
	Node    *new_head;
	Node    *following;
	Node    *temp;

	current = *head;
	*number_deleted = 0;
	if (current == NULL)
		return (NULL);
	while (current != NULL && current->value == delete_value)
	{
		following = current->next;
		free(current);
		*number_deleted = *number_deleted + 1;
		current = following;
	}
	new_head = current;
	if (new_head == NULL)
		return (NULL);
	while (current->next != NULL)
	{
		if (current->next->value == delete_value)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*number_deleted = *number_deleted + 1;
		}
		else
			current = current->next;
	}
	return (new_head);
}

void remove_duplicates(Node **head)
{
	Node    *current;
	Node    *current2;
	Node    *duplicate;
	

	current = *head;
	if (current == NULL)
		return ;
	if (current->next == NULL)
		return ;
	while (current != NULL && current->next != NULL)
	{
		current2 = current;
		while (current2->next != NULL)
		{
			if (current->value == current2->next->value)
			{
				duplicate = current2->next;
				current2->next = current2->next->next;
				free(duplicate);
			}
			else
				current2 = current2->next;
		}
		current = current->next;
	}
}

void delete_node(Node **node)
{
	Node *temp;

	temp = *node;
	*node = (*node)->next;
	free(temp);
}

Node *delete_last_match(Node **head, int delete_value, bool *was_deleted)
{
	Node    *current;
	Node    *following;
	Node	*temp;
	
	current = *head;
	if (current == NULL)
	{
		*was_deleted = false;
		return (NULL);
	}
	temp = NULL;
	*was_deleted = false;
	while (current->next != NULL)
	{
		if (current->value == delete_value)
		{
			*was_deleted = true;
			temp = current;
		}
		following = current->next;
		current = following;
	}
	if (*was_deleted == true)
	{
		current = *head;
		while (current->next != temp)
		{
			current = current->next;
		}
		current->next = temp->next;
		free(temp);
	}
	return (*head);
}

