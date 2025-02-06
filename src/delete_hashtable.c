/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** delete_hashtable.c
*/

#include "hashtable.h"

static void free_node(node_t *current)
{
    node_t *temp = NULL;

    while (current != NULL) {
        temp = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = temp;
    }
}

void handle_free_node(hashtable_t *ht, int i)
{
    if (ht->tab[i] != NULL)
        free_node(ht->tab[i]);
}

void delete_hashtable(hashtable_t *ht)
{
    if (!ht)
        return;
    if (ht->tab) {
        for (int i = 0; i < ht->len_hashtable; i++)
            handle_free_node(ht, i);
        free(ht->tab);
    }
    free(ht);
}
