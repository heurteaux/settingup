/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** handle_gen_exceptions.c
*/

#include <stdbool.h>
#include "../../includes/my.h"

bool is_pattern_valid(char *pattern)
{
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] != '.' && pattern[i] != 'o') {
            return false;
        }
    }
    return true;
}

int invalid_square_size(void)
{
    my_puterr("setting_up: invalid square size, must be a strictly positive "
        "number\n");
    return 84;
}

int invalid_pattern_size(void)
{
    my_puterr("setting_up: invalid pattern size, must be at least 1 character "
        "long\n");
    return 84;
}

int invalid_pattern(void)
{
    my_puterr("setting_up: invalid pattern, must be composed only of '.' and "
        "'o' characters (ex: \"..o..\")\n");
    return 84;
}
