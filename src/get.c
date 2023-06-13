/*
** EPITECH PROJECT, 2022
** get.c
** File description:
** get
*/

#include "pushswap.h"

int get_max_value (list_t * head, int signature)
{
    list_t * current = head;
    int max_value = current -> val;
    while (current -> next != head && current -> signature == signature) {
        if (current -> val > max_value) max_value = current -> val;
        current = current -> next;
    }
    if (current -> val > max_value && current -> signature == signature)
        max_value = current -> val;
    return max_value;
}

int get_min_value (list_t * head, int signature)
{
    list_t * current = head;
    int min_value = current -> val;
    while (current -> next != head) {
        if (current -> val < min_value && current -> signature == signature)
            min_value = current -> val;
        current = current -> next;
    }
    if (current -> val < min_value && current -> signature == signature)
        min_value = current -> val;
    return min_value;
}

int get_min_value2 (list_t * head, int max, int signature)
{
    list_t * current = head;
    int min_value = get_max_value(head, signature);
    while (current -> next != head) {
        if (current -> val < min_value && current -> val > max &&
        current -> signature == signature)
            min_value = current -> val;
        current = current -> next;
    }
    if (current -> val < min_value && current -> val > max &&
    current -> signature == signature)
        min_value = current -> val;
    return min_value;
}

int get_mid_point (list_t * head, int signature)
{
    if (head == NULL) return 0;
    long long int sum = 0;
    int i = 0;
    list_t * current = head;
    while (current -> next != head &&
    current -> next -> signature == signature) {
        sum += current -> val;
        i++;
        current = current -> next;
    }
    sum += current -> val;
    i++;
    return sum / i;
}

void get_l_a(int size, char ** av, list_t * head)
{
    int i = 2;
    while (av[i]) {
        append(head, my_getnbr(av[i]), 0);
        i++;
    }
}
