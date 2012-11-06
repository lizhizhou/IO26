/*
 * Step_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou LI
 */
#include "Step_motor.h"
#include "FPGA.h"
#include <math.h>

#define STEPMOTOR_CTRL_ADDRESS 0x140
#define STEPMOTOR_CTRL_BASE    (STEPMOTOR_CTRL_ADDRESS/4)
#define STEPMOTOR_PWM_FREQUENCE *((volatile int*) FPGA_SYS_BASE+STEPMOTOR_CTRL_BASE)
#define STEPMOTOR_PWM_WIDTH_A   *((volatile int*) FPGA_SYS_BASE+STEPMOTOR_CTRL_BASE+1)
#define STEPMOTOR_PWM_WIDTH_B   *((volatile int*) FPGA_SYS_BASE+STEPMOTOR_CTRL_BASE+2)
#define STEPMOTOR_STEP          *((volatile int*) FPGA_SYS_BASE+STEPMOTOR_CTRL_BASE+3)
#define STEPMOTOR_FORWARD_BACK  *((volatile int*) FPGA_SYS_BASE+STEPMOTOR_CTRL_BASE+4)

const int frequent = 1000; // PWM frequence
const int duty_cycle =50;  // PWM duty_cycle

#define MAX_SUBDIVISION 0xFFFFFFFF

void Step_motor_init()
{
	STEPMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle;
}

void Step_motor_move_step_forward()
{
	STEPMOTOR_FORWARD_BACK=1;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
}

void Step_motor_move_step_back()
{
	STEPMOTOR_FORWARD_BACK=0;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
}

void Setp_motor_subdivision(unsigned int subdivision)
{
	subdivision &= MAX_SUBDIVISION;
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle - 0xFFFFFFFF * subdivision /2 / MAX_SUBDIVISION;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle + 0xFFFFFFFF * subdivision /2 / MAX_SUBDIVISION;	
}
