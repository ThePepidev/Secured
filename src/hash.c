/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont.git
** File description:
** hash.c
*/

#include "hashtable.h"

int hash(char *key, int len)
{
    unsigned long hash = 5381;

    if (!key || len == 0 || !len)
        return -1;
    for (int i = 0; key[i]; i++)
        hash = ((hash << 5) + hash) + key[i];
    hash = (hash * len) + len;
    hash = hash % __INT32_MAX__;
    return (int)hash;
}
