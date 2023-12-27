#include "gks_linked_list.h"

int main(void)
{
    Node    *head;
    Node    *head2;
    Node    *head3;
    Node    *head4;
    Node    *head5;
    Node    *head6;
    Node    *head7;
    Node    *head8;
    Node    *head9;
    Node    *head_timer;
    bool    true_or_false;
    int     i;
    int    j;
    int    elements;
    int     tic;
    int     toc;
    int     *array;
    int    *new_array;

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
    // head = sort_list_quick(&head);
    // sort_list_bubble(&head);
    head = sort_list_insertion(&head);
    print_list(&head);

    return (0);
}


//     printf("*****remove duplicates******\n");
//     remove_duplicates(&head);
//     print_list(&head);

//     printf("*****insert after******\n");
//     head = insert_after(&head, 100, 8);
//     print_list(&head);
//     head = insert_after(&head, 100, 18);
//     print_list(&head);
//     head = insert_after_or_tail(&head, 100, 18);
//     print_list(&head);

//     printf("*****sum values*******\n");
//     head4 = NULL;
//     for (int i = 0; i < 5; i++)
//     {
//         head4 = insert_at_tail(&head4, i);
//     }
//     head5 = NULL;
//     for (int i = 10; i < 15; i++)
//     {
//         head5 = insert_at_tail(&head5, i);
//     }
//     head6 = sum_values(&head4, &head5);
//     print_list(&head6);

//     printf("*****duplicate list******\n");
//     // head7 = duplicate_list_recursive(head6);
//     head7 = duplicate_list(&head6);
//     print_list(&head7);

//     printf("*****merge sorted list******\n");
//     head8 = NULL;
//     for (int i = 0; i < 20; i++)
//     {
//         j = rand() % 50;
//         head8 = insert_at_tail(&head8, j);
//         sort_list_bubble(&head8);
//     }
//     print_list(&head8);
//     head6 = merge_sorted_lists(&head6, &head8);
//     print_list(&head6);

//     printf("*****timer test*******\n");
//     elements = 10000;
//     array = malloc(sizeof(int) * elements);
//     for (i = 0; i < elements; i++)
//     {    
//         array[i] = i;
//     }
//     tic = clock();
//     for (i = 1; i <= elements; i++)
//     {
//         new_array = malloc(sizeof(int) * (elements - i));
//         for (j = 0; j < elements - i; j++)
//             new_array[j] = array[j + 1];
//         free(array);
//         array = new_array;
//     }
//     toc = clock();
//     printf("Time elapsed for array: %f\n", (double)(toc - tic) / CLOCKS_PER_SEC);
//     free (array);

//     head_timer = NULL;
//     for (i = 0; i < elements; i++)
//         head_timer = insert_at_tail(&head_timer, i);
//     tic = clock();
//     for (i = 0; i < elements; i++)
//         head_timer = delete_at_head(&head_timer);        
//     toc = clock();
//     printf("Time elapsed for linked list: %f\n", (double)(toc - tic) / CLOCKS_PER_SEC);
//     head_timer = NULL;

//     printf("*****swap nodes******\n");
//     head9 = NULL;
//     for (i = 0; i < 15; i++)
//         head9 = insert_at_tail(&head9, i);
//     print_list(&head9);
//     head9 = swap_nodes(&head9, 0, 1);
//     print_list(&head9);
//     head9 = swap_nodes(&head9, 1, 0);
//     print_list(&head9);
//     head9 = swap_nodes(&head9, 0, 2);
//     print_list(&head9);
//     head9 = swap_nodes(&head9, 3, 0);
//     print_list(&head9);
//     head9 = swap_nodes(&head9, 1, 4);
//     print_list(&head9);
//     head9 = swap_nodes(&head9, 3, 8);
//     print_list(&head9);

//     printf("*****swap first two******\n");
//     head9 = swap_first_two(&head9);
//     print_list(&head9);

//     printf("*****move tail to head******\n");
//     head9 = move_tail_to_head(&head9);
//     print_list(&head9);

//     printf("*****move head to tail******\n");
//     head9 = move_head_to_tail(&head9);
//     print_list(&head9);

//     printf("*****swap data******\n");
//     swap_data(&head9, &head9->next);
//     print_list(&head9);

//     printf("*****delete memory******\n");
//     // delete_list_memory(&head);
//     // delete_list_memory(&head2);
//     // delete_list_memory(&head3);
//     head = delete_list(head);
//     head2 = delete_list(head2);
//     head3 = delete_list(head3);
//     // head4 = delete_list(head4);
//     // head5 = delete_list(head5);
//     head6 = delete_list(head6);
//     head7 = delete_list(head7);
//     head9 = delete_list(head9);
//     print_list(&head);
//     print_list(&head2);
//     print_list(&head3);
//     printf("*/*/*/*/*/*/*program end*/*/*/*/*/*/*/*\n");
//     return (0);
// }
// 