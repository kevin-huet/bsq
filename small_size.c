/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "include/my.h"

void my_putchar(char *str)
{
    write(1, str, 2);
}

void one_char(square_t *square)
{
    if (square->array[0][0] == 'o')
        my_putchar(square->array[0]);
    if (square->array[0][0] == '.') {
        square->array[0][0] = 'x';
        my_putchar(square->array[0]);
    }
}

void small_square(square_t *square)
{
    if (square->x == 1 && square->y == 1)
        one_char(square);
}
