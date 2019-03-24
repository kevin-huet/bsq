/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "include/my.h"

void my_putstr(square_t *square, int i)
{
    write(1, square->array[i], square->x + 1);
}

void square_init(square_t *square)
{
    square->x = -1;
    square->y = 0;
    square->check = 0;
    square->compt = 0;
}

int cat(int ac, char **av, square_t square)
{
    int fd = open(av[1], O_RDONLY);
    char c;
    char *str = malloc(sizeof(char) * 12);
    do {
        square.i = read(fd, &c, 1);
        if (square.i == 0)
            return (84);
        if (c == '\n')
            square.check++;
        if (square.check == 1)
            square.x++;
        if (square.check == 0)
            str[square.compt++] = c;
    } while (square.check != 2);
    close(fd);
    if (check_number(str) == 1)
        return (84);
    square.y = my_getnbr(str);
    create_map(&square, av[1]);
    free(str);
    return (0);
}

int main(int ac, char **av)
{
    square_t square;
    if (open(av[1], O_RDONLY) == -1)
        return (84);
    else {
        square_init(&square);
        if (cat(ac, av, square) == 84)
            return (84);
    }
    return (0);
}
