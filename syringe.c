/*
 * syringe.c
 *
 *  Created on: Jan 29, 2013
 *      Author: lizhizhou
 */
#include <unistd.h>
#include <stdio.h>
#include "platform.h"
#include "position_sensor.h"
#include "step_motor.h"
#define PARAMETER  10
static int syringe_start=0;
static int syringe_target=0;
static int syringe_diameter=0;
void syringe_mark_start()
{
    syringe_start = get_position(POSITITON_SENSNOR_1);
}

void syringe_set_target(int m_litre, int u_litre)
{
    syringe_target = syringe_start -
    		m_litre;
    		//(1000* m_litre + u_litre) / syringe_diameter * PARAMETER;
}

void syringe_set_diameter(int m_meter)
{
    syringe_diameter = m_meter;
}

int syringe_run_forward()
{
    int i=0;
    int position = get_position(POSITITON_SENSNOR_1);
    printf("syringe_target = %d\n", syringe_target);
    while(position > syringe_target) {
    	usleep(2000);
    	printf("position = %d\n", position);
        step_motor_move_step_forward(STEP_MOTOR_1);
//        if (get_position() == position) {
//            printf("The syringe stuck\n");
//            break;
//        }
        position = get_position(POSITITON_SENSNOR_1);
    }
    return (1);
}

int syringe_run_back()
{
    int i=0;
    int position = get_position(POSITITON_SENSNOR_1);
    printf("syringe_target = %d", syringe_target);
    while(position > syringe_target) {
    	usleep(2000);
    	printf("position = %d", position);
        step_motor_move_step_back(STEP_MOTOR_1);
//        if (get_position() == position) {
//            printf("The syringe stuck\n");
//            break;
//        }
        position = get_position(POSITITON_SENSNOR_1);
    }
    return (1);
}

int syringe_faster_forward()
{
    int i=0;
    int position = 0;
    while(position < syringe_target) {
        step_motor_move_step_forward(STEP_MOTOR_1);
        if (get_position(POSITITON_SENSNOR_1) == position) {
            printf("The syringe stuck\n");
            break;
        }
        position = get_position(POSITITON_SENSNOR_1);
    }
    return (1);
}

void syringe_init()
{
    step_motor_init(STEP_MOTOR_1);
}
