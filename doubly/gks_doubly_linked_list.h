#ifndef GKS_DOUBLY_LINKED_LIST_H
# define GKS_DOUBLY_LINKED_LIST_H

// #define val_name(v)#v
// printf("===========%s==========\n", val_name(head));


# include <stdlib.h> // calloc
# include <stdio.h> // printf
# include <stdbool.h> // bool
# include <time.h> // clock
# include <limits.h> // INT_MIN

typedef struct s_dode
{
	int			value; /**< the value stored in the t_dode */
	struct s_dode	*next; /**< pointer to the next t_dode in the list */
	struct s_dode	*prev; /**< pointer to the previous t_dode in the list */
}	t_dode;

void	db_print_list(t_dode **head);
t_dode	*db_insert_at_head(t_dode **head, int value);
t_dode	*db_insert_at_tail(t_dode **head, int value);
int		db_length(t_dode **head);
int		db_recursive_length(t_dode *head);


// /******searches******/
// int count_matches(t_dode *t_dode, int find_value);
// void replace_matches(t_dode *t_dode, int find_value, int replace_value);
// t_dode *delete_first_match(t_dode **head, int delete_value, bool *was_deleted);
// //most unefficient way to do this
// t_dode *delete_all_matches3(t_dode **head, int delete_value, bool *was_deleted);
// //least unefficient way to do this
// t_dode *delete_all_matches2(t_dode **head, int delete_value, int *number_deleted);
// //most efficient way to do this
// t_dode *delete_all_matches(t_dode **head, int delete_value, int *number_deleted);
// void remove_duplicates(t_dode **head);
// t_dode *insert_after_value(t_dode **head, int new_value, int after_value);
// t_dode *insert_after_or_tail(t_dode **head, int new_value, int after_value);

// /******sorts******/	
// void sort_list_bubble(t_dode **head);

// /******merges******/
// t_dode *append_list(t_dode **head1, t_dode **head2);
// t_dode *merge_sorted_lists(t_dode **head1, t_dode **head2);

// //my additional functions below
// t_dode *swap_t_dodes(t_dode **head, int pos1, int pos2);
// t_dode *swap_first_two(t_dode **head);
// t_dode *move_tail_to_head(t_dode **head);
// t_dode *move_head_to_tail(t_dode **head);
// t_dode *sort_list_quick(t_dode **head);
// void swap_data(t_dode **t_dode1, t_dode **t_dode2);
// int max_in_list(t_dode **head);
// int min_in_list(t_dode **head);
// t_dode *max_t_dode(t_dode **head);
// t_dode *min_t_dode(t_dode **head);
// t_dode *delete_last_match(t_dode **head, int delete_value, bool *was_deleted);
// t_dode *split_from_position(t_dode **head, int position);
// t_dode *split_from_value(t_dode **head, int value);
// t_dode *insert_after_position(t_dode **head, int new_value, int position);
// int	search_value(t_dode **head, int value);
// t_dode *rest_list(t_dode **long_list, t_dode **begin);

#endif