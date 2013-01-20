/*
 * position_sensor.c
 *
 *  Created on: 2012-10-30
 *      Author: Zhizhou Li
 */

#include "FPGA.h"

#define POSITITON_SENSOR_ADDRESS 0x280
#define POSITITON_SENSOR_ADDRESS_BASE           (POSITITON_SENSOR_ADDRESS / 4)
#define POSITITON_SENSOR_ADDRESS_ID             *((volatile int*) (FPGA_SYS_BASE+POSITITON_SENSOR_ADDRESS_BASE))
#define POSITITON_SENSOR_ADDRESS_POSTITION    *((volatile int*) (FPGA_SYS_BASE+POSITITON_SENSOR_ADDRESS_BASE+1))
#define POSITITON_SENSOR_ADDRESS_DIRECTION    *((volatile int*) (FPGA_SYS_BASE+POSITITON_SENSOR_ADDRESS_BASE+2))

int get_position()
{
	return POSITITON_SENSOR_ADDRESS_POSTITION;
}

int get_direction()
{
	return POSITITON_SENSOR_ADDRESS_DIRECTION;
}
