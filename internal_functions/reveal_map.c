/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** reveal_map.c
*/

#include "../includes/data_structs.h"

void reveal_square(square max_square, char *map, int nb_cols)
{
    if (max_square.size == 0) {
        return;
    }
    for (int y = max_square.pos_y; y > max_square.pos_y - max_square.size;
        y--) {
        for (int x = max_square.pos_x; x > max_square.pos_x - max_square.size;
            x--) {
            map[y * (nb_cols + 1) + x] = 'x';
        }
    }
}
