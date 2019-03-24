/*
** EPITECH PROJECT, 2018
** fz
** File description:
** f
*/

#include "include/my.h"

int value(int a, int b, int c, int d)
{
    int res = 0;
    int res2 = 0;
    int res3 = 0;
    if (b > a)
        res = a;
    else
        res = b;
    if (c < res)
        res2 = c;
    else
        res2 = res;
    res3 = res2 + d;
    return (res3);
}

void print_square(square_t *square, vector_t pos, int max)
{
    for (int i = pos.y; i != pos.y - max; i--) {
        for (int j = pos.x; j != pos.x - max; j--)
            square->array[i][j] = 'x';
    }
    square->array[pos.y][pos.x] = 'x';
    for (int i = 0; i != square->y; i++)
        my_putstr(square, i);
}

void find_square(square_t *square)
{
    vector_t pos = {0, 0};
    int temp = 0;
    for (int i = 1; i != square->y; i++) {
        for (int j = 1; j != square->x; j++) {
            if (square->convert[i][j] > 0) {
                square->convert[i][j] =
                    value(square->convert[i][j - 1], square->convert[i - 1][j],
                          square->convert[i - 1][j - 1], square->convert[i][j]);
                if (temp < square->convert[i][j]) {
                    temp = square->convert[i][j];
                    pos.x = j;
                    pos.y = i;
                }
            }
        }
    }
    print_square(square, pos, temp);
}

void convert_map(square_t *square)
{
    for (int i = 0; i != square->y; i++) {
        for (int j = 0; j != square->x; j++) {
            if (square->array[i][j] == '.')
                square->convert[i][j] = 1;
            if (square->array[i][j] == 'o')
                square->convert[i][j] = 0;
        }
    }
    if (square->y == 1 && square->x == 1) {
        small_square(square);
    }
    else
        find_square(square);
    free(square->convert);
}

void create_map(square_t *square, char *str)
{
    char c;
    int compt = 0;
    int fd = open(str, O_RDONLY);
    for (; c != '\n';)
        read(fd, &c, 1);
    square->array = malloc(sizeof(char *) * square->y + 1);
    square->convert = malloc(sizeof(int *) * square->y + 1);
    for (int i = 0; i != square->y + 1; i++) {
        square->convert[i] = malloc(sizeof(int) * square->x + 1);
        square->array[i] = malloc(sizeof(char) * square->x + 1);
}
    for (int i = 0; i != square->y; i++) {
        read(fd, square->array[compt], square->x + 1);
        square->array[compt++][square->x + 1] = '\0';
    }
    convert_map(square);
    free(square->array);
    close(fd);
}
