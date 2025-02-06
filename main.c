/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-mathys1.dupont.git
** File description:
** main.c
*/

#include "bootstrap.h"
#include "my.h"
#include <unistd.h>

int main(void)
{
    int size = 5;
    entry_t **address_book = create_address_book(size);

    add_address(address_book, size, "Kevin ", " +33 6 45 12 87 11 02") ;
    add_address(address_book, size, "Jonathan ", " +33 6 74 91 48 12 04");
    add_address(address_book, size, "Cyril ", " +33 7 64 99 01 00 06");
    add_address(address_book, size, "Leo ", " +33 7 65 19 98 71 08 ");
    add_address(address_book, size, "Gildas ", " +33 6 45 67 89 90 10 ");
    add_address(address_book, size, "<3 ", " +33 6 07 08 09 00 12 "); // There 's no slot left for you </3
    write (STDOUT_FILENO, "\nExecute on addresses :\n", my_strlen("\nExecute on addresses :\n"));
    execute_on_address_book(address_book, size, &dummy_function);
    write (STDOUT_FILENO, "\nDelete addresses :\n",my_strlen("\nDelete addresses :\n"));
    delete_address_book(address_book, size);
    return 0;
}