#include "gks_linked_list.h"

Node *insert_at_head(Node **head, int new_value)
{
	Node    *new_node;

	new_node = calloc(1, sizeof(Node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = new_value;
	if (*head == NULL)
		return (new_node);
	else
	{
		new_node->next = *head;
		return (new_node);
	}
}

Node* insert_at_tail(Node **head, int new_value)
{
	Node    *new_node;
	Node    *current;

	new_node = calloc(1, sizeof(Node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = new_value;
	new_node->next = NULL;
	current = *head;
	if (current == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		return (*head);
	}
}

Node *insert_after_value(Node **head, int new_value, int after_value)
{
	Node    *new_node;
	Node    *current;
	Node    *following;

	new_node = calloc(1, sizeof(Node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = new_value;
	current = *head;
	if (current == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
		{
			if (current->value == after_value)
			{
				following = current->next;
				current->next = new_node;
				new_node->next = following;
				return (*head);
			}
			else
				current = current->next;
		}
		if (current->next == NULL)
		{
			free(new_node);
			return (*head);
		}
	}
	return (*head);
}

Node *insert_after_or_tail(Node **head, int new_value, int after_value)
{
	Node    *new_node;
	Node    *current;
	Node    *following;

	new_node = calloc(1, sizeof(Node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = new_value;
	current = *head;
	if (current == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
		{
			if (current->value == after_value)
			{
				following = current->next;
				current->next = new_node;
				new_node->next = following;
				return (*head);
			}
			else
				current = current->next;
		}
		if (current->next == NULL)
		{
			current->next = new_node;
			new_node->next = NULL;
			return (*head);
		}
	}
	return (*head);
}

Node *insert_after_position(Node **head, int new_value, int position)
{
	Node *current;
	Node *following;
	Node *new_node;
	int i;

	current = *head;
	if (current == NULL)
		return (NULL);
	new_node = calloc(1, sizeof(Node));
	if (new_node == NULL)
		return (NULL);
	if (position < 0)
		return (current);
	if (position > length(head) - 1)
		return (NULL);
	new_node->value = new_value;
	if (current->next == NULL)
		return (current);
	i = 0;
	while (i < position)
	{
		current = current->next;
		i++;
	}
	following = current->next;
	current->next = new_node;
	new_node->next = following;
	return (*head);
}
