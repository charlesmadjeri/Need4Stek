/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-sami.benkirane-saadi [WSL: Ubuntu]
** File description:
** get_speed_info
*/

#include "../../include/n4s.h"

bool get_car_speed_max(n4s_t *n4s)
{
    return get(n4s, "GET_CAR_SPEED_MAX\n");
}

bool get_car_speed_min(n4s_t *n4s)
{
    return get(n4s, "GET_CAR_SPEED_MIN\n");
}

bool get_current_speed(n4s_t *n4s)
{
    return get(n4s, "GET_CURRENT_SPEED\n");
}
