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
	  AM2301_init(AM2301_1);
	  brush_motor_init();
	  fan_motor_init();
	  step_motor_init(STEP_MOTOR_1);
	  //IOA_OE      = 0xffffffff;
	  //IOB_OE      = 0xffffffff;
	  syringe_mark_start();
	  syringe_set_target(50, 0);
	  syringe_run_forward();
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
//		  usleep(2000);
//		  Step_motor_move_step_forward(STEP_MOTOR_1);
//		  Step_motor_move_step_back(STEP_MOTOR_1);
	  }
	  fpga_close();
	  //trace_back();
	  return 0;
}
