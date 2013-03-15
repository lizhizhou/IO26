/*
 * AM2301.c
 *
 *  Created on: Oct 26, 2012
 *      Author: lizhizhou
 */
#include "FPGA.h"
#define AM2301_ADDRESS AM2301_address//0x220
#define AM2301_ID      *((volatile int*) (AM2301_address+1))
#define AM2301_DATA    *((volatile int*) (AM2301_address+3))
#define AM2301_READY   *((volatile int*) (AM2301_address+4))

void AM2301_init(unsigned int AM2301_address)
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
