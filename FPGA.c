/*
 * FPGA.c
 *
 *  Created on: Oct 25, 2012
 *      Author: lizhizhou
 */
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "FPGA.h"
int* FPGA_MOD_BASE;
int* FPGA_SYS_BASE;
const int ADDRESS_LENGTH = 4096;
void fpga_open()
{
	  int sysmem_fd;
	  sysmem_fd = open("/sys/kernel/debug/lophilo/modmem", O_RDWR);
	  FPGA_MOD_BASE = mmap(
		  0,  // starting address
		  ADDRESS_LENGTH, // length
		  PROT_READ | PROT_WRITE,  //prot
		  MAP_SHARED, //flags
		  sysmem_fd, //filedescriptor
		  0x0 // offset
		  );
	  close(sysmem_fd);
	  sysmem_fd = open("/sys/kernel/debug/lophilo/sysmem", O_RDWR);
	  FPGA_SYS_BASE = mmap(
		  0,  // starting address
		  ADDRESS_LENGTH, // length
		  PROT_READ | PROT_WRITE,  //prot
		  MAP_SHARED, //flags
		  sysmem_fd, //filedescriptor
		  0x0 // offset
		  );
	  close(sysmem_fd);
}

void fpga_close()
{
	munmap(FPGA_SYS_BASE, ADDRESS_LENGTH);
	munmap(FPGA_MOD_BASE, ADDRESS_LENGTH);
}

int sysid_check()
{
	if(SYS_ID == 0xea680001)
		return 1;
	else
		return 0;
}
