#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *db_insert_at_head(Node **head, int value)
{
	Node *new_node;

	new_node = (Node *)malloc(sizeof(Node));
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

void	db_print_list(Node **head)
{
	Node *current;
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

int main()
{
    Node *head;
    Node *head2;

    head = (Node *)malloc(sizeof(Node));
    if (!head)
        return (0);
    head->value = 1;
    head->prev = NULL;

    head->next = (Node *)malloc(sizeof(Node));
    if (!head->next)
        return (0);
    head->next->value = 2;
    head->next->prev= head;

    head->next->next = (Node *)malloc(sizeof(Node));
    if (!head->next->next)
        return (0);
    head->next->next->value = 3;
    head->next->next->next = NULL;   
    head->next->next->prev = head->next;

    printf("head->value: %d\n", head->value);
    printf("head->next->value: %d\n", head->next->value);
    printf("head->next->next->value: %d\n", head->next->next->value);

    db_insert_at_head(&head, 0);
    printf("head->value: %d\n", head->value);
    printf("head->next->value: %d\n", head->next->value);
    printf("head->next->next->value: %d\n", head->next->next->value);
    printf("head->next->next->next->value: %d\n", head->next->next->next->value);

    head2 = NULL;
    db_print_list(&head2);
    db_insert_at_head(&head2, 0);
    printf("head2->value: %d\n", head2->value);

    db_print_list(&head);
    db_print_list(&head2);

    return 0;
}
