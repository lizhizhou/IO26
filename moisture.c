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
static float target_moisture;
static void humidifier_on(void)
{
    IOA_IO_2 =1;
}

static void humidifier_off(void)
{
    IOA_IO_2 =0;
}

static void exhaust_on(void)
{
    IOA_IO_2 =1;
}

static void exhaust_off(void)
{
    IOA_IO_2 =0;
}

void set_moisture_target(float moisture)
{
    target_moisture = moisture;
}

void* moisture_regulating_process(void *arg)
{
    float moisture_1;
    float moisture_2;
    float moisture;

    while(1) {
    	printf("moisture_regulating_process wake up\n");
        //moisture_1 = AM2301_get_moisture(AM2301_0);
        //moisture_2 = AM2301_get_moisture(AM2301_1);
        moisture = moisture_1 + moisture_2;
        if (moisture < target_moisture)
        {
            humidifier_on();
            exhaust_off();
        }
        else if(moisture > target_moisture)
        {
            humidifier_off();
            exhaust_on();
        }
        else
        {
            humidifier_off();
            exhaust_off();
        }
        sleep(1);
    }
    return (NULL);
}
