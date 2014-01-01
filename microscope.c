/*
 * microscope.c
 *
 *  Created on: Mar 26, 2013
 *      Author: lizhizhou
 */
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "platform.h"
#include "PIO26.h"
#include "PIO8.h"
#include "step_motor.h"
#include "fan_motor.h"
#include "microscope.h"
#define MICRO_MAGI 0x46427834
#define STEP_MOTOR_X        STEP_MOTOR_0
#define STEP_MOTOR_Y        STEP_MOTOR_1
#define STEP_MOTOR_Z        STEP_MOTOR_2
#define LED 			    MSE_FAN_MOTOR_0
static coordinates current;
#define X_Parameter 1     // 10 um per setp
#define Y_Parameter 1     // 10 um per setp
//#define X_Parameter 2     // 5 um per setp
//#define Y_Parameter 2     // 5 um per setp
#define Z_Parameter 1     // 10 um per setp
static int get_edge_sensor_x_plus()
{
	return (PORT0_DATA & 0x4);
}
static int get_edge_sensor_x_minus()
{
	return (PORT0_DATA & 0x2);
}
static int get_infrared_sensor_x()
{
	return (PORT0_DATA & 0x8);
}
static int get_edge_sensor_y_plus()
{
	return (PORT0_DATA & 0x20);
}
static int get_edge_sensor_y_minus()
{
	return (PORT0_DATA & 0x10);
}
static int get_infrared_sensor_y()
{
	return (PORT0_DATA & 0x40);
}
static int get_edge_sensor_z_plus()
{
	return (PORT0_DATA & 0x100);
}
static int get_edge_sensor_z_minus()
{
	return (PORT0_DATA & 0x80);
}
static int get_infrared_sensor_z()
{
	return (PORT0_DATA & 0x200);
}
#define LED_PWM 1
static int led_light = LED_PWM * 10;

void microscope_init()
{
	PORT0_OE   &= ~0x3fe;  // init PORT0 1-9 as inport
	step_motor_init(STEP_MOTOR_X, 50000, 20);
	step_motor_init(STEP_MOTOR_Y, 50000, 20);
	step_motor_init(STEP_MOTOR_Z, 50000, 20);
	fan_motor_init(LED, 5000, LED_PWM);
}

int microscope_led_get_light()
{
	return led_light;
}

void microscope_led_set_light(int light)
{
	fan_motor_set_pwm(LED, 0xFFFFFFFF / 1000 * light);
	led_light = light;
}

unsigned int microscope_x_plus(unsigned int step)
{
    int i;
    for(i = 0; i < step * X_Parameter; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_X);
        if (get_edge_sensor_x_plus())
        	return (i);
    }
    return (step);
}
unsigned int microscope_x_minus(unsigned int step)
{
    int i;
    for(i = 0; i < step * X_Parameter; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_X);
        if (get_edge_sensor_x_minus())
        	return (i);
    }
    return (step);
}
unsigned int microscope_y_plus(unsigned int step)
{
    int i;
    for(i = 0; i < step * Y_Parameter; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_Y);
        if (get_edge_sensor_y_plus())
        	return (i);
    }
    return (step);
}
unsigned int microscope_y_minus(unsigned int step)
{
    int i;
    for(i = 0; i < step * Y_Parameter; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_Y);
        if (get_edge_sensor_y_minus())
        	return (i);
    }
    return (step);
}
unsigned int microscope_z_plus(unsigned int step)
{
    int i;
    for(i = 0; i < step * Z_Parameter; i++)
    {
        step_motor_move_step_forward(STEP_MOTOR_Z);
        if (get_edge_sensor_z_plus())
        	return (i);
    }
    return (step);
}
unsigned int microscope_z_minus(unsigned int step)
{
    int i;
    for(i = 0; i < step * Z_Parameter; i++)
    {
        step_motor_move_step_back(STEP_MOTOR_Z);
        if (get_edge_sensor_z_minus())
        	return (i);
    }
    return (step);
}

