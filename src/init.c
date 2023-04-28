/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** init
*/

#include "../include/n4s.h"

static answer_t *init_answer(void)
{
    answer_t *answer = malloc(sizeof(answer_t));

    answer->status = 0;
    answer->answer_array = malloc(sizeof(char *) * 6);
    for (int i = 0; i < 6; i++)
        answer->answer_array[i] = NULL;
    answer->answer = NULL;
    answer->additional_info = NULL;
    answer->code_str = NULL;

    answer->float_value = 0;
    answer->float_array = malloc(sizeof(float) * 32);
    for (int i = 0; i < 32; i++)
        answer->float_array[i] = 0;
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

n4s_t *init_n4s(void)
{
    n4s_t *n4s = malloc(sizeof(n4s_t));

    n4s->answer = init_answer();
    n4s->command = init_command();
    n4s->request = NONE;

    return n4s;
}
