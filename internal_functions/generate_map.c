/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** generate_map.c
*/

#include <stdlib.h>
#include "../includes/my.h"

char *generate_map(int size, char *pattern)
{
    char *map = malloc(sizeof(char) * (size * (size + 1) + 2));
    int pattern_count = 0;

    for (int i = 0; i < (size * (size + 1) + 2); i++) {
        map[i] = 0;
    }
    for (int i = 1; i < (size * (size + 1)) + 1; i++) {
        if (i % (size + 1) == 0) {
            map[i - 1] = '\n';
            continue;
        }
        if (pattern_count == my_strlen(pattern)) {
            pattern_count = 0;
        }
        map[i - 1] = pattern[pattern_count];
        pattern_count++;
    }
    return map;
}
