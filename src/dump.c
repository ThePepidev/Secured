/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** dump.c
*/

#include "hashtable.h"

void ht_dump(hashtable_t *ht)
{
    int i = 0;
    node_t *current = NULL;

    if (!ht || !ht->tab)
        return;
    while (ht->len_hashtable > i){
        current = ht->tab[i];
        mini_printf("[%d]:\n", i);
        while (current != NULL){
            mini_printf("> %d - %s\n", current->hash, current->value);
            current = current->next;
        }
        i++;
    }
}
