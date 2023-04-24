/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** n4s
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <limits.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <math.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #pragma once

// Macros //

    #define START_SIMULATION 42
    #define CAR_FORWARD 43
    #define CAR_BACKWARDS 44
    #define WHEELS_DIR 45
    #define CYCLE_WAIT 46
    #define GET_INFO_LIDAR 47
    #define GET_CURRENT_SPEED 48
    #define GET_CURRENT_WHEELS 49
    #define GET_CAR_SPEED_MAX 50
    #define GET_CAR_SPEED_MIN 51
    #define GET_INFO_SIMTIME 52
    #define END_SIMULATION 53
    #define NONE 54

// Structures //

    typedef enum request_s {
        START_SIMULATION_E = START_SIMULATION,
        CAR_FORWARD_E = CAR_FORWARD,
        CAR_BACKWARDS_E = CAR_BACKWARDS,
        WHEELS_DIR_E = WHEELS_DIR,
        CYCLE_WAIT_E = CYCLE_WAIT,
        GET_INFO_LIDAR_E = GET_INFO_LIDAR,
        GET_CURRENT_SPEED_E = GET_CURRENT_SPEED,
        GET_CURRENT_WHEELS_E = GET_CURRENT_WHEELS,
        GET_CAR_SPEED_MAX_E = GET_CAR_SPEED_MAX,
        GET_CAR_SPEED_MIN_E = GET_CAR_SPEED_MIN,
        GET_INFO_SIMTIME_E = GET_INFO_SIMTIME,
        END_SIMULATION_E = END_SIMULATION,
        NONE_E = NONE
    } request_t;

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
        request_t request;
    } n4s;

// Prototypes //

//  Parser:
    void parse_answer(n4s *n4s);
    void parse_answer_type_1(char *answer_string, answer_t *answer);
    void parse_answer_type_2(char *answer_string, answer_t *answer);
    void parse_answer_type_3(char *answer_string, answer_t *answer);
    void parse_answer_type_4(char *answer_string, answer_t *answer);

#endif /* !HEADER_H_ */
