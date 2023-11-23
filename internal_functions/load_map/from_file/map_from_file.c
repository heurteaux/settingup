/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** map_from_file.c
*/

#include "../../../includes/internal_functions.h"
#include "../../../includes/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

char *file_content_to_map(char *file_content)
{
    char *map;
    int i = 0;

    while (file_content[i] != '\n' && file_content[i] != '\0') {
        i++;
    }
    i++;
    map = my_strdup(&file_content[i]);
    free(file_content);
    return map;
}

char *map_from_file(char *file_path, int *nb_cols, int *nb_rows)
{
    char *file_content = open_map_file(file_path);

    *nb_cols = get_nb_cols(file_content);
    *nb_rows = get_nb_rows(file_content, *nb_cols);
    if (*nb_cols == (-1) || *nb_rows == (-1)) {
        my_puterr("setting_up : failed reading file\n");
        return NULL;
    }
    return file_content_to_map(file_content);
}
