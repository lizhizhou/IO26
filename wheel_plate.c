/*
 * wheel_plate.c
 *
 *  Created on: Apr 11, 2013
 *      Author: lizhizhou
 */
#include "platform.h"
#include "step_motor.h"
#include "position_sensor.h"
#define STEP_MOTOR            STEP_MOTOR_0
#define POSITITON_SENSNOR     POSITITON_SENSNOR_0
#define MAX_ANGLE             1024
#define NUMBER_OF_WINDOWS     16
void initial_wheel_plate(void)
{
    step_motor_init(STEP_MOTOR, 8000, 40);
    while(get_position(POSITITON_SENSNOR) !=0)
    {
        step_motor_move_step_forward(STEP_MOTOR);
    }
}

int set_wheel_plate_position(int angle)
{
    if(angle > MAX_ANGLE)
        return (0);
    while(get_position(POSITITON_SENSNOR) != angle)
    {
        step_motor_move_step_forward(STEP_MOTOR);
    }
    return (1);
}
