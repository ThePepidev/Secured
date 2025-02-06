/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont
** File description:
** secured.c
*/

#include "bootstrap.h"
#include "my.h"
#include <string.h>
#include <unistd.h>

void delete_address_book(entry_t **address_book, int len)
{
    for (int i = 0; i < len; i++) {
        if (!address_book[i])
            continue;
        free(address_book[i]);
    }
    free(address_book);
    printf("address book deleted\n");
}

entry_t *create_address(const char *name, const char *phone_number)
{
    entry_t *temp = malloc(sizeof(entry_t));

    if (!temp)
        return NULL;
    temp->name = name;
    temp->phone_number = phone_number;
    return temp;
}

void execute_on_address_book(entry_t **address_book, int len, void (*execute)(entry_t *))
{
    for (int i = 0; i < len; i++) {
        if (!address_book[i])
            continue;
        execute(address_book[i]);
    }
}

void dummy_function(entry_t *address)
{
    write (1, address->name, my_strlen(address->name));
    write (1, "\n", 1) ;
}

void add_address(entry_t **address_book,
    int len, const char *name, const char *phone_number)
{
    int i = 0;

    for (; i < len; i++) {
        if (!address_book[i])
            break;
    }
    if (i == len) {
        printf("add_address: not enough capacity to store new address\n");
        return;
    }
    address_book[i] = create_address(name, phone_number);
    printf("new address added\n");
}

entry_t **create_address_book(int len)
{
    entry_t **temp = malloc(sizeof(entry_t *) * (len + 1));
    int i = 0;

    if (!temp)
        return NULL;
    for (; i < len; i++)
        temp[i] = NULL;
    temp[i] = NULL;
    printf("address book created\n");
    return temp;
}
