/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** insert.c
*/

#include "hashtable.h"

void insert_new_node(node_t **new_node, char *key, char *value
    , int value_hash)
{
    (*new_node)->key = my_strdup(key);
    (*new_node)->value = my_strdup(value);
    (*new_node)->hash = value_hash;
    (*new_node)->next = NULL;
}

int free_new_node(node_t *new_node)
{
    if (!new_node){
        free(new_node);
        return 84;
    }
    return 0;
}

int update_existing_node(node_t *current,
    char *key, char *value, int value_hash)
{
    while (current != NULL) {
        if (current->hash == value_hash && my_strcmp(key, current->key) == 0) {
            current->value = my_strdup(value);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int value_hash = 0;
    int index = 0;
    node_t *current = NULL;
    node_t *new_node = malloc(sizeof(node_t));

    if (!ht || !key || !value || free_new_node(new_node) == 84)
        return 84;
    value_hash = ht->hash(key, ht->len_hashtable);
    index = value_hash % ht->len_hashtable;
    current = ht->tab[index];
    if (update_existing_node(current, key, value, value_hash)) {
        free(new_node);
        return 0;
    }
    insert_new_node(&new_node, key, value, value_hash);
    new_node->next = ht->tab[index];
    ht->tab[index] = new_node;
    return 0;
}
