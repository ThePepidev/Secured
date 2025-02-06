/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** delete.c
*/

#include "hashtable.h"

void check_previous(node_t **previous, node_t **current)
{
    if (*previous == NULL)
        *current = (*current)->next;
    else
        (*previous)->next = (*current)->next;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int value_hash = ht->hash(key, ht->len_hashtable);
    int index = value_hash % ht->len_hashtable;
    node_t *current = ht->tab[index];
    node_t *previous = NULL;

    if (!ht || !key || !ht->tab)
        return 84;
    while (current != NULL){
        if (value_hash == current->hash && my_strcmp(key, current->key) == 0){
            check_previous(&previous, &current);
            free(current->key);
            free(current->value);
            free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return 84;
}
