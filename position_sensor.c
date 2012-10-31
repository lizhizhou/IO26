/*
 * position_sensor.c
 *
 *  Created on: 2012-10-30
 *      Author: Zhizhou Li
 */

#include "FPGA.h"

#define POSITITON_SENSOR_ADDRESS 0x260
#define POSITITON_SENSOR_ADDRESS_BASE    (POSITITON_SENSOR_ADDRESS / 4)
#define POSITITON_SENSOR_ADDRESS_ID      *((volatile int*) (FPGA_SYS_BASE+POSITITON_SENSOR_ADDRESS_BASE))
#define POSITITON_SENSOR_ADDRESS_DATA    *((volatile int*) (FPGA_SYS_BASE+POSITITON_SENSOR_ADDRESS_BASE+1))

int get_position()
{
	return POSITITON_SENSOR_ADDRESS_DATA;
}


