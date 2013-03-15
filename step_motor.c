/*
 * Step_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou LI
 */
#include "step_motor.h"
#include "FPGA.h"
#include <math.h>
#define STEPMOTOR_CTRL_ADDRESS stepmotor_address
#define STEPMOTOR_PWM_FREQUENCE *((volatile int*) STEPMOTOR_CTRL_ADDRESS)
#define STEPMOTOR_PWM_WIDTH_A   *((volatile int*) STEPMOTOR_CTRL_ADDRESS+1)
#define STEPMOTOR_PWM_WIDTH_B   *((volatile int*) STEPMOTOR_CTRL_ADDRESS+2)
#define STEPMOTOR_STEP          *((volatile int*) STEPMOTOR_CTRL_ADDRESS+3)
#define STEPMOTOR_FORWARD_BACK  *((volatile int*) STEPMOTOR_CTRL_ADDRESS+4)

const int frequent = 1000; // PWM frequence
const int duty_cycle =50;  // PWM duty_cycle

#define MAX_SUBDIVISION 0xFFFFFFFF

void step_motor_init(unsigned int stepmotor_address)
{
	STEPMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle;
}

void step_motor_move_step_forward(unsigned int stepmotor_address)
{
	STEPMOTOR_FORWARD_BACK=1;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
}

void step_motor_move_step_back(unsigned int stepmotor_address)
{
	STEPMOTOR_FORWARD_BACK=0;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
}

void setp_motor_subdivision(unsigned int stepmotor_address, unsigned int subdivision)
{
	subdivision &= MAX_SUBDIVISION;
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle - 0xFFFFFFFF * subdivision /2 / MAX_SUBDIVISION;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle + 0xFFFFFFFF * subdivision /2 / MAX_SUBDIVISION;	
}
