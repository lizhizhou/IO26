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
static float target_moisture;
static float threshold = 0.05;
static void humidifier_on(void)
{
    IOA_IO_1 =0;
}

static void humidifier_off(void)
{
    IOA_IO_1 =1;
}

static void exhaust_on(void)
{
	fan_ON(FAN_MOTOR_0);
}

static void exhaust_off(void)
{
	fan_OFF(FAN_MOTOR_0);
}

void set_moisture_target(float moisture)
{
    target_moisture = moisture;
}

void* moisture_regulating_process(void *arg)
{
    float moisture;

    fan_motor_init(FAN_MOTOR_0);
	IOA_OE      = 0xffffffff;

    while(1) {
    	printf("moisture_regulating_process wake up\n");
        moisture = AM2301_get_moisture(AM2301_0);
        printf("moisture is %.2f%%\n", moisture);
        if (moisture < target_moisture - target_moisture * threshold)
        {
        	printf("moisture goes up\n");
            humidifier_on();
            exhaust_off();
            sleep(1);
        }
        else if(moisture > target_moisture + target_moisture * threshold)
        {
        	printf("moisture goes down\n");
            humidifier_off();
            //exhaust_on();
            sleep(1);
        }
        else
        {
        	printf("moisture keeps\n");
            humidifier_off();
            exhaust_off();
        }
        humidifier_off();
        exhaust_off();
        sleep(1);
    }
    return (NULL);
}
