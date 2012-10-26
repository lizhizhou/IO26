#include <stdio.h>
#include <unistd.h>

#include "PIO26.h"
#include "ShieldCtrl.h"
#include "FPGA.h"
#include "AM2301.h"
#include "debug.h"

int main(int argn, char* argv[])
{
	  fpga_open();
	  ShieldCtrl_init();
	  AM2301_init();
	  //IOA_OE      = 0xffffffff;
	  //IOB_OE      = 0xffffffff;
	  fpga_close();
	  trace_back();
	  return 0;
}
