/*
 * temperature.c
 *
 *  Created on: Apr 11, 2013
 *      Author: lizhizhou
 */
#include <unistd.h>
#include <stdio.h>
#include "AM2301.h"
#include "platform.h"
#include "PWM.h"
#include "PID.h"
static float target_temperature;
void set_temperature_target(float temperature)
{
    target_temperature = temperature;
}

void* temperature_regulating_process(void* arg)
{
    float temperature_1;
    float temperature_2;
    float temperature;

    while(1) {
    	printf("temperature_regulating_process wake up\n");
        temperature_1 = AM2301_get_temperature(AM2301_0);
        temperature_2 = AM2301_get_temperature(AM2301_1);
        temperature = temperature_1 + temperature_2;
    }
    return (NULL);
}
