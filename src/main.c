/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** main
*/

#include "../include/n4s.h"

int main(int ac, char **av)
{
    n4s_t *n4s = init_n4s();

    n4s->request = START_SIMULATION;
    while (start_simulation(n4s) != true);
    algo(n4s);
    while (stop_simulation(n4s) != true);

    free_n4s(n4s);

    return 0;
}
