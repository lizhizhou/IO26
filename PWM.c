/*
 * PWM.c
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */

#define PWM_CTRL_ADDRESS 0x260
#define PWM_CTRL_BASE    (BRUSHMOTOR_CTRL_ADDRESS/4)
#define PWM_ID            *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+1)
#define PWM_STATE         *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+3)
#define PWM_GATE          *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+3)
#define PWM_DUTYCYCLE     *((volatile int*) FPGA_SYS_BASE+BRUSHMOTOR_CTRL_BASE+4)

define IOA_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define IOA_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define IOA_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define IOA_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define IOA_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)

void PWM_init()
{
	PWM_STATE =
}
