#include "gks_doubly_linked_list.h"

Dode	*db_insert_at_head(Dode **head, int value)
{
	Dode	*new_dode;

	new_dode = (Dode *)malloc(sizeof(Dode));
	if (new_dode == NULL)
		return (NULL);
	new_dode->value = value;
	new_dode->prev = NULL;
	new_dode->next = *head;
	if (*head != NULL)
		(*head)->prev = new_Dode;
	*head = new_Dode;
	return (*head);
}

void	db_print_list(Dode **head)
{
	Dode	*current;
	int		i;

	current = *head;
	i = 0;
	if (current == NULL)
		printf("List is empty\n");
	printf("======Printing list======\n");
	while (current != NULL)
	{
		printf("Dode %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

// int main()
// {
//     Dode *head;
//     Dode *head2;

//     head = (Dode *)malloc(sizeof(Dode));
//     if (!head)
//         return (0);
//     head->value = 1;
//     head->prev = NULL;

//     head->next = (Dode *)malloc(sizeof(Dode));
//     if (!head->next)
//         return (0);
//     head->next->value = 2;
//     head->next->prev= head;

//     head->next->next = (Dode *)malloc(sizeof(Dode));
//     if (!head->next->next)
//         return (0);
//     head->next->next->value = 3;
//     head->next->next->next = NULL;   
//     head->next->next->prev = head->next;

//     printf("head->value: %d\n", head->value);
//     printf("head->next->value: %d\n", head->next->value);
//     printf("head->next->next->value: %d\n", head->next->next->value);

//     db_insert_at_head(&head, 0);
//     printf("head->value: %d\n", head->value);
//     printf("head->next->value: %d\n", head->next->value);
//     printf("head->next->next->value: %d\n", head->next->next->value);
//     printf("head->next->next->next->value: %d\n", head->next->next->next->value);

//     head2 = NULL;
//     db_print_list(&head2);
//     db_insert_at_head(&head2, 0);
//     printf("head2->value: %d\n", head2->value);

//     db_print_list(&head);
//     db_print_list(&head2);

//     return 0;
// }
