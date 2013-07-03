/*
 * syringe.c
 *
 *  Created on: Jan 29, 2013
 *      Author: lizhizhou
 */
#include <unistd.h>
#include <stdio.h>
#include "platform.h"
#include "position_sensor.h"
#include "step_motor.h"
#define MM_PRE_STEP  2.65/100
#define STUCK_STEP 20
#define FAST_STEP  20
#define POSITITON_SENSNOR POSITITON_SENSNOR_3
#define STEP_MOTOR        STEP_MOTOR_3

static int syringe_stuck_check()
{
	return (0);
}

static int syringe_start=0;
static int syringe_target=0;
static int syringe_diameter=0;
void syringe_mark_start()
{
    syringe_start = get_position(POSITITON_SENSNOR);
}

void syringe_set_target(int m_litre, int u_litre)
{
    syringe_target = syringe_start -
    		m_litre;
    		//(1000* m_litre + u_litre) / syringe_diameter * MM_PRE_STEP;
}

void syringe_set_diameter(int m_meter)
{
    syringe_diameter = m_meter;
}

int syringe_run_forward()
{
    int i=0;
    int position = get_position(POSITITON_SENSNOR);
    printf("syringe_target = %d\n", syringe_target);
    while(position > syringe_target) {
    	printf("position = %d\n", position);
   	    step_motor_move_step_forward(STEP_MOTOR);
        if (get_position(POSITITON_SENSNOR) == position) {
        	i++;
        	if(i > STUCK_STEP)
        		return (0);
        } else {
        	i = 0;
        }
        position = get_position(POSITITON_SENSNOR);
    }
	printf("position = %d\n", position);
    return (1);
}

int syringe_run_back()
{
    int i=0;
    int position = get_position(POSITITON_SENSNOR);
    printf("syringe_target = %d\n", syringe_target);
    while(position > syringe_target) {
    	printf("position = %d\n", position);
    	step_motor_move_step_back(STEP_MOTOR);
        if (get_position(POSITITON_SENSNOR) == position) {
        	i++;
        	if(i > STUCK_STEP)
        		return (0);
        } else {
        	i = 0;
        }
        position = get_position(POSITITON_SENSNOR);
    }
	printf("position = %d\n", position);
    return (1);
}

int syringe_faster_forward()
{
	int i;
    int position = get_position(POSITITON_SENSNOR);
	for(i = 0; i < FAST_STEP; i++)
		step_motor_move_step_forward(STEP_MOTOR);
	printf("position = %d\n", position);
    if (get_position(POSITITON_SENSNOR) == position) {
    		return (0);
    }
    return (1);
}

int syringe_faster_back()
{
	int i;
    int position = get_position(POSITITON_SENSNOR);
	for(i = 0; i < FAST_STEP; i++)
		step_motor_move_step_back(STEP_MOTOR);
	printf("position = %d\n", position);
    if (get_position(POSITITON_SENSNOR) == position) {
    		return (0);
    }
    return (1);
}

unsigned int syringe_forward_step(unsigned int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_back(STEP_MOTOR);
        if (syringe_stuck_check())
        	return (step);
    }
    return (step);
}
unsigned int syringe_back_step(unsigned int step)
{
    int i;
    for(i = 0; i < step; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR);
        if (syringe_stuck_check())
        	return (step);
    }
    return (step);
}


void syringe_init()
{
    step_motor_init(STEP_MOTOR, 10000, 30);
}
