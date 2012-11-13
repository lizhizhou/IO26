#include <stdio.h>
#include <unistd.h>

#include "PIO26.h"
#include "ShieldCtrl.h"
#include "FPGA.h"
#include "AM2301.h"
#include "position_sensor.h"
#include "Brush_motor.h"
#include "debug.h"


int main(int argn, char* argv[])
{
	  fpga_open();
	  ShieldCtrl_init();
	  AM2301_init();
	  Brush_motor_init();
	  fan_motor_init();
	  //IOA_OE      = 0xffffffff;
	  //IOB_OE      = 0xffffffff;
	  printf("Position A is %d\n",get_position_A());
	  printf("Position B is %d\n",get_position_B());
	  while(1) {
		  Brush_motor_ON();
		  fan_ON();
		  Brush_motor_forward();
		  getchar();
		  Brush_motor_back();
		  getchar();
		  Brush_motor_OFF();
		  fan_OFF();
		  getchar();
	  }
	  fpga_close();
	  //trace_back();
	  return 0;
}
