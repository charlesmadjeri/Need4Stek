/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** algo
*/

#include "../../include/n4s.h"

float pid_update(pid_controller_t *pid, float error, float dt)
{
    float p_term, i_term, d_term;

    p_term = pid->kp * error;
    pid->integral += error * dt;
    i_term = pid->ki * pid->integral;
    d_term = pid->kd * (error - pid->prev_error) / dt;

    pid->prev_error = error;

    return p_term + i_term + d_term;
}

void algo(n4s_t *n4s)
{
    pid_controller_t pid = {PID_KP, PID_KI, PID_KD, 0, 0};
    float right_avg, center_avg, left_avg;
    float error, dt = 1.0, pid_output;

    while (1) {
        n4s->request = GET_INFO_LIDAR;
        while (get_info_lidar(n4s) != true);

        calculate_average_distances(n4s->answer->float_array,
        &right_avg, &center_avg, &left_avg);
        error = left_avg - right_avg;
        pid_output = pid_update(&pid, error, dt);

        check_and_drive_forward(n4s, 0, 0);
        set_wheel_direction(n4s, pid_output);
    }
}
