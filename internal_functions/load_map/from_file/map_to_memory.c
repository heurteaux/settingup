/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** map_to_memory.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../../includes/my.h"
#include "../../../includes/internal_functions.h"

bool is_valid_map_character(char a)
{
    return (a == 'o' || a == '.');
}

static int file_content_to_array(
    char const *file_content, map_to_memory_shortner *vars, char **map)
{
    for (int i = 0; file_content[i] != '\0'; i++) {
        if (file_content[i] == '\n') {
            vars->loop_cols = 0;
            vars->loop_rows++;
            continue;
        }
        if (!is_valid_map_character(file_content[i]) && vars->loop_rows > 0) {
            my_puterr("setting_up: Illegal character on map file at line ");
            my_puterr_nbr(vars->loop_rows);
            my_puterr(".\n");
            return 1;
        }
        map[vars->loop_rows][vars->loop_cols] = file_content[i];
        vars->loop_cols++;
    }
    map[vars->loop_rows] = NULL;
    return 0;
}

char **map_to_memory(char *file_path)
{
    char *file_content = open_map_file(file_path);
    map_to_memory_shortner *vars = create_map_to_memory_shortner(file_content);
    char **map;

    if (!file_content)
        return NULL;
    if (vars->nb_cols == (-1) || vars->nb_rows == (-1)) {
        my_puterr("setting_up: Failed reading file.\n");
        return NULL;
    }
    map = mem_alloc_2d_array(vars->nb_rows + 1, vars->nb_cols + 1);
    if (file_content_to_array(file_content, vars, map) == 1)
        map = NULL;
    if (!map) {
        return NULL;
    }
    return &map[1];
}
