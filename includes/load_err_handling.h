/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** gen_err_handling.h
*/

#pragma once

#include <stdbool.h>

int err_invalid_line_size(void);

bool err_incorrect_lines(int nb_rows, int line_count);

bool err_invalid_character(char a, int line_count);
