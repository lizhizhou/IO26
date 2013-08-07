/*
 * temperature.c
 *
 *  Created on: Apr 11, 2013
 *      Author: lizhizhou
 */
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "AM2301.h"
#include "platform.h"
#include "brush_motor.h"
#include "PIO8.h"
#include "PID.h"

#define SEMI_COOLER      MSE_BRUSH_MOTOR_0

static float target_temperature;
static float threshold = 0;
void set_temperature_target(float temperature)
{
    target_temperature = temperature;
}

static void wator_bump_on()
{
	PORT0_DATA  |= 0x1;
	usleep(50);
}

static void wator_bump_off()
{
	PORT0_DATA  &= ~0x01;
	usleep(50);
}

static void semi_cooler_on()
{
	brush_motor_ON(MSE_BRUSH_MOTOR_0);
}

static void semi_cooler_off()
{
	brush_motor_OFF(MSE_BRUSH_MOTOR_0);
}


static void semi_cooler_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	brush_motor_forward(SEMI_COOLER);
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	brush_motor_set_pwm(SEMI_COOLER, pwm);
}

static void semi_warmer_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	brush_motor_back(SEMI_COOLER);
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	brush_motor_set_pwm(SEMI_COOLER, pwm);
}


void* temperature_regulating_process(void* arg)
{
    float temperature;
    float error = 0;
    float error_d = 0;
    float error_d_d = 0;

    while(1) {
    	printf("temperature_regulating_process wake up\n");
    	temperature = AM2301_get_temperature(AM2301_0);
        error_d_d = error_d;
        error_d = error;
        error = (target_temperature - temperature)/target_temperature;
        printf("temperature is %.2fC out is %.2fC\n", AM2301_get_temperature(AM2301_0),
        		AM2301_get_temperature(AM2301_1));
        if (temperature < target_temperature - target_temperature * threshold)
        {
        	printf("temperature goes up\n");
            semi_warmer_regulating(PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
            printf("delta %f", PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
        }
        else if(temperature > target_temperature + target_temperature * threshold)
        {
        	printf("temperature goes down\n");
            semi_cooler_regulating(-PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
            printf("delta %f", PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
        }
        else
        {
        	printf("moisture keeps\n");

        }
        sleep(1);
    }
    return (NULL);
}

void init_temperature_subsystem(float temperature)
{
	pthread_t pid;
	PORT0_OE  |= 0x1;
	usleep(50);
	brush_motor_init(SEMI_COOLER, 1000, 30);
	wator_bump_on();
	set_temperature_target(temperature);
	pthread_create(&pid, NULL, temperature_regulating_process, "temperature");
}
