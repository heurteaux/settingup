/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** map_check.c
*/

#include <stdbool.h>
#include <unistd.h>
#include "../../../includes/my.h"

static void err_incorrect_lines(int nb_rows, int line_count)
{
    my_puterr("setting_up: Incorrect number of lines, expected ");
    my_puterr_nbr(nb_rows);
    my_puterr(" but got ");
    my_puterr_nbr(line_count);
    my_puterr(
        " please set the first line of the file to the correct value.\n");
}

static void err_invalid_character(char a, int line_count)
{
    my_puterr("setting_up: Invalid character '");
    write(2, &a, 1);
    my_puterr("' on line ");
    my_puterr_nbr(line_count);
    my_puterr(", a map can only be composed of '.' and 'o' (and "
        "return char).\n");
}

bool is_map_valid(char *map, int nb_rows)
{
    int line_count = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '.' && map[i] != 'o' && map[i] != '\n') {
            err_invalid_character(map[i], line_count);
            return false;
        }
        if (map[i] == '\n')
            line_count++;
    }
    if (line_count < nb_rows) {
        err_incorrect_lines(nb_rows, line_count);
        return false;
    }
    return true;
}
