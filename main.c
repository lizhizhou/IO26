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
	  //Brush_motor_forward();
	  Brush_motor_back();
	  //IOA_OE      = 0xffffffff;
	  //IOB_OE      = 0xffffffff;
	  printf("Position A is %d\n",get_position_A());
	  printf("Position B is %d\n",get_position_B());
	  fpga_close();
	  //trace_back();
	  return 0;
}
