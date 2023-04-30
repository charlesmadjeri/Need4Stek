/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** drive
*/

#include "../../include/n4s.h"

float clamp(float value, float min, float max)
{
    if (value < min)
        return min * 1.20;
    if (value > max)
        return max * 1.20;
    if (value < 1 && -1 < value)
        return value * 10;
    return value * 1.04;
}

void check_and_drive_forward(n4s_t *n4s,
float center_avg, float left_avg)
{
    if ((n4s->answer->float_array[LIDAR_CENTER] > CLEAR_DISTANCE) &&
        (n4s->answer->float_array[LIDAR_LEFT] > CLEAR_DISTANCE) &&
        (n4s->answer->float_array[LIDAR_RIGHT] > CLEAR_DISTANCE)) {
        float speed = calculate_speed(center_avg);
        n4s->request = CAR_FORWARD;
        while (car_forward(n4s, speed + 0.20) != true);
    }
}

void set_wheel_direction(n4s_t *n4s, float pid_output)
{
    float turn_value = -clamp(pid_output, -256, 256.0);
    n4s->request = WHEELS_DIR;
    while (wheels_dir(n4s, (turn_value / 1288)) != true);
}
