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

    typedef struct hashtable_s {
        long hash;
        char *name;
        int id;
        int len_hashtable;
        struct hashtable_s *next;
    } hashtable_t;

int ht_insert(hashtable_t *ht, char *key, char *value);
#endif
