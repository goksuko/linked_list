/**
 * Linked List Library Header File
 * 
 * This file contains the function prototypes for the linked list library. 
 * 
 * @file gks_linked_list.h
 * @version 1.0
 * @date 2023-12-25
 * @author Ayse Goksu KAYa OZSAN
*/

#ifndef GKS_LINKED_LIST_H
#define GKS_LINKED_LIST_H

# include <stdlib.h> // calloc
# include <stdio.h> // printf
# include <stdbool.h> // bool
# include <time.h> // clock

/**
 * A node in a linked list.
*/

typedef struct Node {
    int value; /**< the value stored in the node */
    struct Node *next; /**< pointer to the next node in the list */
} Node;

void print_list(Node **head);
//mine first solution
void delete_list_memory(Node **head);
//portfolio courses
Node *delete_list(Node *node);
Node *insert_at_head(Node **head, int new_value);
Node* insert_at_tail(Node **head, int new_value);
Node *delete_at_head(Node **head);
Node *delete_at_tail(Node **head);
int length(Node **head);
int recursive_length(Node *node);
bool is_member(Node *node, int find_value);
int count_matches(Node *node, int find_value);
void replace_matches(Node *node, int find_value, int replace_value);
Node *delete_first_match(Node **head, int delete_value, bool *was_deleted);
//most unefficient way to do this
Node *delete_all_matches3(Node **head, int delete_value, bool *was_deleted);
//least unefficient way to do this
Node *delete_all_matches2(Node **head, int delete_value, int *number_deleted);
//most efficient way to do this
Node *delete_all_matches(Node **head, int delete_value, int *number_deleted);
Node *append_list(Node **head1, Node **head2);
//copilot
Node *reverse_list2(Node **head);
//portfolio courses
Node *reverse_list(Node **head);
void sort_list_bubble(Node **head);
void remove_duplicates(Node **head);
Node *insert_after_value(Node **head, int new_value, int after_value);
Node *insert_after_or_tail(Node **head, int new_value, int after_value);
//portfolio courses with memory leak
void    sum_values2(Node **head1, Node **head2);
//my solution without memory leak and returns new list
Node *sum_values(Node **head1, Node **head2);
//my solution
Node *duplicate_list(Node **head);
//portfolio courses
Node *duplicate_list_recursive(Node *node);
Node *merge_sorted_lists(Node **head1, Node **head2);
//my additional functions below
Node *swap_nodes(Node **head, int pos1, int pos2);
Node *swap_first_two(Node **head);
Node *move_tail_to_head(Node **head);
Node *move_head_to_tail(Node **head);
Node *sort_list_quick(Node **head);
void swap_data(Node **node1, Node **node2);
int max_in_list(Node **head);
int min_in_list(Node **head);
Node *max_node(Node **head);
Node *min_node(Node **head);
Node *delete_last_match(Node **head, int delete_value, bool *was_deleted);
Node *split_from_position(Node **head, int position);
Node *split_from_value(Node **head, int value);
Node *insert_after_position(Node **head, int new_value, int position);

#endif