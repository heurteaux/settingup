/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** get_max_square.c
*/

#include <stdlib.h>
#include "../includes/data_structs.h"
#include "../includes/internal_functions.h"

int *int_map_from_file(const char *map, int nb_rows, int nb_cols)
{
    int *int_map = malloc(sizeof(int) * (nb_rows * nb_cols + 1));
    int count = 0;

    for (int i = 0; i < (nb_rows * nb_cols + 1); i++) {
        int_map[i] = 0;
    }
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'o') {
            int_map[count] = 0;
            count++;
        }
        if (map[i] == '.') {
            int_map[count] = 1;
            count++;
        }
    }
    return int_map;
}

int get_int_map_index_val(int x, int y, int *int_map, int nb_cols)
{
    int top_left_val = read_int_pos(int_map, x - 1, y - 1, nb_cols);
    int left_val = read_int_pos(int_map, x - 1, y, nb_cols);
    int top_val = read_int_pos(int_map, x, y - 1, nb_cols);

    if (top_left_val <= left_val && top_left_val <= top_val) {
        return top_left_val + 1;
    } else if (left_val <= top_left_val && left_val <= top_val) {
        return left_val + 1;
    } else {
        return top_val + 1;
    }
}

static void ponder_map_cond(int x, int y, int *int_map, int nb_cols)
{
    if (read_int_pos(int_map, x, y, nb_cols) != 0 && x > 0 && y > 0) {
        int_map[y * nb_cols + x] =
            get_int_map_index_val(x, y, int_map, nb_cols);
    }
}

void ponder_map(int *int_map, int nb_cols, int nb_rows)
{
    for (int y = 0; y < nb_rows; y++) {
        for (int x = 0; x < nb_cols; x++) {
            ponder_map_cond(x, y, int_map, nb_rows);
        }
    }
}

square find_greatest_value_int_map(int *int_map, int nb_cols, int nb_rows)
{
    square max_result;

    max_result.size = 0;
    max_result.pos_x = 0;
    max_result.pos_y = 0;
    for (int i = 0; i < nb_rows * nb_cols; i++) {
        if (int_map[i] > max_result.size) {
            max_result.size = int_map[i];
            max_result.pos_x = i % nb_cols;
            max_result.pos_y = i / nb_rows;
        }
    }
    return max_result;
}

square get_max_square(char *map, int nb_cols, int nb_rows)
{
    square result;
    int *int_map = int_map_from_file(map, nb_rows, nb_cols);

    ponder_map(int_map, nb_cols, nb_rows);
    result = find_greatest_value_int_map(int_map, nb_cols, nb_rows);
    free(int_map);
    return result;
}
