/*
 * ShieldCtrl.c
 *
 *  Created on: Oct 26, 2012
 *      Author: Zhizhou LI
 */
#include "ShieldCtrl.h"
#include "FPGA.h"

void ShieldCtrl_init()
{
	  SHIELD_CTRL = 0x03030300;
}
