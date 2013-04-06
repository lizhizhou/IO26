#include <stdio.h>
#include <unistd.h>

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
	microscope_up(200);
	microscope_down(200);
	microscope_left(500);
	microscope_right(500);
}

int main(int argn, char* argv[])
{
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

//	  syringe_test();
//	  AM2301_test();
//	  step_motmor_test();
	  microscope_test();
	  printf("done\n");
	  while(1) {
//		  Brush_motor_ON();
//		  fan_ON();
//		  Brush_motor_forward();
//		  getchar();
//		  Brush_motor_back();
//		  getchar();	`a
//		  Brush_motor_OFF();
//		  fan_OFF();
//		  getchar();
//		  printf("Position is %d\n",get_position());
//		  printf("Direction is %s\n",get_direction()?"forword":"backword");

	  }
	  fpga_close();
	  //trace_back();
	  return 0;
}
