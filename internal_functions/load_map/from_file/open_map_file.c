/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** open_map_file.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../../../includes/data_structs.h"
#include "../../../includes/my.h"

char *open_map_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *buffer = NULL;
    struct stat *file_stats = malloc(sizeof(struct stat));

    if (fd == (-1)) {
        my_puterr("setting_up: Failed opening file.\n");
        return NULL;
    }
    stat(file_path, file_stats);
    buffer = malloc(sizeof(char) * file_stats->st_size);
    read(fd, buffer, file_stats->st_size);
    return buffer;
}
