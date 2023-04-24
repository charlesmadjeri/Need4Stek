/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** post
*/

#include "../../include/n4s.h"

// Ask format:

// START_SIMULATION - (1)
// STOP_SIMULATION - (1)
// CAR_FORWARD:float [0;1] (1)
// CAR_BACKWARDS:float [0;1] (1)
// WHEELS_DIR:float [-1;1] (1)

bool start_simulation(n4s *n4s);
bool stop_simulation(n4s *n4s);
bool car_forward(n4s *n4s); // Between 0 and 1
bool car_backwards(n4s *n4s); // Between 0 and 1
bool wheels_dir(n4s *n4s); // Between -1 and 1
