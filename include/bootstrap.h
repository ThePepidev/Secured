/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured Bootstrap
** File description:
** bootstrap.h
*/

#ifndef BOOTSTRAP_H
    #define BOOTSTRAP_H

    #include <stdio.h>
    #include <stdlib.h>

typedef struct entry_s {
    char *name;
    char *phone_number;
} entry_t;

entry_t **create_address_book(int len);
entry_t *create_address(const char *name, const char *phone_number);
void add_address(entry_t **address_book, int len, const char *name, const char *phone_number);
void dummy_function(entry_t *address);
void execute_on_address_book(entry_t **address_book, int len, void (*execute)(entry_t *));
void delete_address_book(entry_t **address_book, int len);

#endif /* BOOTSTRAP_H */