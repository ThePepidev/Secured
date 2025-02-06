/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont.git
** File description:
** hash.c
*/

#include "secured.h"

static int len_nbr(unsigned long number)
{
    int len = 0;

    if (number == 0)
        return 1;
    while (number >= 1) {
        number /= 10;
        len++;
    }
    return len;
}

static int len_nb_pointer(unsigned long *number)
{
    int len = 0;

    if (*number == 0)
        return 1;
    while (*number >= 1) {
        (*number) /= 10;
        len++;
    }
    return len;
}

static void copy_nbr(char *str, float nb_copy, int len_nb)
{
    int temp;
    int i = 0;

    for (; i < len_nb; i++) {
        temp = (int)nb_copy;
        nb_copy = (nb_copy - temp) * 10;
        str[i] = (nb_copy + 48);
    }
    str[i] = '\0';
}

static char *cast_to_str(unsigned long nb)
{
    unsigned long nb_copy = (unsigned long)nb;
    char *str;
    int len_nb = len_nb_pointer(&nb_copy);

    if (nb == 0)
        return "00";
    if (nb == 33)
        return "33";
    str = malloc(sizeof(char) * (len_nb + 1));
    if (!str)
        return NULL;
    copy_nbr(str, nb_copy, len_nb);
    return str;
}

int hash(char *key, int len)
{
    unsigned long temp = 4523;
    long hash = 4523;

    if (!key)
        return 84;
    for (int i = 0; key[i]; i++)
        hash = ((hash << 5) + hash) + key[i];
    while (len_nbr(hash) < len)
        hash += temp + (hash / 2);
    while (len_nbr(hash) > len)
        hash -= temp + (hash / 2);
    if (hash < 0)
        hash = -hash;
    key = cast_to_str(hash);
    return 0;
}
