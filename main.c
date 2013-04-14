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
#include "debug.h"

void AM2301_test()
{
	while(1)
	{
		sleep(1);
		printf("Temperature is %.2f C", AM2301_get_temperature(AM2301_0));
		printf("\tTemperature is %.2f C\n", AM2301_get_temperature(AM2301_1));
		printf("Moisture is %.2f%%", AM2301_get_moisture(AM2301_0));
		printf("\tMoisture is %.2f%% \n", AM2301_get_moisture(AM2301_1));
	}
}

void syringe_test()
{
	syringe_init();
	//	while(syringe_faster_back());
	//	printf("syringe stuck\n");
	while(syringe_faster_forward());
	printf("syringe stuck\n");
	syringe_mark_start();
	syringe_set_target(200,0);
	syringe_run_back();
	printf("syringe done\n");
	sleep(5);
	syringe_mark_start();
	syringe_set_target(100,0);
	syringe_run_forward();
	printf("syringe done\n");
}

void step_motmor_test()
{
	int i;
	step_motor_init(STEP_MOTOR_0, 1100, 50);
	step_motor_init(STEP_MOTOR_1, 1100, 50);
	for(i = 0; i < 1000; i++) {
		step_motor_move_step_forward(STEP_MOTOR_0);
		step_motor_move_step_forward(STEP_MOTOR_1);
	}
	for(i = 0; i < 1000; i++) {
		step_motor_move_step_back(STEP_MOTOR_0);
		step_motor_move_step_back(STEP_MOTOR_1);
	}
}

void microscope_test()
{
	microscope_init();
	microscope_up(500);
	microscope_down(500);
	microscope_left(500);
	microscope_right(500);
}

void wheel_plate_test()
{
	int i;
	int position1 = get_position(POSITITON_SENSNOR_0);
	int position2;
	step_motor_init(STEP_MOTOR_0, 2000, 50);
	printf("p1 = %d\n", position1);
	for(i = 0; i < 20; i++)
		step_motor_move_step_forward(STEP_MOTOR_0);
	position2 = get_position(POSITITON_SENSNOR_0);
	printf("p2 = %d\n", position2);
	if (position2 - position1 > 1000)
		printf("moving step1 %d\n", position2 - 1000 - position1);
	else
		printf("moving step2 %d\n", position1 - position2);
}

int main(int argn, char* argv[])
{
	float i;
    pthread_t pid;
	fpga_open();
	shield_ctrl_init();
	AM2301_init(AM2301_0);
	AM2301_init(AM2301_1);
	brush_motor_init(BRUSH_MOTOR_0);
	brush_motor_init(BRUSH_MOTOR_1);
	brush_motor_back(BRUSH_MOTOR_1);
	brush_motor_init(BRUSH_MOTOR_2);
	brush_motor_init(BRUSH_MOTOR_3);
	fan_motor_init(FAN_MOTOR_0);
	//IOA_OE      = 0xffffffff;
	//IOB_OE      = 0xffffffff;
	// Unit_test
//	  syringe_test();
//    AM2301_test();
//	  step_motmor_test();
//	microscope_test();
//	  wheel_plate_test();
	printf(argv[1]);
	sscanf(argv[1],"%f", &i);
	printf("target is %0.2f%%\n", i);
    set_moisture_target(i);

	printf("done\n");
	pthread_create(&pid, NULL, moisture_regulating_process, "moisture");
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
