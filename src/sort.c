/*
** EPITECH PROJECT, 2022
** sort.c
** File description:
** sort
*/

#include "pushswap.h"

int sort_restrictive (list_t ** pt_1, list_t** pt_2, int signature)
{
    list_t * current = (*pt_1);
    int len = 0;
    while (!is_sorted(current, signature)
    && (len = len_list_signature(current, signature)) > 2) {
        mid_point(&current, pt_2, signature, len);
    }
    if (len_list_signature(current, signature) > 0) {
        if (current -> val > current -> next -> val) {
            write (1, "sa ", 3);
            swap(&current -> val, &current -> next -> val);
        }
    }
    *pt_1 = current;
}

list_t * inv_sort_restrictive (list_t ** pt_1, list_t** pt_2, int signature)
{
    list_t * current = (*pt_1);
    int len = 0;
    while ((len = len_list_signature(current, signature)) > 2) {
        inv_mid_point(&current, pt_2, signature, len);
        if ((*pt_2) -> val > (*pt_2) -> next -> val) {
            write(1, "sa ", 3); swap(&(*pt_2) -> val, &(*pt_2) -> next -> val);
        }
        if (!is_sorted((*pt_2), (*pt_2) -> signature))
            sort_restrictive(pt_2, &current, (*pt_2) -> signature);
        if (current) signature = current -> signature;
    }
    if (!current) return (*pt_1 = current);
    while (current -> signature == signature) {
        write (1, "pa ", 3);
        inv_append(pt_2, current -> val, signature); pop(&current);
        if (current == NULL) break;
    }
    if (!is_sorted((*pt_2), (*pt_2) -> signature))
        sort_restrictive(pt_2, &current, (*pt_2) -> signature);
    *pt_1 = current;
}

int sorting_but_good (list_t * current_a)
{
    list_t * current_b = NULL;
    if (!is_sorted(current_a, current_a -> signature)) {
        sort_restrictive (&current_a, &current_b, current_a -> signature);
    } else {
        return 0;
    }
    while (current_b) {
        inv_sort_restrictive (&current_b, &current_a, current_b -> signature);
    }
    return 1;
}
