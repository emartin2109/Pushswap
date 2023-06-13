/*
** EPITECH PROJECT, 2022
** utils_list.c
** File description:
** utils_list
*/

#include "pushswap.h"

int len_list (list_t * head)
{
    if (head == NULL) return 0;
    int i = 0;
    int retval = 1;
    list_t * current = head;
    while (current -> next != head) {
        retval++;
        current = current -> next;
    }
    return retval;
}

int len_list_signature (list_t * head, long int signature)
{
    if (head == NULL) return 0;
    int i = 0;
    int retval = 0;
    list_t * current = head;
    while (current -> next != head && current -> signature == signature) {
        if (current -> signature == signature)
            retval++;
        current = current -> next;
    }
    if (current -> signature == signature)
        retval++;
    return retval;
}
