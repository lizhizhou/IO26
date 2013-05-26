#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include "platform.h"
#include "PIO26.h"
#include "shield_ctrl.h"
#include "FPGA.h"
#include "AM2301.h"
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
	float i;
	if (!fpga_open()) {
		printf("FPGA open error\n");
		exit(1);
	}
	shield_ctrl_init();

//	coordinate_test();
//	{
//		int i;
//		cylindroid  c;
//	    microscope_init();
//		c.phi = 0;
//		c.r   = 1450;
//		c.z   = 0;
//		for(i = 0; i < 25 ; i++) {
//			micorscope_run_to_coordinates(rectangular_to_coordinates(cylindroid_to_rectangular(c)));
//			c.phi += angle_to_radian(14.4);
//			sleep(1);
//		}
//		c.phi = 0;
//		c.r   = 0;
//		c.z   = 0;
//		micorscope_run_to_coordinates(rectangular_to_coordinates(cylindroid_to_rectangular(c)));
//	}

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
//	while(1) {

//		printf("main loop wake up\n");
//		  Brush_motor_ON();
//		  fan_ON();
//		  Brush_motor_forward();
//		  getchar();
//		  Brush_motor_back();
//		  getchar();
//		  Brush_motor_OFF();
//		  fan_OFF();
//		  getchar();
//		  step_motor_move_step_forward(STEP_MOTOR_0);
//		  printf("Position is %d\n",get_position(POSITITON_SENSNOR_0));
//		  printf("Direction is %s\n",get_direction(POSITITON_SENSNOR_0)?"forword":"backword");

//  }
	fpga_close();
	//trace_back();
	return 0;
}
