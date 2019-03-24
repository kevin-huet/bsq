/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

int check_number(char *str);
int my_getnbr(char *str);
int my_atoi(char *str, int i);
void create_map(square_t *square, char *str);
void my_putstr(square_t *square, int i);
void small_square(square_t *square);
