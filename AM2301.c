/*
 * AM2301.c
 *
 *  Created on: Oct 26, 2012
 *      Author: lizhizhou
 */
#include "FPGA.h"

#define AM2301_ADDRESS 0x220
#define AM2301_BASE    (AM2301_ADDRESS / 4)
#define AM2301_ID      *((volatile int*) (FPGA_SYS_BASE+AM2301_BASE+1))
#define AM2301_DATA    *((volatile int*) (FPGA_SYS_BASE+AM2301_BASE+3))
#define AM2301_READY   *((volatile int*) (FPGA_SYS_BASE+AM2301_BASE+4))

void AM2301_init()
{
	  short temperature_data;
	  float temperature;
	  short moisture_data;
	  float moisture;
	  printf("AM2301 ID   =0x%x\n", AM2301_ID);
	  printf("AM2301_DATA =0x%x\n", AM2301_DATA);
	  printf("AM2301_READY=0x%x\n", AM2301_READY);
	  moisture_data    =  AM2301_DATA >> 16;
	  printf("moisture_data=%d\n", moisture_data);
	  moisture     = moisture_data/10.0;
	  printf("Moisture=%.1f%%\n", moisture);
	  temperature_data = 0xffff & AM2301_DATA;
	  temperature  = temperature_data/10.0;
	  printf("Temperature=%.1fC\n", temperature);
}
