/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** delete.c
*/

#include "hashtable.h"

int check_previous(node_t **tab_index, node_t **previous, node_t **current)
{
    node_t *temp = *current;

    if (*previous == NULL)
        *tab_index = (*current)->next;
    else
        (*previous)->next = (*current)->next;
    free(temp->key);
    free(temp->value);
    free(temp);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int value_hash = 0;
    int index = 0;
    node_t *current = NULL;
    node_t *previous = NULL;

    if (!ht || !key || !ht->tab)
        return 84;
    value_hash = ht->hash(key, ht->len_hashtable);
    index = value_hash % ht->len_hashtable;
    current = ht->tab[index];
    while (current != NULL){
        if (value_hash == current->hash && my_strcmp(key, current->key) == 0)
            return check_previous(&(ht->tab[index]), &previous, &current);
        previous = current;
        current = current->next;
    }
    return 84;
}
