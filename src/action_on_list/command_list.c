/*
** EPITECH PROJECT, 2022
** command_list.c
** File description:
** command_list
*/

#include "pushswap.h"

void append (list_t * head, int val, long int signature)
{
    list_t * current = head -> prev;
    current -> next = malloc (sizeof(list_t));
    current -> next -> val = val;
    current -> next -> next = head;
    current -> next -> prev = current;
    head -> prev = current -> next;
    head -> signature = signature;
}

void inv_append (list_t ** head, int val, int signature)
{
    if ((*head) == NULL) {
        (*head) = malloc(sizeof(list_t));
        (*head) -> next = (*head);
        (*head) -> prev = (*head);
        (*head) -> val = val;
        (*head) -> signature = signature;
        return;
    }
    list_t * new_nb;
    new_nb = malloc(sizeof(list_t));
    new_nb -> val = val;
    new_nb -> next = *head;
    new_nb -> prev = (*head) -> prev;
    new_nb -> signature = signature;
    (*head) -> prev -> next = new_nb;
    (*head) -> prev = new_nb;
    *head = new_nb;
}

int pop (list_t ** head)
{
    if ((*head) -> next == (*head)) {
        free(*head);
        *head = NULL;
        return 0;
    }
    (*head) -> prev -> next = (*head) -> next;
    (*head) -> next -> prev = (*head) -> prev;
    int retval = -1;
    list_t * next_nb = NULL;
    if (*head == NULL) return -1;
    next_nb = (*head) -> next;
    retval = (*head) -> val;
    free(*head);
    *head = next_nb;
    return retval;
}
