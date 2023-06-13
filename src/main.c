/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "pushswap.h"

int glob_signature = 0;

list_t * reposition_pointer (list_t * current, int signature, char *to_print)
{
    if (current == NULL) return NULL;
    if (current -> signature != signature)
        while (current -> prev -> signature == signature) {
            write(1, to_print, 4);
            current = current -> prev;
        }
    return current;
}

int mid_point(list_t ** pt_head_1, list_t ** pt_head_2, int signature, int len)
{
    glob_signature++;
    list_t * current = (*pt_head_1);
    int i = 0;
    if (current == NULL) return 0;
    int mid_point = get_mid_point(current, signature);
    while (i < len) {
        if (current -> val <= mid_point) {
            write (1, "pb ", 3);
            inv_append(pt_head_2, current -> val, glob_signature);
            pop(&current);
        } else {
            write (1, "ra ", 3);
            current = current -> next;
        }
        i++;
    }
    *pt_head_1 = reposition_pointer(current, signature, "rra ");
    return signature;
}

int inv_mid_point(list_t ** pt_1, list_t ** pt_2, int signature, int len)
{
    glob_signature++;
    list_t * current = (*pt_1);
    if (current == NULL) return 0;
    int mid_point = get_mid_point(current, signature);
    int i = 0;
    while (i++ < len) {
        if (current -> val >= mid_point) {
            write (1, "pa ", 3);
            inv_append(pt_2, current -> val, glob_signature);
            pop(&current);
        } else {
            write (1, "rb ", 3);
            current = current -> next;
        }
    }
    *pt_1 = reposition_pointer(current, signature, "rrb ");
    return signature;
}

int sort_one_action (list_t * head_a)
{
    if (head_a -> next -> val < head_a -> val) {
        swap (&head_a -> val, &head_a -> next -> val);
        if (is_list_sorted(head_a)) {
            write (1, "sa", 2);
        } else {
            write (1, "sa ", 3);
        }
    }
}

int main (int argc, char ** argv)
{
    if (argc < 2) return 84;
    list_t * head_a = malloc(sizeof(list_t));
    head_a -> val = my_getnbr(argv[1]);
    head_a -> next = head_a;
    head_a -> prev = head_a;
    head_a -> signature = 0;
    get_l_a(argc, argv, head_a);
    sort_one_action(head_a);
    if (sorting_but_good(head_a)) {
        write (1, "sa ", 3);
        write (1, "sa", 2);
    }
    write(1, "\n", 1);
    return 0;
}
