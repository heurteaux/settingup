/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** display_map.c
*/

#include "../includes/my.h"
#include <unistd.h>

void display_map(char *map, int nb_rows, int nb_cols)
{
    write(1, map, ((nb_rows + 1) * nb_cols - 1));
    my_putchar('\n');
}
