/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** insert.c
*/

#include "secured.h"

void insert_new_node(node_t **new_node, char *key, char *value
    , int value_hash)
{
    (*new_node)->key = my_strdup(key);
    (*new_node)->value = my_strdup(value);
    (*new_node)->hash = value_hash;
    (*new_node)->next = NULL;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int value_hash = ht->hash(key, ht->len_hashtable);
    int index = value_hash % ht->len_hashtable;
    node_t *current = ht->tab[index];
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node || !ht || !key || !value)
        return 84;
    while (current != NULL){
        if (current->hash == value_hash && my_strcmp(key, current->key) == 0){
            current->value = my_strdup(value);
            free(new_node);
            return 0;
        }
        current = current->next;
    }
    insert_new_node(&new_node, key, value, value_hash);
    new_node->next = ht->tab[index];
    ht->tab[index] = new_node;
    return 0;
}
