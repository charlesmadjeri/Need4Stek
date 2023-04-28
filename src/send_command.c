/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-sami.benkirane-saadi [WSL: Ubuntu]
** File description:
** send_command
*/

#include "../include/n4s.h"

char* send_command(const char* command)
{
    char *response = NULL;

    my_putstr(command);
    size_t response_size = 0;
    if (getline(&response, &response_size, stdin) == -1) {
        free(response);
        return NULL;
    }
    response[strcspn(response, "\n")] = '\0';

    return response;
}
