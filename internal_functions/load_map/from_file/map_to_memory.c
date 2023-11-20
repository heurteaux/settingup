/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** map_to_memory.c
*/

#include <stdlib.h>
#include "../../../includes/internal_functions.h"

char **map_to_memory(char *file_path)
{
    char *file_content = open_map_file(file_path);
    map_to_memory_shortner *vars = create_map_to_memory_shortner(file_content);
    char **map;

    if (vars->nb_cols == (-1) || vars->nb_rows == (-1))
        return NULL;
    map = mem_alloc_2d_array(vars->nb_rows + 1, vars->nb_cols + 1);
    for (int i = 0; file_content[i] != '\0'; i++) {
        if (file_content[i] == '\n') {
            vars->loop_cols = 0;
            vars->loop_rows++;
            continue;
        }
        map[vars->loop_rows][vars->loop_cols] = file_content[i];
        vars->loop_cols++;
    }
    map[vars->loop_rows] = NULL;
    return &map[1];
}
