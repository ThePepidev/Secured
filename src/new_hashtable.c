/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** new_hashtable.c
*/

#include "hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new_hash = malloc(sizeof(hashtable_t));

    if (!len || len == 0 || !hash || !new_hash)
        return NULL;
    new_hash->len_hashtable = len;
    new_hash->hash = hash;
    new_hash->tab = malloc(sizeof(node_t) * len);
    if (!new_hash->tab){
        free(new_hash->tab);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        new_hash->tab[i] = NULL;
    return new_hash;
}
