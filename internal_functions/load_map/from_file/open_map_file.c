/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** open_map_file.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../../../includes/my.h"

char *open_map_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *buffer = NULL;
    struct stat file_stats;

    if (fd == (-1)) {
        my_puterr("setting_up: Failed opening file.\n");
        return NULL;
    }
    stat(file_path, &file_stats);
    if (file_stats.st_size == 0) {
        my_puterr("setting_up: Failed reading file, cannot be empty\n");
        return NULL;
    }
    buffer = malloc(sizeof(char) * (file_stats.st_size + 1));
    for (int i = 0; i < (file_stats.st_size + 1); i++) {
        buffer[i] = 0;
    }
    read(fd, buffer, file_stats.st_size);
    return buffer;
}
