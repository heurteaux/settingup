/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** load_and_find.c
*/

#include "../includes/internal_functions.h"
#include "../includes/my.h"
#include <stddef.h>

int load_and_find(char *file_path)
{
    char **map = map_to_memory(file_path);

    if (!map)
        return 84;
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return 0;
}
