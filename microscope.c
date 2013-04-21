/*
 * microscope.c
 *
 *  Created on: Mar 26, 2013
 *      Author: lizhizhou
 */
#include <unistd.h>
#include <stdio.h>
#include "platform.h"
#include "position_sensor.h"
#include "step_motor.h"
#define STEP_MOTOR_X        STEP_MOTOR_0
#define STEP_MOTOR_Y        STEP_MOTOR_1
static int get_edge_sensor()
{
    return (0);
}
void microscope_init()
{
	step_motor_init(STEP_MOTOR_X, 8000, 30);
	step_motor_init(STEP_MOTOR_Y, 8000, 30);
}

int microscope_up(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_Y);
        if (get_edge_sensor())
        	return (0);
    }
    return (1);
}
int microscope_down(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_Y);
        if (get_edge_sensor())
        	return (0);
    }
    return (1);
}
int microscope_left(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_X);
        if (get_edge_sensor())
        	return (0);
    }
    return (1);
}
int microscope_right(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_X);
        if (get_edge_sensor())
        	return (0);
    }
    return (1);
}

void microscope_calibration(void)
{

}
