/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-sami.benkirane-saadi [WSL: Ubuntu]
** File description:
** commands
*/

#include "../include/n4s.h"

bool get_info(n4s_t *n4s, const char *command)
{
    char *response = send_command(command);

    if (!response)
        return false;

    n4s->answer->answer = strdup(response);
    parse_answer(n4s);
    return true;
}

bool post_with_value(n4s_t *n4s, const char *command, float value)
{
    char command_with_value[2048];
    char *response = NULL;
    size_t response_size = 0;

    sprintf(command_with_value, "%s:%.1f\n", command, value);
    my_putstr(command_with_value);

    if (getline(&response, &response_size, stdin) == -1) {
        free(response);
        return false;
    }
    response[strcspn(response, "\n")] = '\0';
    n4s->answer->answer = strdup(response);
    parse_answer(n4s);

    free(response);
    return true;
}
