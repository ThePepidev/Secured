/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** secured.h
*/

#ifndef SECURED
    #define SECURED

    #include "my.h"
    #include <unistd.h>

    typedef struct node_s {
        char *key;
        char *value;
        int hash;
        struct node_s *next;
    } node_t;

    typedef struct hashtable_s {
        node_t **tab;
        int (*hash)(char *, int);
        int len_hashtable;
    } hashtable_t;

int ht_insert(hashtable_t *ht, char *key, char *value);
#endif
