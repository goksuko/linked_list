#include "gks_doubly_linked_list.h"

void	db_print_list(t_dode **head)
{
	t_dode	*current;
	int		i;

	current = *head;
	i = 0;
	printf("======Printing list======\n");
	if (current == NULL)
		printf("List is empty\n");
	printf("========length: %d========\n", db_length(head));
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

void	db_print_reverse_list(t_dode **head)
{
	t_dode	*current;
	int		i;

	current = *head;
	i = db_length(head);
	printf("======Printing Reverse list======\n");
	if (current == NULL)
		printf("List is empty\n");
	printf("========length: %d========\n", i);
	while (current->next != NULL)
		current = current->next;
	while (current != NULL)
	{
		printf("Node %d: %d\n", i - 1, current->value);
		i--;
		current = current->prev;
	}
}

void	db_free_list(t_dode **head)
{
	t_dode	*current;
	t_dode	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

t_dode	*db_insert_at_head(t_dode **head, int value)
{
	t_dode	*new_node;

	new_node = (t_dode *)malloc(sizeof(t_dode));
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

t_dode	*db_insert_at_tail(t_dode **head, int value)
{
	t_dode	*new_node;
	t_dode	*current;

	current = *head;
	new_node = (t_dode *)malloc(sizeof(t_dode));
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

int	db_length(t_dode **head)
{
	int		i;
	t_dode	*current;

	i = 0;
	current = *head;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int db_recursive_length(t_dode *head)
{
	if (head == NULL)
		return (0);
	else
		return (1 + db_recursive_length(head->next));
}

t_dode	*db_reverse_list(t_dode **head)
{
	t_dode	*current;
	t_dode	*next_node;

	current = *head;

	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	next_node = current->next;
	current->next = NULL;
	current->prev = next_node;
	while (next_node != NULL)
	{
		next_node->prev = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = next_node->prev;
	}
	*head = current;
	return (*head);
}

t_dode	*db_delete_at_head(t_dode **head)
{
	t_dode	*current;
	t_dode	*temp;

	current = *head;
	if (current == NULL)
		return (NULL);
	else
	{
		temp = current->next;
		temp->prev = NULL;
		free(current);
		*head = temp;
		return (*head);
	}
}

t_dode	*db_delete_at_tail(t_dode **head)
{
	t_dode	*current;

	current = *head;
	if (current == NULL)
		return (NULL);
	else if (current->next == NULL)
	{
		free(current);
		*head = NULL;
		return (NULL);
	}
	while (current->next->next != NULL)
		current = current->next;
	free (current->next);
	current->next = NULL;
	return (*head);
}

bool db_is_member(t_dode *head, int find_value)
{
	if (head == NULL)
		return (false);
	else if (head->value == find_value)
		return (true);
   	else
		return (db_is_member(head->next, find_value));
}

int db_count_matches(t_dode **head, int find_value)
{
	t_dode	*current;
	int		i;

	i = 0;
	current = *head;
	while (current != NULL)
	{
		if (current->value == find_value)
			i++;
		current = current->next;
	}
	return(i);
}

void db_replace_matches(t_dode **head, int find_value, int replace_value)
{
	t_dode	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->value == find_value)
			current->value = replace_value;
		current = current->next;
	}
}

int db_max_in_list(t_dode **head)
{
	t_dode	*current;
	int		i;

	current = *head;
	i = INT_MIN;
	if (current == NULL)
		return (0);
	while (current != NULL)
	{
		if (current->value > i)
			i = current->value;
		current = current->next;
	}
	return (i);
}

int db_min_in_list(t_dode **head)
{
	t_dode	*current;
	int		i;

	i = INT_MAX;
	current = *head;
	if (current == NULL)
		return (0);
	while (current != NULL)
	{
		if (current->value < i)
			i = current->value;
		current = current->next;
	}
	return (i);
}

t_dode *db_swap_values(t_dode **head, unsigned int pos1, unsigned int pos2)
{
	t_dode			*current;
	t_dode			*temp1;
	t_dode			*temp2;
	unsigned int	i;
	unsigned int	temp_int;
	unsigned int	length;

	current = *head;
	length = db_length(head);
	if (current == NULL)
		return (NULL);
	if (current->next == NULL || pos1 == pos2 || pos1 > length - 1 || pos2 > length - 1)
		return (current);
	if (pos1 > pos2)
	{
		i = pos1;
		pos1 = pos2;
		pos2 = i;
	}
	i = 0;
	while (i < pos1 && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	temp1 = current;
	while (i < pos2 && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	temp2 = current;
	temp_int = temp1->value;
	temp1->value = temp2->value;
	temp2->value = temp_int;
	return (*head);
}

t_dode *db_swap_head_and_tail(t_dode **head)
{
	t_dode	*current;
	t_dode	*prev;
	t_dode	*tail;

	current = *head;
	if (current ==  NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	while (current->next->next != NULL)
		current = current->next;
	prev = current;
	tail = current->next;
	current = *head;
	tail->next = current->next;
	tail->prev = NULL;
	current->next->prev = tail;
	current->next = NULL;
	current->prev = prev;
	prev->next = current;
	*head = tail;
	return (*head);
}

t_dode *db_move_tail_to_head(t_dode **head)
{
	t_dode	*current;
	t_dode	*prev;
	t_dode	*tail;

	current = *head;
	if (current ==  NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	while (current->next->next != NULL)
		current = current->next;
	prev = current;
	tail = current->next;
	current = *head;
	prev->next = NULL;
	tail->prev = NULL;
	tail->next = current;
	current->prev = tail;
	*head = tail;
	return (*head);
}

t_dode *db_move_head_to_tail(t_dode **head)
{
	t_dode	*current;
	t_dode	*tail;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	while (current->next != NULL)
		current = current->next;
	tail = current;
	current = *head;
	*head = current->next;
	current->next->prev = NULL;
	current->next = NULL;
	current->prev = tail;
	tail->next = current;
	return (*head);
}

t_dode	*db_search_value(t_dode **head, int value)
{
	t_dode	*current;

	current = *head;
	while (current->value != value && current->next != NULL)
		current = current->next;
	if (current->value == value)
	{
		current->prev = NULL;
		return (current);
	}
	else
		return (*head);
}

t_dode	*db_swap_first_two(t_dode **head)
{
	t_dode	*current;
	t_dode	*next_node;

	current = *head;
	if (current == NULL)
		return (NULL);
	if (current->next == NULL)
		return (current);
	next_node = current->next;
	next_node->next->prev = current;
	next_node->prev = NULL;
	current->next = next_node->next;
	next_node->next = current;
	current->prev = next_node;
	*head = next_node;
	return (*head);
}

int main (void)
{
	t_dode	*head1;
	t_dode	*head2;
	int		i;

	head1 = NULL;
	for (i = 0; i < 10; i++)
		db_insert_at_head(&head1, i);
	db_print_list(&head1);
	printf("recursive length: %d\n", db_recursive_length(head1));
	head2 = NULL;
	for (i = 0; i < 10; i++)
		db_insert_at_tail(&head2, i);
	db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// printf("recursive length: %d\n", db_recursive_length(head2));
	// head2 = db_reverse_list(&head2);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// db_delete_at_head(&head2);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// db_delete_at_tail(&head2);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// printf("is_member 2: %d\n", db_is_member(head2, 2));
	// printf("is_member 8: %d\n", db_is_member(head2, 8));
	// printf("is_member 0: %d\n", db_is_member(head2, 0));
	// printf("matches of 1: %d\n", db_count_matches(&head2, 1));
	// printf("matches of 10: %d\n", db_count_matches(&head2, 10));
	// printf("replace 5 with 15\n");
	// db_replace_matches(&head2, 5, 15);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// printf("max: %d\n", db_max_in_list(&head2));
	// printf("min: %d\n", db_min_in_list(&head2));
	// head2 = db_swap_values(&head2, 3, 5);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// head2 = db_swap_values(&head2, 0, 5);
	// db_print_list(&head2);
	// head2 = db_swap_values(&head2, 0, 15);
	// db_print_list(&head2);
	// head2 = db_swap_values(&head2, 7, 0);
	// db_print_list(&head2);
	// head2 = db_swap_head_and_tail(&head2);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// head2 = db_move_tail_to_head(&head2);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// head2 = db_move_head_to_tail(&head2);
	// head2 = db_search_value(&head2, 5);
	// db_print_list(&head2);
	// db_print_reverse_list(&head2);
	// head2 = db_search_value(&head2, 15);
	head2 = db_swap_first_two(&head2);
	db_print_list(&head2);
	db_print_reverse_list(&head2);


	
	db_free_list(&head1);
	db_free_list(&head2);
	
	return (0);
}
