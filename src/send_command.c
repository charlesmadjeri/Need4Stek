/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-sami.benkirane-saadi [WSL: Ubuntu]
** File description:
** send_command
*/

#include "../include/n4s.h"

char* send_command_get(const char* command)
{
    my_putstr(command);

    char *response = NULL;
    size_t response_size = 0;

    if (getline(&response, &response_size, stdin) == -1) {
        free(response);
        return NULL;
    }

    response[strcspn(response, "\n")] = '\0';

    return response;
}

char* send_command_post(const char* command)
{
    my_putstr(command);

    char *response = NULL;
    size_t response_size = 0;

    if (getline(&response, &response_size, stdin) == -1) {
        free(response);
        return NULL;
    }

    response[strcspn(response, "\n")] = '\0';

    return response;
}
