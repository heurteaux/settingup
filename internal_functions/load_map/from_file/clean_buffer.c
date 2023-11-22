/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** clean_buffer.c
*/

#include "../../../includes/my.h"

int get_first_line_size(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n' || buffer[i] != '\0') {
        i++;
    }
    return (i + 1);
}

char *clean_buffer(char *buffer)
{
    int first_line_size = get_first_line_size(buffer);

    return my_strdup(&buffer[first_line_size]);
}
