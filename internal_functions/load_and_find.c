/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** load_and_find.c
*/

#include "../includes/internal_functions.h"
#include "../includes/my.h"
#include <stddef.h>
#include <stdio.h>

int load_and_find(char *file_path)
{
    char **map = map_to_memory(file_path);

    if (!map) {
        my_puterr("setting_up: Failed reading file.\n");
        return 84;
    }
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s\n", map[i]);
    }
    return 0;
}
