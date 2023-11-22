/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** int_map_manipulation.c
*/

int read_int_pos(int *int_map, int x, int y, int nb_cols)
{
    int index = y * nb_cols + x;

    return int_map[index];
}

void write_char_pos(char *map, int x, int y, int nb_cols)
{
    int index = y * nb_cols + x;

    map[index] = 'x';
}
