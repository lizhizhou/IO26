/*
 * Step_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou LI
 */
#include "step_motor.h"
#include "FPGA.h"
#include <unistd.h>
#include <math.h>
#define TIME_DELAY 5000
#define STEPMOTOR_CTRL_ADDRESS stepmotor_address
#define STEPMOTOR_PWM_FREQUENCE *((volatile int*) STEPMOTOR_CTRL_ADDRESS)
#define STEPMOTOR_PWM_WIDTH_A   *((volatile int*) STEPMOTOR_CTRL_ADDRESS+1)
#define STEPMOTOR_PWM_WIDTH_B   *((volatile int*) STEPMOTOR_CTRL_ADDRESS+2)
#define STEPMOTOR_STEP          *((volatile int*) STEPMOTOR_CTRL_ADDRESS+3)
#define STEPMOTOR_FORWARD_BACK  *((volatile int*) STEPMOTOR_CTRL_ADDRESS+4)

const int interval_time_us = 5000;
const int frequent = 1000; // PWM frequence
const int duty_cycle = 20;  // PWM duty_cycle

#define MAX_SUBDIVISION 0xFFFFFFFF

void step_motor_init(void* stepmotor_address)
{
	STEPMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle;
}

void step_motor_move_step_forward(void* stepmotor_address)
{
	STEPMOTOR_FORWARD_BACK=1;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
    usleep(TIME_DELAY);
}

void step_motor_move_step_back(void* stepmotor_address)
{
	STEPMOTOR_FORWARD_BACK=0;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
    usleep(TIME_DELAY);
}

void setp_motor_subdivision(void* stepmotor_address, unsigned int subdivision)
{
	subdivision &= MAX_SUBDIVISION;
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle - 0xFFFFFFFF * subdivision /2 / MAX_SUBDIVISION;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle + 0xFFFFFFFF * subdivision /2 / MAX_SUBDIVISION;	
}
