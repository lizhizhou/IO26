#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include "platform.h"
#include "PIO26.h"
#include "PIO8.h"
#include "shield_ctrl.h"
#include "FPGA.h"
#include "AM2301.h"
#include "sht1x.h"
#include "position_sensor.h"
#include "step_motor.h"
#include "brush_motor.h"
#include "fan_motor.h"
#include "syringe.h"
#include "microscope.h"
#include "moisture.h"
#include "temperature.h"
#include "PID.h"
#include "debug.h"
#include "unit_test.h"

int main(int argn, char* argv[])
{
	int i = 0;
	if (!fpga_open()) {
		printf("FPGA open error\n");
		exit(1);
	}
	getchar();
	//qsys_serial_test();
	shield_ctrl_init();
	PORT0_OE   = 0xff;
	usleep(50);
	PORT0_DATA = 0x00;
	usleep(50);
	printf("PORT0_ID is 0x%x\n", PORT0_ID);
	printf("PORT0_OE is 0x%x\n", PORT0_OE);
	printf("PORT0_DATA is 0x%x\n", PORT0_DATA);
	getchar();
	PORT0_DATA = 0x01;
	usleep(50);
	printf("PORT0_ID is 0x%x\n", PORT0_ID);
	printf("PORT0_OE is 0x%x\n", PORT0_OE);
	printf("PORT0_DATA is 0x%x\n", PORT0_DATA);
//	sht1x_init(SHT1X_0);
	cli();
	/*if(argn != 2) {
		printf("arg error\n");
		return 0;
	}
	printf(argv[1]);
	sscanf(argv[1],"%f", &i);
	printf("target is %0.2f%%\n", i);
    init_moisture_subsystem(i);
	printf("done\n");*/
	//subdivision_step_motor_test();
	while(1) {
		printf("Temp %.2fC Mois %.2f%%\n\n", sht1x_get_temperature(SHT1X_0),
				sht1x_get_moisture(SHT1X_0));
		printf("Temp %.2fC Mois %.2f%%\n\n", sht1x_get_temperature(SHT1X_1),
				sht1x_get_moisture(SHT1X_1));
		sleep(1);
		printf("main loop wake up\n");

    }
	fpga_close();
	//trace_back();
	return 0;
}
