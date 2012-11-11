/*
 * PWM.c
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */

#define PWM_CTRL_ADDRESS 0x260
#define PWM_CTRL_BASE    (BRUSHMOTOR_CTRL_ADDRESS/4)
#define PWM_ID            *((volatile int*) FPGA_MOD_BASE+BRUSHMOTOR_CTRL_BASE+1)
#define PWM_STATE         *((volatile int*) FPGA_MOD_BASE+BRUSHMOTOR_CTRL_BASE+3)
#define PWM_GATE          *((volatile int*) FPGA_MOD_BASE+BRUSHMOTOR_CTRL_BASE+3)
#define PWM_DUTYCYCLE     *((volatile int*) FPGA_MOD_BASE+BRUSHMOTOR_CTRL_BASE+4)

#define PWM_RESET         *((volatile char*) PWM_STATE
#define PWM_OUT_INV       *((volatile char*) PWM_STATE+1)
#define PWM_DUTYCYCLE_EN  *((volatile char*) PWM_STATE+2)
#define PWM_GATE_EN       *((volatile char*) PWM_STATE+3)

void PWM_init()
{
	PWM_RESET   = 0;
	PWM_OUT_INV = 0;
}

void PWM_SET_GATE(unsigned int gate)
{
	PWM_GATE    = gate;
}

void PWM_SET_DUTY_CYCLE(unsigned int duty)
{

	PWM_DUTYCYCLE = duty;
}