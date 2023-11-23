/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** load_and_find.c
*/

#include <stdlib.h>
#include "../includes/internal_functions.h"

int load_and_find(char *file_path)
{
    square max_square;
    int nb_cols = 0;
    int nb_rows = 0;
    char *map = map_from_file(file_path, &nb_cols, &nb_rows);

    if (!map)
        return 84;
    max_square = get_max_square(map, nb_cols, nb_rows);
    reveal_square(max_square, map, nb_cols);
    display_map(map, nb_rows, nb_cols);
    free(map);
    return 0;
}
