/*
 * brush_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */
#include "brush_motor.h"
#include "FPGA.h"
#define BRUSHMOTOR_CTRL_ADDRESS brushmotor_address//0x260
#define BRUSHMOTOR_ID            *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS)
#define BRUSHMOTOR_PWM_FREQUENCE *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+1)
#define BRUSHMOTOR_PWM_WIDTH     *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+2)
#define BRUSHMOTOR_ON_OFF        *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+3)
#define BRUSHMOTOR_FORWARD_BACK  *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+4)

const static int frequent   = 30000; // PWM frequence
const static int duty_cycle = 50;   // PWM duty_cycle

void brush_motor_init(void* brushmotor_address)
{
	BRUSHMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	BRUSHMOTOR_PWM_WIDTH = 0xFFFFFFFF / 100 * duty_cycle;
	BRUSHMOTOR_ON_OFF = 1; 
}

void brush_motor_forward(void* brushmotor_address)
{
	BRUSHMOTOR_FORWARD_BACK = 1;
}

void brush_motor_back(void* brushmotor_address)
{
	BRUSHMOTOR_FORWARD_BACK=0;
}

void brush_motor_ON(void* brushmotor_address)
{
	BRUSHMOTOR_ON_OFF = 1;
}

void brush_motor_OFF(void* brushmotor_address)
{
	BRUSHMOTOR_ON_OFF = 0;
}

void brush_motor_set_pwm(void* brushmotor_address, unsigned int pwm)
{
	BRUSHMOTOR_PWM_WIDTH = pwm;
}


