/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

int check_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}