void microscope_calibration(void)
{
    while(get_infrared_sensor_x() != 0)
        microscope_x_plus(1);
    while(get_infrared_sensor_y() != 0)
        microscope_y_plus(1);
    while(get_infrared_sensor_z() != 0)
        microscope_z_plus(1);
    micorscope_set_coordinates_zero();
}

void microscope_manual_calibration_on(void)
{
    step_motor_off(STEP_MOTOR_X);
    step_motor_off(STEP_MOTOR_Y);
    step_motor_off(STEP_MOTOR_Z);
}

void microscope_manual_calibration_off(void)
{
    step_motor_on(STEP_MOTOR_X);
    step_motor_on(STEP_MOTOR_Y);
    step_motor_on(STEP_MOTOR_Z);
}
#ifdef PARALLEL
void* microscope_x_task(void* arg)
{
    coordinates* delta = (coordinates* )arg;
    int x = delta->x;
	printf("x=%d\n", x);
	if(x > 0)
		current.x += microscope_x_plus(x);
	else
		current.x -= microscope_x_minus(-x);
	return 0;
}

void* microscope_y_task(void* arg)
{
    coordinates* delta = (coordinates* )arg;
	int y = delta->y;
	printf("y=%d\n", y);
	if(y > 0)
		current.y += microscope_y_plus(y);
	else
		current.y -= microscope_y_minus(-y);
	return 0;
}

void* microscope_z_task(void* arg)
{
    coordinates* delta = (coordinates* )arg;
	int z = delta->z;
	printf("z=%d\n", z);
	if(z > 0)
		current.z += microscope_z_plus(z);
	else
		current.z -= microscope_z_minus(-z);
	return 0;
}
#endif
coordinates micorscope_run_to_coordinates(coordinates target)
{
    coordinates delta;
#ifdef PARALLEL
	pthread_t x, y, z;
#endif
	delta.x = target.x - current.x;
    delta.y = target.y - current.y;
    delta.z = target.z - current.z;

#ifdef PARALLEL
	pthread_create(&x, NULL, microscope_x_task, (void *)&delta);
	pthread_create(&y, NULL, microscope_y_task, (void *)&delta);
	pthread_create(&z, NULL, microscope_z_task, (void *)&delta);
	pthread_join(x, NULL);
	pthread_join(y, NULL);
	pthread_join(z, NULL);
#else
    if(delta.x > 0)
		current.x += microscope_x_plus(delta.x);
	else
		current.x -= microscope_x_minus(-delta.x);
    if(delta.y > 0)
        current.y += microscope_y_plus(delta.y);
    else
        current.y -= microscope_y_minus(-delta.y);
    if(delta.z > 0)
        current.z += microscope_z_plus(delta.z);
    else
        current.z -= microscope_z_minus(-delta.z);
#endif
    return current;
}

coordinates micorscope_get_coordinates(void)
{
    return current;
}

void micorscope_set_coordinates_zero(void)
{
    current.x = 0;
    current.y = 0;
    current.z = 0;
}

void micorscope_set_coordinates(coordinates n)
{
    current.x = n.x;
    current.y = n.y;
    current.z = n.z;
}

coordinates rectangular_to_coordinates(rectangular n)
{
	coordinates r;
	r.x = n.x;
	r.y = n.y;
	r.z = n.z;
	return (r);
}

rectangular coordinates_to_rectangular(coordinates n)
{
	rectangular r;
	r.x = n.x;
	r.y = n.y;
	r.z = n.z;
	return (r);
}

