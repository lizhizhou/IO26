/*
 * moisture.c
 *
 *  Created on: Apr 11, 2013
 *      Author: lizhizhou
 */
#include <stdio.h>
#include <unistd.h>
#include "AM2301.h"
#include "platform.h"
#include "PIO26.h"
#include "fan_motor.h"
#include "PID.h"
static float target_moisture;
static float threshold = 0;
static void humidifier_on(void)
{
	fan_ON(FAN_MOTOR_1);
}

static void humidifier_off(void)
{
	fan_OFF(FAN_MOTOR_1);
}

static void exhaust_on(void)
{
	fan_ON(FAN_MOTOR_0);
}

static void exhaust_off(void)
{
	fan_OFF(FAN_MOTOR_0);
}

static void humidifier_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	fan_motor_set_pwm(FAN_MOTOR_1, pwm);
}

static void exhaust_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	pwm = (0xffffffff - 0x1fffffff)*i + 0x1fffffff;
	fan_motor_set_pwm(FAN_MOTOR_0, pwm);
}

void set_moisture_target(float moisture)
{
    target_moisture = moisture;
}

void* moisture_regulating_process(void *arg)
{
    float moisture;
    float error = 0;
    float error_d = 0;
    float error_d_d = 0;
	FILE* fp;
    fan_motor_init(FAN_MOTOR_0);
    fan_motor_init(FAN_MOTOR_1);

    moisture = AM2301_get_moisture(AM2301_0);

    while(1) {
    	printf("moisture_regulating_process wake up\n");
        moisture = AM2301_get_moisture(AM2301_0);
        error_d_d = error_d;
        error_d = error;
        error = (target_moisture - moisture)/target_moisture;
    	fp = fopen("log","a");
        fprintf(fp, "%f ", moisture);
        fclose(fp);
        printf("moisture is %.2f%% out is %.2f%%\n", moisture, AM2301_get_moisture(AM2301_1));
        printf("temperature is %.2fC out is %.2fC\n", AM2301_get_temperature(AM2301_0),
        		AM2301_get_temperature(AM2301_1));
        if (moisture < target_moisture - target_moisture * threshold)
        {
        	printf("moisture goes up\n");
            humidifier_on();
            humidifier_regulating(PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
            printf("delta %f", PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
            exhaust_off();
        }
        else if(moisture > target_moisture + target_moisture * threshold)
        {
        	printf("moisture goes down\n");
            humidifier_off();
            exhaust_on();
            exhaust_regulating(-PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
            printf("delta %f", PID(error,error_d,error_d_d, 1 ,0.001 ,0.3));
        }
        else
        {
        	printf("moisture keeps\n");
            humidifier_off();
            exhaust_off();
        }
        sleep(1);
    }
    return (NULL);
}
