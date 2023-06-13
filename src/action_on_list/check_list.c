/*
** EPITECH PROJECT, 2022
** check_list.c
** File description:
** check_list
*/

#include "pushswap.h"

int is_sorted (list_t * head, int signature)
{
    list_t * current = head;
    if (current == NULL) return 1;
    int preval = current -> val;
    while (current -> signature == signature && current -> next != head) {
        if (preval > current -> val) return 0;
        preval = current -> val;
        current = current -> next;
    }
    if (preval > current -> val) return 0;
    return 1;
}

int is_list_sorted(list_t * head)
{
    list_t * current = head;
    if (current == NULL) return 1;
    int preval = current -> val;
    while (current -> next != head) {
        if (preval > current -> val) return 0;
        preval = current -> val;
        current = current -> next;
    }
    if (preval > current -> val) return 0;
    return 1;
}
