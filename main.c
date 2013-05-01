#include <stdio.h>
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
#include "PID.h"
#include "debug.h"
#include "unit_test.h"

int main(int argn, char* argv[])
{
	float i;
    pthread_t pid;
	fpga_open();
	shield_ctrl_init();

	// Unit_test

//	syringe_test();
//	AM2301_test();
//	step_motmor_test();
//	wheel_plate_test();
//	PID_test();
    microscope_test();

	/*if(argn != 2) {
		printf("arg error\n");
		return 0;
	}
	printf(argv[1]);
	sscanf(argv[1],"%f", &i);
	printf("target is %0.2f%%\n", i);
    set_moisture_target(i);
	pthread_create(&pid, NULL, moisture_regulating_process, "moisture");*/
	printf("done\n");
	while(1) {

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

    }
	fpga_close();
	//trace_back();
	return 0;
}
