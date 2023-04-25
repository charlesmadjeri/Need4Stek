/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-sami.benkirane-saadi [WSL: Ubuntu]
** File description:
** commands
*/

#include "../include/n4s.h"

bool get(n4s_t *n4s, const char *command)
{
    char *response = send_command_get(command);
    if (!response)
        return false;
    n4s->answer = calloc(1, sizeof(answer_t));
    n4s->answer->answer = strdup(response);
    parse_answer(n4s);

    return true;
}

bool post(n4s_t *n4s, const char *command)
{
    char *response = send_command_post(command);

    if (!response)
        return false;

    n4s->answer = calloc(1, sizeof(answer_t));
    n4s->answer->answer = strdup(response);
    parse_answer(n4s);
    return true;
}

bool post_with_value(n4s_t *n4s, const char *command, float value)
{
    char command_with_value[2048];

    sprintf(command_with_value, "%s:%.2f\n", command, value);

    my_putstr(command_with_value);

    char response[2048];
    if (getline(response, sizeof(response), stdin) == NULL)
        return false;

    response[strcspn(response, "\n")] = '\0';

    n4s->answer = calloc(1, sizeof(answer_t));
    n4s->answer->answer = strdup(response);
    parse_answer(n4s);

    return true;
}
