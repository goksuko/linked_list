#include "gks_double_linked_list.h"

Dode *db_insert_at_head(Dode **head, int value)
{
	Dode *new_node;

	new_node = (Dode *)malloc(sizeof(Dode));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (*head);
}

Dode *db_insert_at_tail(Dode **head, int value)
{
	Dode *new_node;
	Dode *current;

	current = *head;
	new_node = (Dode *)malloc(sizeof(Dode));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	else
		*head = new_node;
	return (*head);
}

void	db_print_list(Dode **head)
{
	Dode *current;
	int i;

	current = *head;
	i = 0;
	if (current == NULL)
		printf("List is empty\n");
	printf("======Printing list======\n");
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

void	db_free_list(Dode **head)
{
	Dode *current;
	Dode *next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

int main (void)
{
	Dode *head1;
	Dode *head2;
	int i;

	head1 = NULL;
	for (i = 0; i < 10; i++)
		db_insert_at_head(&head1, i);
	db_print_list(&head1);
	head2 = NULL;
	for (i = 0; i < 10; i++)
		db_insert_at_tail(&head2, i);
	db_print_list(&head2);

	db_free_list(&head1);
	db_free_list(&head2);
	
	return (0);
}
