/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** search.c
*/

#include "hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int value_hash = 0;
    int index = 0;
    node_t *current = NULL;

    if (!ht || !key || !ht->tab)
        return NULL;
    value_hash = ht->hash(key, ht->len_hashtable);
    index = value_hash % ht->len_hashtable;
    current = ht->tab[index];
    while (current != NULL){
        if (value_hash == current->hash && my_strcmp(key, current->key) == 0){
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}
