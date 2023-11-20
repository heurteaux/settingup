/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** struct_init.c
*/

#include <stdlib.h>
#include "../includes/data_structs.h"
#include "../includes/internal_functions.h"

map_to_memory_shortner *create_map_to_memory_shortner(char *file_content)
{
    map_to_memory_shortner *result =
        malloc(sizeof(map_to_memory_shortner) * 1);

    result->nb_cols = get_nb_cols(file_content);
    result->nb_rows = get_nb_rows(file_content, result->nb_cols);
    result->loop_rows = 0;
    result->loop_cols = 0;
    return result;
}
