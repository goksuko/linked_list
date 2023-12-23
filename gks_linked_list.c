#include <stdlib.h> // calloc
#include <stdio.h> // printf
#include <stdbool.h> // bool

typedef struct Node {
    int value;
    struct Node *next;
} Node;

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

Node *insert_at_head(Node **head, int new_value)
{
    Node    *new_node;

    new_node = calloc(1, sizeof(Node));
    if (new_node == NULL)
        return (NULL);
    new_node->value = new_value;
    if (*head == NULL)
    {
        return (new_node);
    }
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
    {
        return (new_node);
    }
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



int main(void)
{
    Node    *head;
    bool    true_or_false;
    int     i;

    i = 0;
    head = NULL;
    head = insert_at_head(&head, 5);
    head = insert_at_head(&head, 10);
    head = insert_at_head(&head, 15);
    head = insert_at_tail(&head, -5);
    head = insert_at_tail(&head, -10);
    head = insert_at_tail(&head, -15);
    head = insert_at_tail(&head, -5);
    head = insert_at_tail(&head, -10);
    head = insert_at_tail(&head, -15);
    print_list(&head);
    head = delete_at_head(&head);
    head = delete_at_tail(&head);
    head = delete_at_tail(&head);
    printf("\n");
    print_list(&head);
    printf("\n");
    printf("Length: %d\n", length(&head));
    printf("Recursive Length: %d\n", recursive_length(head));
    printf("Is Member: %d\n", is_member(head, 5));
    printf("Is Member: %d\n", is_member(head, 8));
    printf("Count Matches -5: %d\n", count_matches(head, -5));
    printf("Count Matches: %d\n", count_matches(head, 8));
    printf("Count Matches: %d\n", count_matches(head, -15));
    printf("\n");
    replace_matches(head, -5, 5);
    printf("Count Matches -5: %d\n", count_matches(head, -5));
    printf("\n");
    print_list(&head);
    printf("\n");

    head = delete_first_match(&head, 5, &true_or_false);
    printf("Delete First Match 5: %d\n", true_or_false);
    print_list(&head);
    head = delete_first_match(&head, 8, &true_or_false);
    printf("Delete First Match 8: %d\n", true_or_false);
    print_list(&head);
    head = delete_first_match(&head, 10, &true_or_false);
    printf("Delete First Match 10: %d\n", true_or_false);
    printf("head value: %d\n", head->value);
    print_list(&head);
    head = insert_at_tail(&head, -5);
    head = insert_at_tail(&head, -10);
    head = insert_at_tail(&head, -15);
    head = insert_at_tail(&head, -5);
    head = insert_at_tail(&head, -10);
    head = insert_at_tail(&head, -15);
    print_list(&head);
    head = delete_all_matches(&head, -5, &i);
    printf("Delete All Matches -5: %d\n", i);
    print_list(&head);
    head = delete_all_matches(&head, -10, &i);
    printf("Delete All Matches -10: %d\n", i);
    print_list(&head);


    printf("*****delete memory******\n");
    while (head != NULL)
    {
        head = delete_at_head(&head);
    }
    print_list(&head);
    printf("*/*/*/*/*/*/*program end*/*/*/*/*/*/*/*\n");
    return (0);
}
