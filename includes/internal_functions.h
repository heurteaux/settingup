/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** internal_functions.h
*/

#include "data_structs.h"
#include <stdbool.h>

#pragma once

char *open_map_file(char *file_path);

int get_nb_cols(const char *file_content);

int get_nb_rows(char *file_content, int nb_cols);

int load_and_find(char *file_path);

char *clean_buffer(char *buffer);

char *map_from_file(char *file_path, int *nb_cols, int *nb_rows);

square get_max_square(char *map, int nb_cols, int nb_rows);

int read_int_pos(int *int_map, int x, int y, int nb_cols);

void reveal_square(square max_square, char *map, int nb_cols);

void write_char_pos(char *map, int x, int y, int nb_cols);

void display_map(char *map, int nb_rows, int nb_cols);

char *generate_map(int size, char *pattern);

int generate_and_find(char *square_size, char *pattern);

bool is_pattern_valid(char *pattern);

int invalid_square_size(void);

int invalid_pattern_size(void);

int invalid_pattern(void);

bool is_map_valid(char *map, int nb_rows, int nb_cols);

int invalid_line_size(void);
