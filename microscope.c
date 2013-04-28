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
#define STEP_MOTOR_Z        STEP_MOTOR_2
int current_x;
int current_y;
int current_z;
static int get_edge_sensor_x_plus()
{
	//return (IOB_IO_16);
    return (0);
}
static int get_edge_sensor_x_minus()
{
	//return (IOB_IO_17);
    return (0);
}
static int get_edge_sensor_y_plus()
{
    return (0);
}
static int get_edge_sensor_y_minus()
{
    return (0);
}
static int get_edge_sensor_z_plus()
{
    return (0);
}
static int get_edge_sensor_z_minus()
{
    return (0);
}

static int get_infrared_sensor()
{
    return (0);
}

void microscope_init()
{
	step_motor_init(STEP_MOTOR_X, 10000, 30);
	step_motor_init(STEP_MOTOR_Y, 10000, 30);
	step_motor_init(STEP_MOTOR_Z, 10000, 30);
}

int microscope_x_plus(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_X);
        if (get_edge_sensor_x_plus())
        	return (step);
    }
    return (step);
}
int microscope_x_minus(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_X);
        if (get_edge_sensor_x_minus())
        	return (step);
    }
    return (step);
}
int microscope_y_plus(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_Y);
        if (get_edge_sensor_y_plus())
        	return (step);
    }
    return (step);
}
int microscope_y_minus(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_Y);
        if (get_edge_sensor_y_minus())
        	return (step);
    }
    return (step);
}
int microscope_z_plus(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_Z);
        if (get_edge_sensor_z_plus())
        	return (step);
    }
    return (step);
}
int microscope_z_minus(int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_Z);
        if (get_edge_sensor_z_minus())
        	return (step);
    }
    return (step);
}
void microscope_calibration(void)
{
    get_infrared_sensor();
}

void microscope_manual_calibration_on(void)
{
    step_motor_off(STEP_MOTOR_X);
    step_motor_off(STEP_MOTOR_Y);
    step_motor_off(STEP_MOTOR_Z);
}

void microscope_manual_calibration_off(void)
{
    step_motor_on(STEP_MOTOR_X);
    step_motor_on(STEP_MOTOR_Y);
    step_motor_on(STEP_MOTOR_Z);
}

void micorscope_run_to_coordinates(int x, int y, int z)
{

}

void micorscope_set_zero(void)
{

}