void microscope_original_angle(coordinates ref_point[], coordinates* original,
        float* angle)
{
    int d[3];
    int org_x, org_y;
    int x, y;
    d[0] = distence(coordinates_to_rectangular(ref_point[0]),
            coordinates_to_rectangular(ref_point[1]));
    d[1] = distence(coordinates_to_rectangular(ref_point[1]),
            coordinates_to_rectangular(ref_point[2]));
    d[2] = distence(coordinates_to_rectangular(ref_point[2]),
            coordinates_to_rectangular(ref_point[0]));
    if (d[2] > d[1] && d[2] > d[0])
    {
    	org_x  = (ref_point[0].x+ref_point[2].x) /2;
    	org_y =  (ref_point[0].y+ref_point[2].y) /2;
    } else if (d[1] > d[0] && d[1] > d[2])
    {
    	org_x  = (ref_point[1].x+ref_point[2].x) /2;
    	org_y =  (ref_point[1].y+ref_point[2].y) /2;
    }
    else
    {
    	org_x  = (ref_point[0].x+ref_point[1].x) /2;
     	org_y =  (ref_point[0].y+ref_point[1].y) /2;
    }
    original->x = org_x;
    original->y = org_y;
    if (d[2] < d[1] && d[2] < d[0])
    {
    	x = (ref_point[0].y+ref_point[2].y)/2 - org_x;
    	y = (ref_point[0].x+ref_point[2].x)/2 - org_y;
     	*angle = radian_to_angle(atan2(y,x));
    }
    else if (d[1] < d[0] && d[1] < d[2])
    {
     	x = (ref_point[1].y+ref_point[2].y)/2 - org_x;
     	y = (ref_point[1].x+ref_point[2].x)/2 - org_y;
     	*angle = radian_to_angle(atan2(y,x));
    }
    else
    {
     	x = (ref_point[0].y+ref_point[1].y)/2 - org_x;
     	y = (ref_point[0].x+ref_point[1].x)/2 - org_y;
     	*angle = radian_to_angle(atan2(y,x));
    }
}

int RADIUS = 1437;
int SAMPLES = 25;
float FIRST = 108;
void microscope_move_to_sample(int index,
        coordinates ref_original, float ref_angle)
{
    cylindroid  c;
    coordinates target;
    coordinates current = micorscope_get_coordinates();
    if(index > 25 || index < 0)
        return ;
    if(index == 0)
    {
        target.x = 0;
        target.y = 0;
        target.z = current.z;
        micorscope_run_to_coordinates(target);
        return;
    }
    c.phi = angle_to_radian(-360.0/SAMPLES * index-1 + ref_angle + FIRST);
    c.r   = RADIUS;
    c.z   = current.z;
    target =  rectangular_to_coordinates(cylindroid_to_rectangular(c));
    target.x += ref_original.x;
    target.y += ref_original.y;
    target.z += ref_original.z;
    micorscope_run_to_coordinates(target);
    printf("x = %d, y = %d, z = %d\n", target.x, target.y, target.z);
}

int HOLE = 1437;
int HOLES = 25;
float HOLE_FIRST = 108;
void microscope_move_to_input_hole(int index,
		coordinates ref_original, float ref_angle)
{
    cylindroid  c;
    coordinates target;
    coordinates current = micorscope_get_coordinates();
    if(index > 25 || index < 0)
        return ;
    if(index == 0)
    {
        target.x = 0;
        target.y = 0;
        target.z = current.z;
        micorscope_run_to_coordinates(target);
        return;
    }
    c.phi = angle_to_radian(-360.0/HOLES * index-1 + ref_angle + HOLE_FIRST);
    c.r   = HOLE;
    c.z   = current.z;
    target =  rectangular_to_coordinates(cylindroid_to_rectangular(c));
    target.x += ref_original.x;
    target.y += ref_original.y;
    target.z += ref_original.z;
    micorscope_run_to_coordinates(target);
    printf("x = %d, y = %d, z = %d\n", target.x, target.y, target.z);
}

int DISTANCE=2500;
int HIGH=5000;
void microscope_move_neadle_to_sample()
{
	microscope_x_minus(DISTANCE);
	microscope_z_minus(HIGH);
}

void microscope_move_neadle_back()
{
	microscope_z_plus(HIGH);
	microscope_x_plus(DISTANCE);
}

