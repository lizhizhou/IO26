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
#include "debug.h"


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
	  step_motor_init(STEP_MOTOR_0);
	  step_motor_init(STEP_MOTOR_1);
	  //IOA_OE      = 0xffffffff;
	  //IOB_OE      = 0xffffffff;
//	  syringe_mark_start();
//	  syringe_set_target(50, 0);
//	  syringe_run_forward();
//	  syringe_run_back();
	  printf("syringe done\n");
	  while(1) {
//		  Brush_motor_ON();
//		  fan_ON();
//		  Brush_motor_forward();
//		  getchar();
//		  Brush_motor_back();
//		  getchar();
//		  Brush_motor_OFF();
//		  fan_OFF();
//		  getchar();
//		  printf("Position is %d\n",get_position());
//		  printf("Direction is %s\n",get_direction()?"forword":"backword");
		  usleep(5000);
		  step_motor_move_step_forward(STEP_MOTOR_0);
//		  step_motor_move_step_forward(STEP_MOTOR_1);
//		  step_motor_move_step_back(STEP_MOTOR_0);
		  step_motor_move_step_back(STEP_MOTOR_1);
		  printf("Temperature is %.2f C", AM2301_get_temperature(AM2301_0));
		  printf("\tTemperature is %.2f C\r", AM2301_get_temperature(AM2301_1));
	  }
	  fpga_close();
	  //trace_back();
	  return 0;
}
