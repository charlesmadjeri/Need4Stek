/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** header
*/

#ifndef HEADER_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <limits.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <math.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #pragma once

// Macros:
// Structures:
    enum request {
        START_SIMULATION,
        CAR_FORWARD,
        CAR_BACKWARDS,
        WHEELS_DIR,
        CYCLE_WAIT,
        GET_INFO_LIDAR,
        GET_CURRENT_SPEED,
        GET_CURRENT_WHEELS,
        GET_INFO_SIMTIME,
        END_SIMULATION,
        NONE
    };

    typedef struct get_s {
        char *command;
        char **command_array;

    } get_t;

    typedef struct answer_s {
        char *answer;
        char **answer_array;
        int format;
        int value_id;
        int status;
        char *code_str;
        char *additional_info;
        float float_value;
        long long long_value;
    } answer_t;

    typedef struct n4s_s {
        get_t *command;
        answer_t *answer;
        enum request *request;
    } n4s;

// Prototypes:

#define HEADER_H_


#endif /* !HEADER_H_ */
