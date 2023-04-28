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
    #include <time.h>
    #include <errno.h>
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

    #define LIDAR_CENTER 15
    #define LIDAR_LEFT 0
    #define LIDAR_RIGHT 31
    #define CLEAR_DISTANCE 150
    #define MAX_SPEED 0.1
    #define MIN_SPEED 0.001

// PID //
    #define PID_KP 1
    #define PID_KI 0.05
    #define PID_KD 0.01

// Structures //
    typedef struct {
        float kp;
        float ki;
        float kd;
        float prev_error;
        float integral;
    } pid_controller_t;

    enum request_e {
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
    };

    typedef struct get {
        char *command;
        char **command_array;

    } get_t;

    typedef struct answer {
        char *answer;
        char **answer_array;
        int format;
        int value_id;
        int status;
        char *code_str;
        char *additional_info;
        float float_value;
        float *float_array;
        long long long_value;
    } answer_t;

    typedef struct n4s {
        get_t *command;
        answer_t *answer;
        enum request_e request;
    } n4s_t;

// Prototypes //
    n4s_t *init_n4s(void);
    void free_n4s(n4s_t *n4s);

    void my_putstr(char const *str);

    char* send_command(const char* command);
    bool get_info(n4s_t *n4s, const char *command);

//  Parser //
    void parse_answer(n4s_t *n4s);
    void parse_answer_type_1(char *answer_string, answer_t *answer);
    void parse_answer_type_2(char *answer_string, answer_t *answer);
    void parse_answer_type_3(char *answer_string, answer_t *answer);
    void parse_answer_type_4(char *answer_string, answer_t *answer);

// Post //
    bool post_with_value(n4s_t *n4s, const char *command, float value);
    bool start_simulation(n4s_t *n4s);
    bool stop_simulation(n4s_t *n4s);
    bool car_forward(n4s_t *n4s, float value);
    bool car_backwards(n4s_t *n4s, float value);
    bool wheels_dir(n4s_t *n4s, float value);

// GET //
    bool get_info_lidar(n4s_t *n4s);
    bool get_current_wheels(n4s_t *n4s);
    bool cycle_wait(n4s_t *n4s);
    bool get_info_simtime(n4s_t *n4s);
    bool get_car_speed_min(n4s_t *n4s);
    bool get_current_speed(n4s_t *n4s);
    bool get_car_speed_max(n4s_t *n4s);

// Algo //
    void algo(n4s_t *n4s);
    float calculate_speed(float distance);
    void calculate_average_distances(float *float_array,
    float *right_avg, float *center_avg, float *left_avg);

    void check_and_drive_forward(n4s_t *n4s,
    float center_avg, float left_avg);
    void set_wheel_direction(n4s_t *n4s, float pid_output);

#endif /* !HEADER_H_ */
