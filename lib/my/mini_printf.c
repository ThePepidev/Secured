/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"

int detect_display(const char *format, int *i, va_list args)
{
    if (format[*i] == '%' && format[*i + 1] == '%'){
        my_putchar('%');
        (*i)++;
    }
    if (format[*i] == '%'){
        if (format[*i + 1] == 'd' || format[*i + 1] == 'i'){
            my_put_nbr(va_arg(args, int));
            (*i)++;
        }
        if (format[*i + 1] == 's'){
            my_putstr(va_arg(args, char *));
            (*i)++;
        }
        if (format[*i + 1] == 'c'){
            my_putchar((char)va_arg(args, int));
            (*i)++;
        }
    } else
        my_putchar(format[*i]);
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++){
        detect_display(format, &i, args);
    }
    va_end(args);
    return 0;
}
