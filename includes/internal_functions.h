/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** internal_functions.h
*/

#include "data_structs.h"

#pragma once

char *open_map_file(char *file_path);

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

int get_nb_cols(char *file_content);

int get_nb_rows(char *file_content, int nb_cols);

char **map_to_memory(char *file_path);

int load_and_find(char *file_path);

map_to_memory_shortner *create_map_to_memory_shortner(char *file_content);
