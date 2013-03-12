/*
 * brush_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */
#include "brush_motor.h"
#include "FPGA.h"
static unsigned int brushmotor_address;
#define BRUSHMOTOR_CTRL_ADDRESS brushmotor_address//0x260
#define BRUSHMOTOR_CTRL_BASE    (BRUSHMOTOR_CTRL_ADDRESS/4)
#define BRUSHMOTOR_ID            *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE)
#define BRUSHMOTOR_PWM_FREQUENCE *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+1)
#define BRUSHMOTOR_PWM_WIDTH     *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+2)
#define BRUSHMOTOR_ON_OFF        *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+3)
#define BRUSHMOTOR_FORWARD_BACK  *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+4)

const static int frequent   = 30000; // PWM frequence
const static int duty_cycle = 50;   // PWM duty_cycle

void select_brush_motor(unsigned int address)
{
    brushmotor_address = address;
}

void brush_motor_init()
{
	BRUSHMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	BRUSHMOTOR_PWM_WIDTH = 0xFFFFFFFF / 100 * duty_cycle;
	BRUSHMOTOR_ON_OFF = 1; 
}

void brush_motor_forward()
{
	BRUSHMOTOR_FORWARD_BACK = 1;
}

void brush_motor_back()
{
	BRUSHMOTOR_FORWARD_BACK=0;
}

void brush_motor_ON()
{
	BRUSHMOTOR_ON_OFF = 1;
}

void brush_motor_OFF()
{
	BRUSHMOTOR_ON_OFF = 0;
}

void brush_motor_set_pwm(unsigned int pwm)
{
	BRUSHMOTOR_PWM_WIDTH = pwm;
}


