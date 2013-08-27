/*
 * moisture.c
 *
 *  Created on: Apr 11, 2013
 *      Author: lizhizhou
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "sht1x.h"
#include "platform.h"
#include "PIO26.h"
#include "fan_motor.h"
#include "PID.h"
static float target_moisture;
static float threshold = 0;

#define HUMIDIFIER      MSE_FAN_MOTOR_1
#define EXHAUST         MSE_FAN_MOTOR_2
#define HUMIDIFIER_FAN  MSE_FAN_MOTOR_3

static void humidifier_on(void)
{
	fan_ON(HUMIDIFIER);
}

static void humidifier_off(void)
{
	fan_OFF(HUMIDIFIER);
}

static void exhaust_on(void)
{
	fan_ON(EXHAUST);
}

static void exhaust_off(void)
{
	fan_OFF(EXHAUST);
}

static void humidifier_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	pwm = (0xffffffff - 0x30000000)*i + 0x30000000;
	fan_motor_set_pwm(HUMIDIFIER, pwm);
}

static void exhaust_regulating(float i)
{
	unsigned int pwm;
	if (i > 1)
		i = 1;
	else if (i < 0)
		i = 0;
	pwm = (0xffffffff - 0x1fffffff)*i + 0x1fffffff;
	fan_motor_set_pwm(EXHAUST, pwm);
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

    moisture = sht1x_get_moisture(SHT1X_1);

    while(1) {
    	printf("moisture_regulating_process wake up\n");
        moisture = sht1x_get_moisture(SHT1X_1);
        error_d_d = error_d;
        error_d = error;
        error = (target_moisture - moisture)/target_moisture;
    	fp = fopen("log","a");
        fprintf(fp, "%f ", moisture);
        fclose(fp);
        printf("moisture is %.2f%%\n", moisture);
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

void init_moisture_subsystem(float moisture)
{
	pthread_t pid;
    fan_motor_init(EXHAUST, 50000, 50);
    fan_motor_init(HUMIDIFIER, 50000, 50);
	set_moisture_target(moisture);
//	pthread_create(&pid, NULL, moisture_regulating_process, "moisture");
}
