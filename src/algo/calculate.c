/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** calculate
*/

#include "../../include/n4s.h"

void calculate_average_distances(float *float_array,
float *right_avg, float *center_avg, float *left_avg)
{
    float right_sum = 0;
    float center_sum = 0;
    float left_sum = 0;

    for (int i = 0; i <= 10; i++)
        right_sum += float_array[i];
    for (int i = 11; i <= 20; i++)
        center_sum += float_array[i];
    for (int i = 21; i <= 31; i++)
        left_sum += float_array[i];

    *right_avg = right_sum / (10 - 0 + 1);
    *center_avg = center_sum / (20 - 11 + 1);
    *left_avg = left_sum / (31 - 21 + 1);
}

float calculate_speed(float distance)
{
    float normalized_distance = distance / 3010;
    float speed = MIN_SPEED + normalized_distance * (MAX_SPEED - MIN_SPEED);

    if (speed < MIN_SPEED)
        speed = MIN_SPEED;
    else
        speed = MAX_SPEED;

    return speed;
}
