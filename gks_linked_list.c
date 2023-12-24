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

Node *append_list(Node **head1, Node **head2)
{
    Node    *current;

    current = *head1;
    if (current == NULL)
        return (*head2);
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

void sort_bubble_list(Node **head)
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

Node *insert_after(Node **head, int new_value, int after_value)
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

int main(void)
{
    Node    *head;
    Node    *head2;
    Node    *head3;
    Node    *head4;
    Node    *head5;
    Node    *head6;
    Node    *head7;
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

    printf("*****head2 list******\n");
    head2 = NULL;
    for (int i = 0; i < 10; i++)
    {
        head2 = insert_at_tail(&head2, i);
    }
    print_list(&head2);
    printf("*****append list******\n");
    head = append_list(&head, &head2);
    head2 = NULL;
    print_list(&head);

    printf("*****reverse list******\n");
    head = reverse_list(&head);
    print_list(&head);
    head3 = NULL;
    head3 = insert_at_tail(&head3, 5);
    head3 = insert_at_tail(&head3, 10);
    head3 = insert_at_tail(&head3, 15);
    head3 = insert_at_tail(&head3, 20);
    head3 = reverse_list(&head3);
    print_list(&head3);

    printf("*****sort list******\n");
    sort_bubble_list(&head);
    print_list(&head);

    printf("*****remove duplicates******\n");
    remove_duplicates(&head);
    print_list(&head);

    printf("*****insert after******\n");
    head = insert_after(&head, 100, 8);
    print_list(&head);
    head = insert_after(&head, 100, 18);
    print_list(&head);
    head = insert_after_or_tail(&head, 100, 18);
    print_list(&head);

    printf("*****sum values*******\n");
    head4 = NULL;
    for (int i = 0; i < 5; i++)
    {
        head4 = insert_at_tail(&head4, i);
    }
    head5 = NULL;
    for (int i = 10; i < 30; i++)
    {
        head5 = insert_at_tail(&head5, i);
    }
    head6 = sum_values(&head4, &head5);
    print_list(&head6);

    printf("*****duplicate list******\n");
    head7 = duplicate_list_recursive(head6);
    head7 = duplicate_list(&head6);
    print_list(&head7);

    printf("*****delete memory******\n");
    // delete_list_memory(&head);
    // delete_list_memory(&head2);
    // delete_list_memory(&head3);
    head = delete_list(head);
    head2 = delete_list(head2);
    head3 = delete_list(head3);
    // head4 = delete_list(head4);
    // head5 = delete_list(head5);
    head6 = delete_list(head6);
    head7 = delete_list(head7);
    print_list(&head);
    print_list(&head2);
    print_list(&head3);
    printf("*/*/*/*/*/*/*program end*/*/*/*/*/*/*/*\n");
    return (0);
}
