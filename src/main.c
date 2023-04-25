/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** main
*/

#include "../include/n4s.h"

static void drive(n4s_t *n4s)
{

}

void algo(n4s_t *n4s)
{
    n4s->request = START_SIMULATION;
    while (start_simulation(n4s) != true)
        start_simulation(n4s);
    drive(n4s);

}

int main(int ac, char **av)
{
    n4s_t *n4s = init_n4s();

    algo(n4s);

    return 0;
}
