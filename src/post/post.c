/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** get_info
*/

#include "../../include/n4s.h"

bool start_simulation(n4s_t *n4s)
{
    return get_info(n4s, "START_SIMULATION\n");
}

bool stop_simulation(n4s_t *n4s)
{
    return get_info(n4s, "STOP_SIMULATION\n");
}

bool car_forward(n4s_t *n4s, float value)
{
    return post_with_value(n4s, "CAR_FORWARD", value);
}

bool car_backwards(n4s_t *n4s, float value)
{
    return post_with_value(n4s, "CAR_BACKWARDS", value);
}

bool wheels_dir(n4s_t *n4s, float value)
{
    return post_with_value(n4s, "WHEELS_DIR", value);
}
