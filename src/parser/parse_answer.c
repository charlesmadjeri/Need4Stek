/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** parse_answer
*/

#include "../../include/n4s.h"

void parse_answer_type_1(char *answer_string, answer_t *answer)
{
    char *token = strtok(answer_string, ":");
    if (token == NULL)
        return;
    answer->value_id = atoi(token);
    token = strtok(NULL, ":");
    if (token == NULL)
        return;
    answer->status = atoi(token);
    token = strtok(NULL, ":");
    if (token == NULL)
        return;
    answer->code_str = strdup(token);
    token = strtok(NULL, "\n");
    if (token == NULL)
        return;
    answer->additional_info = strdup(token);
    answer->format = 1;
}

void parse_answer_type_2(char *answer_string, answer_t *answer)
{
    char *token = strtok(answer_string, ":");
    if (token == NULL)
        return;
    answer->value_id = atoi(token);
    token = strtok(NULL, ":");
    answer->status = atoi(token);
    token = strtok(NULL, ":");
    answer->code_str = strdup(token);
    for (int i = 0; i < 32; i++) {
        token = strtok(NULL, ":");
        if (token == NULL)
            break;
        answer->float_array[i] = atof(token);
        if (i == 0)
            answer->float_value = answer->float_array[0];
    }
    token = strtok(NULL, "\n");;
    answer->additional_info = strdup(token);
    answer->format = 2;
}

void parse_answer_type_3(char *answer_string, answer_t *answer)
{
    char *token = strtok(answer_string, ":");
    if (token == NULL)
        return;
    answer->value_id = atoi(token);
    token = strtok(NULL, ":");
    if (token == NULL)
        return;
    answer->status = atoi(token);
    token = strtok(NULL, ":");
    if (token == NULL)
        return;
    answer->code_str = strdup(token);
    token = strtok(NULL, ":");
    if (token == NULL)
        return;
    answer->float_value = atof(token);
    token = strtok(NULL, "\n");
    answer->additional_info = strdup(token);
    answer->format = 3;
}

void parse_answer_type_4(char *answer_string, answer_t *answer)
{
    char *token = strtok(answer_string, ":");
    if (token == NULL)
        return;
    answer->value_id = atoi(token);
    token = strtok(NULL, ":");
    if (token == NULL)
        return;
    answer->status = atoi(token);
    token = strtok(NULL, ":");
    answer->code_str = strdup(token);
    token = strtok(NULL, ",");
    answer->long_value = atol(token);
    token = strtok(NULL, "]");
    token++;
    answer->long_value = atol(token);
    token = strtok(NULL, "\n");
    answer->additional_info = strdup(token);
    answer->format = 4;
}
