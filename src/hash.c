/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont.git
** File description:
** hash.c
*/

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

int hash(char *key, int len)
{
    unsigned long temp = 4523;
    long hash = 4523;

    for (int i = 0; key[i]; i++)
        hash = ((hash << 5) + hash) + key[i];
    while (len_nbr(hash) < len) {
        hash += ((temp + hash) - hash / 2);
    }
    while (len_nbr(hash) > len) {
        hash -= ((temp + hash) - hash / 2);
    }
    if (hash < 0)
        hash = -hash;
    return hash;
}
