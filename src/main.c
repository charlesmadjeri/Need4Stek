/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** main
*/

#include "../include/n4s.h"

static void drive(n4s_t *n4s)
{
    while(1) {
        // Go forward
        n4s->request = CAR_FORWARD;
        while (car_forward(n4s, CAR_RIGHT_SPEED) != true);
        n4s->request = GET_INFO_LIDAR;
    
        // Get info lidar
        while(get_info_lidar(n4s) != true);
    
        // Check if the car is blocked
        if (n4s->answer->float_array[15] > 1000)
            n4s->request = CAR_FORWARD;
        else
            n4s->request = CAR_BACKWARDS;
        
        // Turn
        if (n4s->answer->float_array[0] < n4s->answer->float_array[31]) {
            n4s->request = WHEELS_DIR;
            while (wheels_dir(n4s, 0.005) != true);
        } else if (n4s->answer->float_array[0] == n4s->answer->float_array[31]) {
            n4s->request = WHEELS_DIR;
            while (wheels_dir(n4s, 0) != true);
        } else {
            n4s->request = WHEELS_DIR;
            while (wheels_dir(n4s, -0.005) != true);
        }
    }

}

void algo(n4s_t *n4s)
{
    n4s->request = START_SIMULATION;
    while (start_simulation(n4s) != true);

    drive(n4s);
    while(stop_simulation(n4s) != true);
}

int main(int ac, char **av)
{
    n4s_t *n4s = init_n4s();

    algo(n4s);
    free_n4s(n4s);

    return 0;
}
