#include <stdio.h>
#include <stdlib.h>
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
#include "GUI.h"
#include "led.h"
#include "lcd.h"
#include "shell.h"
#include "panel.h"
int main(int argn, char* argv[])
{
	if (!fpga_open()) {
		printf("FPGA open error\n");
		exit(1);
	}
//	printf("PNL_ENCODER0 = 0x%x", PNL_ENCODER0);
//	qsys_serial_test();
//	shield_ctrl_init();
	pannel_init();
	cli();
	fpga_close();
	//trace_back();
	return 0;
}
