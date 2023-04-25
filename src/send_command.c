/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-sami.benkirane-saadi [WSL: Ubuntu]
** File description:
** send_command
*/

#include "../include/my.h"

char* send_command(const char* command)
{
    fprintf(stdout, "%s\n", command);

    char response[2048];

    if (getline(response, sizeof(response), stdin) == NULL)
        return NULL;

    response[strcspn(response, "\n")] = '\0';

    return strdup(response);
}
