/*
 * PIO8.h
 *
 *  Created on: Aug 1, 2013
 *      Author: zhizhouli
 */

#ifndef PIO8_H_
#define PIO8_H_
#include"FPGA.h"
#include"platform.h"

#define PORT0_ADDRESS   MSE_ADDRESS+0x0
#define PORT0_BASE      (IOA_ADDRESS/4)
#define PORT0           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT0_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT0_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT0_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT0_IO_BASE   16
#define PORT0_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT0_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT0_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT0_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT0_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT0_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT0_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT0_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT1_ADDRESS   MSE_ADDRESS+0x20
#define PORT1_BASE      (IOA_ADDRESS/4)
#define PORT1           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT1_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT1_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT1_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT1_IO_BASE   16
#define PORT1_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT1_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT1_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT1_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT1_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT1_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT1_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT1_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT1_ADDRESS   0x0
#define PORT1_BASE      (IOA_ADDRESS/4)
#define PORT1           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT1_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT1_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT1_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT1_IO_BASE   16
#define PORT1_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT1_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT1_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT1_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT1_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT1_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT1_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT1_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT2_ADDRESS   0x0
#define PORT2_BASE      (IOA_ADDRESS/4)
#define PORT2           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT2_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT2_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT2_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT2_IO_BASE   16
#define PORT2_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT2_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT2_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT2_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT2_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT2_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT2_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT2_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT3_ADDRESS   0x0
#define PORT3_BASE      (IOA_ADDRESS/4)
#define PORT3           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT3_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT3_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT3_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT3_IO_BASE   16
#define PORT3_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT3_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT3_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT3_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT3_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT3_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT3_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT3_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT4_ADDRESS   0x0
#define PORT4_BASE      (IOA_ADDRESS/4)
#define PORT4           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT4_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT4_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT4_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT4_IO_BASE   16
#define PORT4_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT4_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT4_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT4_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT4_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT4_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT4_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT4_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT5_ADDRESS   0x0
#define PORT5_BASE      (IOA_ADDRESS/4)
#define PORT5           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT5_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT5_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT5_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT5_IO_BASE   16
#define PORT5_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT5_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT5_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT5_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT5_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT5_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT5_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT5_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT6_ADDRESS   0x0
#define PORT6_BASE      (IOA_ADDRESS/4)
#define PORT6           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT6_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT6_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT6_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT6_IO_BASE   16
#define PORT6_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT6_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT6_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT6_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT6_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT6_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT6_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT6_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT7_ADDRESS   0x0
#define PORT7_BASE      (IOA_ADDRESS/4)
#define PORT7           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT7_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT7_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT7_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT7_IO_BASE   16
#define PORT7_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT7_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT7_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT7_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT7_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT7_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT7_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT7_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT8_ADDRESS   0x0
#define PORT8_BASE      (IOA_ADDRESS/4)
#define PORT8           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT8_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT8_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT8_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT8_IO_BASE   16
#define PORT8_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT8_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT8_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT8_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT8_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT8_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT8_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT8_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)

#define PORT9_ADDRESS   0x0
#define PORT9_BASE      (IOA_ADDRESS/4)
#define PORT9           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define PORT9_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define PORT9_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define PORT9_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define PORT9_IO_BASE   16
#define PORT9_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define PORT9_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define PORT9_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define PORT9_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define PORT9_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define PORT9_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define PORT9_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define PORT9_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)


#endif /* PIO8_H_ */
