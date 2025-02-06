/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** secured.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include "my.h"
    #include <unistd.h>
    #include <stdio.h>

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
int hash(char *key, int len);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
int ht_delete(hashtable_t *ht, char *key);
void delete_hashtable(hashtable_t *ht);

#endif /* HASHTABLE_H */
