/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** map_loading_exceptions.c
*/

#include <stdbool.h>
#include <unistd.h>
#include "../../includes/my.h"

bool err_invalid_line_size(void)
{
    my_puterr(
        "setting_up: invalid line size, all lines must be the same length\n");
    return false;
}

bool err_incorrect_lines(int nb_rows, int line_count)
{
    my_puterr("setting_up: Incorrect number of lines, expected ");
    my_puterr_nbr(nb_rows);
    my_puterr(" but got ");
    my_puterr_nbr(line_count);
    my_puterr(
        " please set the first line of the file to the correct value.\n");
    return false;
}

bool err_invalid_character(char a, int line_count)
{
    my_puterr("setting_up: Invalid character '");
    write(2, &a, 1);
    my_puterr("' on line ");
    my_puterr_nbr(line_count);
    my_puterr(", a map can only be composed of '.' and 'o' (and "
        "return char).\n");
    return false;
}
