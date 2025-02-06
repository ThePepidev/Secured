/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** insert.c
*/

#include "secured.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int nb_ht = ht->hash % ht->len_hashtable;

    while (ht != NULL){
        if (ht->id == nb_ht){
            ht->hash = (long)key;
            ht->name = value;
            return 0;
        }
        ht = ht->next;
    }
    return 84;
}
