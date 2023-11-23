/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** generate_and_find.c
*/

#include "../includes/data_structs.h"
#include "../includes/my.h"
#include "../includes/internal_functions.h"
#include <stdlib.h>
#include <stdio.h>

int generate_and_find(char *square_size, char *pattern)
{
    square max_square;
    int square_size_nb = my_getnbr(square_size);
    int nb_cols = square_size_nb;
    int nb_rows = square_size_nb;
    char *map = generate_map(my_getnbr(square_size), pattern);

    if (square_size_nb <= 0)
        return invalid_square_size();
    if (my_strlen(pattern) <= 0)
        return invalid_pattern_size();
    if (!is_pattern_valid(pattern)) {
        return invalid_pattern();
    }
    max_square = get_max_square(map, nb_cols, nb_rows);
    reveal_square(max_square, map, nb_cols);
    display_map(map, nb_rows, nb_cols);
    free(map);
    return 0;
}
