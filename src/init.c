/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** init
*/

#include "../include/n4s.h"
#include <stdlib.h>

static answer_t *init_answer(void)
{
    answer_t *answer = malloc(sizeof(answer_t));

    answer->answer = malloc(sizeof(char *));
    answer->status = 0;
    answer->answer_array = malloc(sizeof(char *) * 6);
    answer->additional_info = malloc(sizeof(char *));
    answer->code_str = malloc(sizeof(char *));
    answer->float_value = 0;
    answer->long_value = 0;
    answer->value_id = 0;
    answer->format = 0;
    answer->status = 0;

    return answer;
}

static get_t *init_command(void)
{
    get_t *command = malloc(sizeof(get_t));

    command->command = malloc(sizeof(char *));
    command->command_array = malloc(sizeof(char *) * 2);

    return command;
}

static enum request_e init_request(void)
{
    enum request_e *request = malloc(sizeof(enum request_e));

    *request = NONE;

    return *request;
}

n4s_t *init_n4s(void)
{
    n4s_t *n4s = malloc(sizeof(n4s_t));

    n4s->answer = init_answer();
    n4s->command = init_command();
    n4s->request = init_request();

    return n4s;
}
