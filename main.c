#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include "platform.h"
#include "PIO26.h"
#include "shield_ctrl.h"
#include "FPGA.h"
#include "AM2301.h"
#include "sht1x.h"
#include "position_sensor.h"
#include "step_motor.h"
#include "brush_motor.h"
#include "fan_motor.h"
#include "syringe.h"
#include "microscope.h"
#include "moisture.h"
#include "temperature.h"
#include "PID.h"
#include "debug.h"
#include "unit_test.h"

#define MSE_DATA       *((volatile int*) MSE)
#define MSE_DATA1      *((volatile int*) MSE+1)
#define MSE_DATA2      *((volatile int*) MSE+2)
#define MSE_DATA3      *((volatile int*) MSE+3)
#define MSE_DATA4      *((volatile int*) MSE+4)
#define TEST_REG_DATA  *((volatile int*) TEST_REG)

int main(int argn, char* argv[])
{
	int i = 0;
	if (!fpga_open()) {
		printf("FPGA open error\n");
		exit(1);
	}
	getchar();
	shield_ctrl_init();

//	sht1x_init(SHT1X_0);
//	cli();
	while(i<10000){
		MSE_DATA4 = i;
		//usleep(10);
		TEST_REG_DATA = i;
		if(MSE_DATA  != 0xea680001){printf("MSE_DATA 0x%x error", MSE_DATA); break;}
		if(MSE_DATA1 != 0){printf("MSE_DATA1 0x%x error", MSE_DATA1); break;}
		if(MSE_DATA2 != 0xa5a5a5a5){printf("MSE_DATA2 0x%x error", MSE_DATA2); break;}
		if(MSE_DATA3 != 0x5a5a5a5a){printf("MSE_DATA3 0x%x error", MSE_DATA3); break;}
		if(MSE_DATA4 != i){printf("MSE_DATA4 %d error", MSE_DATA4); break;}
		if(TEST_REG_DATA != i){printf("TEST_REG_DATA  %d error", TEST_REG_DATA); break;}
		i++;
	}
	printf("i = %d", i);
//	sht1x_init(SHT1X_0);
//	printf("Temp %fC Mois %f%%\n\n", sht1x_get_temperature(SHT1X_0),
//			sht1x_get_moisture(SHT1X_0));
//	printf("Temp %fC Mois %f%%\n\n", sht1x_get_temperature(SHT1X_1),
//			sht1x_get_moisture(SHT1X_1));
	cli();
	/*if(argn != 2) {
		printf("arg error\n");
		return 0;
	}
	printf(argv[1]);
	sscanf(argv[1],"%f", &i);
	printf("target is %0.2f%%\n", i);
    init_moisture_subsystem(i);
	printf("done\n");*/
	//subdivision_step_motor_test();
	while(1) {
//		printf("Temp %.2fC Mois %.2f%%\n\n", sht1x_get_temperature(SHT1X_0),
//				sht1x_get_moisture(SHT1X_0));
//		printf("Temp %.2fC Mois %.2f%%\n\n", sht1x_get_temperature(SHT1X_1),
//				sht1x_get_moisture(SHT1X_1));
		sleep(1);
		printf("main loop wake up\n");

    }
	fpga_close();
	//trace_back();
	return 0;
}
