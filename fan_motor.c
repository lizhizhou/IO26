/*
 * fan_motor.c
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */

#include "fan_motor.h"
#include "FPGA.h"

#define FANMOTOR_CTRL_ADDRESS 0x2A0
#define FANMOTOR_CTRL_BASE    (FANMOTOR_CTRL_ADDRESS/4)
#define FANMOTOR_ID            *((volatile int*) FPGA_SYS_BASE+FANMOTOR_CTRL_BASE)
#define FANMOTOR_PWM_FREQUENCE *((volatile int*) FPGA_SYS_BASE+FANMOTOR_CTRL_BASE+1)
#define FANMOTOR_PWM_WIDTH     *((volatile int*) FPGA_SYS_BASE+FANMOTOR_CTRL_BASE+2)
#define FANMOTOR_ON_OFF        *((volatile int*) FPGA_SYS_BASE+FANMOTOR_CTRL_BASE+3)

const static int frequent   = 1000; // PWM frequence
const static int duty_cycle = 50;   // PWM duty_cycle

void fan_motor_init()
{
	FANMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	FANMOTOR_PWM_WIDTH = 0xFFFFFFFF / 100 * duty_cycle;
	FANMOTOR_ON_OFF = 1; 
}

void fan_ON()
{
	FANMOTOR_ON_OFF = 1; 
}

void fan_OFF()
{
	FANMOTOR_ON_OFF = 0; 
}

void fan_motor_set_pwm(unsigned int pwm)
{
	FANMOTOR_PWM_WIDTH = pwm;
}
