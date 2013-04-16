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
    float moisture_d;
    float moisture_d_d;
    fan_motor_init(FAN_MOTOR_0);
    fan_motor_init(FAN_MOTOR_1);

    moisture = moisture_d = moisture_d_d = AM2301_get_moisture(AM2301_0);

    while(1) {
    	printf("moisture_regulating_process wake up\n");
    	moisture_d_d = moisture_d;
    	moisture_d = moisture;
        moisture = AM2301_get_moisture(AM2301_0);

        printf("moisture is %.2f%%\n", moisture);
        if (moisture < target_moisture - target_moisture * threshold)
        {
        	printf("moisture goes up\n");
            humidifier_on();
            //humidifier_regulating(5*(target_moisture - moisture)/target_moisture);
            //humidifier_regulating(PID(moisture,moisture_d,moisture_d_d), 5 ,0 ,0);
            printf("delta %f", PID(moisture,moisture_d,moisture_d_d, 0.5 ,0 ,0));
            exhaust_off();
        }
        else if(moisture > target_moisture + target_moisture * threshold)
        {
        	printf("moisture goes down\n");
            humidifier_off();
            exhaust_on();
            exhaust_regulating(3*(moisture - target_moisture)/target_moisture);
            printf("delta %f", PID(moisture,moisture_d,moisture_d_d, 0.5 ,0 ,0));
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
