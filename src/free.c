/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** free
*/

#include "../include/n4s.h"

void free_n4s(n4s_t *n4s)
{
    for (int i = 0; n4s->answer->answer_array[i]; i++)
        free(n4s->answer->answer_array[i]);
    free(n4s->answer->answer);
    free(n4s->answer->answer_array);
    free(n4s->answer->additional_info);
    free(n4s->answer->code_str);
    free(n4s->answer->float_array);
    free(n4s->answer);
    free(n4s->command->command);
    for (int i = 0; n4s->command->command_array[i]; i++)
        free(n4s->command->command_array[i]);
    free(n4s->command->command_array);
    free(n4s->command);
    free(n4s);
}
