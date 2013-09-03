/*
 * temperature.c
 *
 *  Created on: Apr 11, 2013
 *      Author: lizhizhou
 */
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "sht1x.h"
#include "platform.h"
#include "brush_motor.h"
#include "PIO8.h"
#include "PID.h"
#include "debug.h"

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

static int previous_state = 0;
static unsigned int previous_pwm = 0;

#define DELTA 100000

static void semi_cooler_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	if(previous_state == 1)
	{
		unsigned int j;
		printf("previous_pwm = %u\n", previous_pwm);
		for(j = previous_pwm; j > DELTA ; j=j-DELTA) {
			brush_motor_set_pwm(SEMI_COOLER, j);
		  	debuginf("go down %u\n", j);
		}
		previous_state = 0;
    	debuginf("buffer time for cooler\n");
	}
	brush_motor_forward(SEMI_COOLER);
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	brush_motor_set_pwm(SEMI_COOLER, pwm);
	previous_pwm = pwm;
}

static void semi_warmer_regulating(float i)
{
	unsigned int pwm;
	if (i > 0.5)
		i = 0.5;
	else if (i < 0)
		i = 0;
	if(previous_state == 0)
	{
		unsigned int j;
		printf("previous_pwm = %u\n", previous_pwm);
		for(j = previous_pwm; j >DELTA; j=j-DELTA) {
			brush_motor_set_pwm(SEMI_COOLER, j);
	    	debuginf("go down %u\n", j);
		}
		previous_state = 1;
    	debuginf("buffer time for warmer\n");
	}
	brush_motor_back(SEMI_COOLER);
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	brush_motor_set_pwm(SEMI_COOLER, pwm);
	previous_pwm = pwm;
}


void* temperature_regulating_process(void* arg)
{
    float temperature;
    float error = 0;
    float error_d = 0;
    float error_d_d = 0;

    while(1) {
    	debuginf("temperature_regulating_process wake up\n");
    	temperature = sht1x_get_temperature(SHT1X_1),
        error_d_d = error_d;
        error_d = error;
        error = (target_temperature - temperature)/target_temperature;
        debuginf("temperature is %.2fC\n", temperature);
        debuginf("error = %f\n", error);
        if (temperature < target_temperature - target_temperature * threshold)
        {
        	debuginf("temperature goes up\n");
            semi_warmer_regulating(PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
            debuginf("delta %f", PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
        }
        else if(temperature > target_temperature + target_temperature * threshold)
        {
        	debuginf("temperature goes down\n");
            semi_cooler_regulating(-PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
            debuginf("delta %f", PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
        }
        else
        {
        	debuginf("temperature keeps\n");
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
	brush_motor_init(SEMI_COOLER, 500000, 1);
	wator_bump_on();
	set_temperature_target(temperature);
	pthread_create(&pid, NULL, temperature_regulating_process, "temperature");
}
