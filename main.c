/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** main.c
*/

#include "includes/my.h"
#include "includes/internal_functions.h"

const char *ERR_MSG = "setting_up: Invalid number of arguments.\n";

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3) {
        my_puterr((char *) ERR_MSG);
        return 84;
    }
    if (argc == 2) {
        return load_and_find(argv[1]);
    }
    if (argc == 3) {
        return 84;
    }
    return 0;
}
