/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** parser
*/

#include "../../include/n4s.h"

void parse_other_answer(n4s_t *n4s)
{
    switch ((int)n4s->request) {
        case GET_CURRENT_SPEED:
            parse_answer_type_3(n4s->answer->answer, n4s->answer);
        case GET_CURRENT_WHEELS:
            parse_answer_type_3(n4s->answer->answer, n4s->answer);
        case GET_CAR_SPEED_MAX:
            parse_answer_type_3(n4s->answer->answer, n4s->answer);
        case GET_CAR_SPEED_MIN:
            parse_answer_type_3(n4s->answer->answer, n4s->answer);
        case CYCLE_WAIT:
            parse_answer_type_4(n4s->answer->answer, n4s->answer);
        case GET_INFO_SIMTIME:
            parse_answer_type_4(n4s->answer->answer, n4s->answer);
    }
}

void parse_answer(n4s_t *n4s)
{
    switch ((int)n4s->request) {
        case START_SIMULATION:
            parse_answer_type_1(n4s->answer->answer, n4s->answer);
        case END_SIMULATION:
            parse_answer_type_1(n4s->answer->answer, n4s->answer);
        case CAR_FORWARD:
            parse_answer_type_1(n4s->answer->answer, n4s->answer);
        case CAR_BACKWARDS:
            parse_answer_type_1(n4s->answer->answer, n4s->answer);
        case WHEELS_DIR:
            parse_answer_type_1(n4s->answer->answer, n4s->answer);
        case GET_INFO_LIDAR:
            parse_answer_type_2(n4s->answer->answer, n4s->answer);
    }
    parse_other_answer(n4s);
}
