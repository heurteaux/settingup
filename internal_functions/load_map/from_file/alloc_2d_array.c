/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** alloc_2d_array.c
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **result = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++) {
        result[i] = malloc(sizeof(char) * nb_cols);
    }
    return result;
}
