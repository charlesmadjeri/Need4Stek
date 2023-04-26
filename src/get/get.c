/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** get
*/

#include "../../include/n4s.h"

bool get_info_lidar(n4s_t *n4s)
{
    return get(n4s, "GET_INFO_LIDAR\n");
}

bool get_current_wheels(n4s_t *n4s)
{
    return get(n4s, "GET_CURRENT_WHEELS\n");
}

bool cycle_wait(n4s_t *n4s)
{
    return get(n4s, "CYCLE_WAIT\n");
}

bool get_info_simtime(n4s_t *n4s)
{
    return get(n4s, "GET_INFO_SIMTIME\n");
}
