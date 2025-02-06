/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** search.c
*/

#include "secured.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int value_hash = ht->hash(key, ht->len_hashtable);
    int index = value_hash % ht->len_hashtable;
    node_t *current = ht->tab[index];

    while (current != NULL){
        if (value_hash == current->hash && my_strcmp(key, current->key) == 0){
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}
