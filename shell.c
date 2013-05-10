/*
 * shell.c
 *
 *  Created on: May 10, 2013
 *      Author: lizhizhou
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "platform.h"
#include "PIO26.h"
#include "shield_ctrl.h"
#include "FPGA.h"
#include "AM2301.h"
#include "position_sensor.h"
#include "step_motor.h"
#include "brush_motor.h"
#include "fan_motor.h"
#include "syringe.h"
#include "microscope.h"
#include "moisture.h"
#include "temperature.h"
int show_temperature(int argc,char* argv[])
{
    int i;
    float temperature;
    if(argc >2) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[1],"%d",&i);
    switch(i) {
        case 1:
            temperature = AM2301_get_temperature(AM2301_0);
            break;
        case 2:
            temperature = AM2301_get_temperature(AM2301_1);
            break;
    }
    printf("Temperature is %.2f C", temperature);
    return (1);
}
int show_moisture(int argc,char* argv[])
{
    int i;
    float moisture;
    if(argc >2) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[1],"%d",&i);
    switch(i) {
        case 1:
            moisture = AM2301_get_moisture(AM2301_0);
            break;
        case 2:
            moisture = AM2301_get_moisture(AM2301_1);
            break;
    }
    printf("TMoisture is %.2f%%", moisture);
    return (1);
}

int set_temperature(int argc,char* argv[])
{
    float temperature;
    if(argc >2) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[1],"%f", &temperature);
    set_temperature_target(temperature);
    return (1);
}

int set_moisture(int argc,char* argv[])
{
    float moisture;
    if(argc >2) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[1],"%f", &moisture);
    set_moisture_target(moisture);
    return (1);
}

int show_microscop_position(int argc,char* argv[])
{
    coordinates p;
    p = micorscope_get_coordinates();
    printf("The position is %d %d %d\n", p.x, p.y, p.z);
    return (1);
}

int set_microscop_position(int argc,char* argv[])
{
    coordinates p;
    if(argc >5) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[1], "%d %d %d", &p.x, &p.y, &p.z);
    p = micorscope_run_to_coordinates(p);
    printf("The position is %d %d %d\n", p.x, p.y, p.z);
    return (1);
}

int microscope_manual_calibration(int argc,char* argv[])
{
    microscope_manual_calibration_on();
    microscope_manual_calibration_off();
}
