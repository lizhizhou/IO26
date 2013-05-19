/*
 * unit_test.c
 *
 *  Created on: Apr 30, 2013
 *      Author: lizhizhou
 */
#include <stdio.h>
#include <unistd.h>
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
#include "PID.h"

void AM2301_test()
{
    AM2301_init(AM2301_0);
    AM2301_init(AM2301_1);
    while(1)
    {
        sleep(1);
        printf("Temperature is %.2f C", AM2301_get_temperature(AM2301_0));
        printf("\tTemperature is %.2f C\n", AM2301_get_temperature(AM2301_1));
        printf("Moisture is %.2f%%", AM2301_get_moisture(AM2301_0));
        printf("\tMoisture is %.2f%% \n", AM2301_get_moisture(AM2301_1));
    }
}

void syringe_test()
{
    syringe_init();
    //  while(syringe_faster_back());
    //  printf("syringe stuck\n");
    while(syringe_faster_forward());
    printf("syringe stuck\n");
    syringe_mark_start();
    syringe_set_target(200,0);
    syringe_run_back();
    printf("syringe done\n");
    sleep(5);
    syringe_mark_start();
    syringe_set_target(100,0);
    syringe_run_forward();
    printf("syringe done\n");
}

void step_motmor_test()
{
    int i;
    step_motor_init(STEP_MOTOR_0, 10000, 50);
    step_motor_init(STEP_MOTOR_1, 10000, 50);
    step_motor_init(STEP_MOTOR_2, 10000, 50);
    for(i = 0; i < 1000; i++) {
        step_motor_move_step_forward(STEP_MOTOR_0);
        step_motor_move_step_forward(STEP_MOTOR_1);
        step_motor_move_step_forward(STEP_MOTOR_2);
    }
    for(i = 0; i < 1000; i++) {
        step_motor_move_step_back(STEP_MOTOR_0);
        step_motor_move_step_back(STEP_MOTOR_1);
        step_motor_move_step_back(STEP_MOTOR_2);
    }
    setp_motor_subdivision(STEP_MOTOR_2, 6, 16 ,50);
}

void brush_motor_test()
{
    brush_motor_init(BRUSH_MOTOR_0);
    brush_motor_init(BRUSH_MOTOR_1);
    brush_motor_back(BRUSH_MOTOR_1);
    brush_motor_init(BRUSH_MOTOR_2);
    brush_motor_init(BRUSH_MOTOR_3);
}

void microscope_test()  // 10um per step
{
    coordinates target;
    target.x = 1000;
    target.y = -2000;
    target.z = 500;
    microscope_init();
    micorscope_run_to_coordinates(target);
    target.x = -1000;
    target.y = 1000;
    target.z = -500;
    micorscope_run_to_coordinates(target);
    target.x = -2000;
    target.y = -2000;
    target.z = -500;
    micorscope_run_to_coordinates(target);
    target.x = 2000;
    target.y = 2000;
    target.z = -500;
    micorscope_run_to_coordinates(target);
    target.x=0;
    target.y=0;
    target.z=0;
    micorscope_run_to_coordinates(target);
    microscope_manual_calibration_on();

}

void wheel_plate_test()
{
    int i;
    int position1 = get_position(POSITITON_SENSNOR_0);
    int position2;
    step_motor_init(STEP_MOTOR_0, 2000, 50);
    printf("p1 = %d\n", position1);
    for(i = 0; i < 20; i++)
        step_motor_move_step_forward(STEP_MOTOR_0);
    position2 = get_position(POSITITON_SENSNOR_0);
    printf("p2 = %d\n", position2);
    if (position2 - position1 > 1000)
        printf("moving step1 %d\n", position2 - 1000 - position1);
    else
        printf("moving step2 %d\n", position1 - position2);
}

void PID_test()
{
    int i;
    float target =100;
    float current = 0;
    float current_d =0;
    float current_d_d = 0;
    float error;
    float error_d;
    float error_d_d;
    for(i=0; i < 100; i++)
    {
        current_d_d = current_d;
        current_d = current;
        error_d_d = error_d;
        error_d = error;
        error = target - current_d_d;
        current = current + PID(error, error_d, error_d_d, 0.2, 0.01, 0.03);
        printf("current is %f\n",current);
    }
}

void PIO_test()
{
    IOA_OE      = 0xffffffff;  // init IO
    IOB_OE      = 0xffffffff;  // init IO
    IOA_IO_0    = 0;
    IOB_IO_0    = 1;
    IOA_IO_1    = 0;
    IOB_IO_1    = 1;
}
