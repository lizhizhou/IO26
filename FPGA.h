/*
 * FPGA.h
 *
 *  Created on: Oct 25, 2012
 *      Author: Zhizhou Li
 */

#ifndef FPGA_H_
#define FPGA_H_

#define SYS_ID         *((volatile int*) FPGA_SYS_BASE)

extern int* FPGA_MOD_BASE;
extern int* FPGA_SYS_BASE;
extern void fpga_open();
extern void fpga_close();


#endif /* FPGA_H_ */
