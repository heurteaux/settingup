/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** map_check.c
*/

#include <stdbool.h>
#include "../../../includes/load_err_handling.h"

bool is_map_valid(char *map, int nb_rows, int nb_cols)
{
    int line_count = 0;
    int line_len_count = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '.' && map[i] != 'o' && map[i] != '\n')
            return err_invalid_character(map[i], line_count);
        if (map[i] == '\n' && line_len_count != nb_cols)
            return err_invalid_line_size();
        if (map[i] == '\n') {
            line_len_count = 0;
            line_count++;
            continue;
        }
        line_len_count++;
    }
    if (line_count < nb_rows)
        return err_incorrect_lines(nb_rows, line_count);
    return true;
}
