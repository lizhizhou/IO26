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

#define DELTA 500000

static void semi_cooler_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	debuginf("previous_pwm = %u\n", previous_pwm);
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	if(previous_state == 1)
	{
		unsigned int j;
		for(j = previous_pwm; j > DELTA ; j=j-DELTA) {
			brush_motor_set_pwm(SEMI_COOLER, j);
		  	debuginf("go down %u\n", j);
		}
		previous_state = 0;
		brush_motor_forward(SEMI_COOLER);
		for(j = 0; j < pwm - DELTA; j=j+DELTA) {
			brush_motor_set_pwm(SEMI_COOLER, j);
	    	debuginf("go up %u\n", j);
		}
    	debuginf("buffer time for cooler\n");
	}
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
	debuginf("previous_pwm = %u\n", previous_pwm);
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	if(previous_state == 0)
	{
		unsigned int j;
		for(j = previous_pwm; j >DELTA; j=j-DELTA) {
			brush_motor_set_pwm(SEMI_COOLER, j);
	    	debuginf("go down %u\n", j);
		}
		brush_motor_back(SEMI_COOLER);
		for(j = 0; j < pwm - DELTA; j=j+DELTA) {
			brush_motor_set_pwm(SEMI_COOLER, j);
	    	debuginf("go up %u\n", j);
		}
		previous_state = 1;
	}
	brush_motor_set_pwm(SEMI_COOLER, pwm);
	previous_pwm = pwm;
}

static float previous_temp;
void* temperature_regulating_process(void* arg)
{
    float temperature;
    float error = 0;
    float error_d = 0;
    float error_d_d = 0;
    float temperature_box;

    while(1) {
    	temperature = sht1x_get_temperature(SHT1X_1);
    	temperature_box = sht1x_get_temperature(SHT1X_0);
    	previous_temp = temperature;
    	if(previous_temp - temperature > 5)
    		continue;
    	if( temperature > 38 || temperature < 0)
    		continue;
        error_d_d = error_d;
        error_d = error;
        error = target_temperature - temperature;
        //error = (target_temperature - temperature)/target_temperature;
        debuginf("error = %f\t", error);
        debuginf("temperature is %.2fC\t", temperature);
        //if (temperature < target_temperature - target_temperature * threshold)
        if (temperature < target_temperature - 0.3)
        {
        	debuginf("temperature goes up\n");
        	//semi_cooler_off();
        	semi_cooler_on();
            semi_warmer_regulating(PID(error,error_d,error_d_d, 0.03,temperature_box/250,1));
            debuginf("delta %f\n", PID(error,error_d,error_d_d, 0.03,temperature_box/250,1));
        }
        //else if(temperature > target_temperature + target_temperature * threshold)
        else if(temperature > target_temperature - 0.3)
        {
        	debuginf("temperature goes down\n");
        	semi_cooler_on();
        	semi_cooler_regulating(-PID(error,error_d,error_d_d, 0.3,temperature_box/25,2));
            debuginf("delta %f\n", -PID(error,error_d,error_d_d, 0.3,temperature_box/25,2));
        }
        else
        {
        	semi_cooler_off();
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
	brush_motor_init(SEMI_COOLER, 50000, 80);
	wator_bump_on();
	set_temperature_target(temperature);
	pthread_create(&pid, NULL, temperature_regulating_process, "temperature");
}
