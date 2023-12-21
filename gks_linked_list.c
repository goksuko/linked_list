#include <stdlib.h> // calloc
#include <stdio.h> // printf

typedef struct node {
    int value;
    struct node *next;
} node;

void print_list(node *head)
{
    node    *current;
    int     i;

    current = head;
    i = 0;
    while (current != NULL)
    {
        printf("Node %d: %d\n", i, current->value);
        i++;
        current = current->next;
    }
}

node *insert_at_head(node *head, int new_value)
{
    node    *new_node;

    new_node = calloc(1, sizeof(node));
    new_node->value = new_value;
    if (head == NULL)
    {
        return (new_node);
    }
    else
    {
        new_node->next = head;
        return (new_node);
    }
}

node* insert_at_tail(node *head, int new_value)
{
    node    *new_node;
    node    *current;

    new_node = calloc(1, sizeof(node));
    new_node->value = new_value;
    if (head == NULL)
    {
        return (new_node);
    }
    else
    {
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        return (head);
    }
}

node *delete_at_head(node *head)
{
    node    *to_return;

    if (head == NULL)
    {
        return (NULL);
    }
    else
    {
        to_return = head->next;
        free(head);
        return (to_return);
    }
}

node *delete_at_tail(node *head)
{
    node    *current;


    if (head == NULL)
    {
        return (NULL);
    }
    else if (head->next == NULL)
    {
        free(head);
        return (NULL);
    }
    else
    {
        current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        return (head);
    }
}

int main(void)
{
    node    *head;

    head = NULL;
    head = insert_at_head(head, 5);
    head = insert_at_head(head, 10);
    head = insert_at_head(head, 15);
    head = insert_at_tail(head, -5);
    head = insert_at_tail(head, -10);
    head = insert_at_tail(head, -15);
    print_list(head);
    head = delete_at_head(head);
    head = delete_at_tail(head);
    head = delete_at_tail(head);
    printf("\n");
    print_list(head);
    return (0);
}
