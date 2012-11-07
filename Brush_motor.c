/*
 * Brush_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */
#include "Brush_motor.h"
#include "FPGA.h"

#define BRUSHMOTOR_CTRL_ADDRESS 0x140
#define BRUSHMOTOR_CTRL_BASE    (BRUSHMOTOR_CTRL_ADDRESS/4)
#define BRUSHMOTOR_ID *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE)
#define BRUSHMOTOR_PWM_FREQUENCE *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+1)
#define BRUSHMOTOR_PWM_WIDTH     *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+2)
#define BRUSHMOTOR_FORWARD_BACK  *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+3)
#define BRUSHMOTOR_ON_OFF        *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+4)

const static int frequent = 1000; // PWM frequence
const static int duty_cycle =50;  // PWM duty_cycle

void Brush_motor_init()
{
	BRUSHMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	BRUSHMOTOR_PWM_WIDTH = 0xFFFFFFFF / 100 * duty_cycle;
	BRUSHMOTOR_ON_OFF = 1; 
}

void Brush_motor_forward()
{
	BRUSHMOTOR_FORWARD_BACK=1;
}

void Brush_motor_back()
{
	BRUSHMOTOR_FORWARD_BACK=0;
}
