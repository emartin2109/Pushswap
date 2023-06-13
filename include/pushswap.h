/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** .h
*/

#ifndef PUSHSWAP_H_
    #define PUSHSWAP_H_

    #include <unistd.h>
    #include <stdlib.h>

typedef struct list {
    long int signature;
    int val;
    struct list * next;
    struct list * prev;
} list_t;

// check_list.c
int is_sorted (list_t * head, int signature);
int is_list_sorted(list_t * head);

// command_list.c
void append (list_t * head, int val, long int signature);
void inv_append (list_t ** head, int val, int signature);
int pop (list_t ** head);

// get.c
int get_max_value (list_t * head, int signature);
int get_min_value (list_t * head, int signature);
int get_min_value2 (list_t * head, int max, int signature);
int get_mid_point (list_t * head, int signature);
void get_l_a(int size, char ** av, list_t * head);

// main.c
int mid_point(list_t ** pt_head_1, list_t ** pt_head_2, int signature, int len);
int inv_mid_point(list_t ** pt_1, list_t ** pt_2, int signature, int len);

// sort.c
int sort_restrictive (list_t ** pt_1, list_t** pt_2, int signature);
list_t * inv_sort_restrictive (list_t ** pt_1, list_t** pt_2, int signature);
int sorting_but_good (list_t * current_a);

// utils_list.c
int len_list (list_t * head);
int len_list_signature (list_t * head, long int signature);

// utils.c
void swap (int *a , int * b);
int my_getnbr (char const *str);

#endif /* !PUSHSWAP_H_ */
