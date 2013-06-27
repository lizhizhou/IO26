/*
 * shell.c
 *
 *  Created on: May 10, 2013
 *      Author: lizhizhou
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>
#include "platform.h"
#include "PIO26.h"
#include "shield_ctrl.h"
#include "FPGA.h"
#include "AM2301.h"
#include "sht1x.h"
#include "position_sensor.h"
#include "step_motor.h"
#include "brush_motor.h"
#include "fan_motor.h"
#include "syringe.h"
#include "microscope.h"
#include "moisture.h"
#include "temperature.h"
#include "unit_test.h"
#include "debug.h"

typedef int (*shell_cmd_func)(int argc, char *argv[]);
typedef struct shell_cmd_t {
    char *name;
    char *help;
    shell_cmd_func func;
} shell_cmd_func_t;
extern shell_cmd_func_t shell_cmd_func_list[];

int show_temperature(int argc,char* argv[])
{
    int i;
    float temperature;
    if(argc < 1) {
        printf("Error command");
        return (false);
    }
    sscanf(argv[0],"%d",&i);
    switch(i) {
        case 1:
            temperature = sht1x_get_temperature(SHT1X_0);//AM2301_get_temperature(AM2301_0);
            break;
        case 2:
            temperature = sht1x_get_temperature(SHT1X_1);//AM2301_get_temperature(AM2301_1);
            break;
        default:
            printf("Error command");
            return (0);
    }
    printf("Temperature is %.2f C\n", temperature);
    return (1);
}
int show_moisture(int argc,char* argv[])
{
    int i;
    float moisture;
    if(argc < 1) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[0],"%d",&i);
    switch(i) {
        case 1:
            moisture = sht1x_get_moisture(SHT1X_0);//AM2301_get_moisture(AM2301_0);
            break;
        case 2:
            moisture = sht1x_get_moisture(SHT1X_1);//AM2301_get_moisture(AM2301_1);
            break;
        default:
            printf("Error command");
            return (0);
    }
    printf("TMoisture is %.2f%%\n", moisture);
    return (1);
}

int set_temperature(int argc,char* argv[])
{
    float temperature;
    if(argc >1) {
        printf("Error command\n");
        return (false);
    }
    sscanf(argv[0],"%f", &temperature);
    set_temperature_target(temperature);
    return (1);
}

int set_moisture(int argc,char* argv[])
{
    float moisture;
    if(argc >1) {
        printf("Error command");
        return (false);
    }
    sscanf(argv[0],"%f", &moisture);
    set_moisture_target(moisture);
    return (true);
}

int show_microscop_position(int argc,char* argv[])
{
    coordinates p;
    p = micorscope_get_coordinates();
    printf("The position is %d %d %d\n", p.x, p.y, p.z);
    return (true);
}

int set_microscop_position(int argc,char* argv[])
{
    coordinates p;
    if(argc < 3) {
        printf("Error command");
        return (false);
    }
    sscanf(argv[0], "%d %d %d", &p.x, &p.y, &p.z);
    p = micorscope_run_to_coordinates(p);
    printf("The position is %d %d %d\n", p.x, p.y, p.z);
    return (true);
}

int microscop_x(int argc,char* argv[])
{
    coordinates p;
    int x;
    if(argc < 1) {
        printf("Error command");
        return (false);
    }
    p = micorscope_get_coordinates();
    sscanf(argv[0], "%d", &x);
    p.x+=x;
    p = micorscope_run_to_coordinates(p);
    printf("The position is %d %d %d\n", p.x, p.y, p.z);
    return (true);
}

int microscop_y(int argc,char* argv[])
{
    coordinates p;
    int y;
    if(argc < 1) {
        printf("Error command");
        return (false);
    }
    p = micorscope_get_coordinates();
    sscanf(argv[0], "%d", &y);
    p.y+=y;
    p = micorscope_run_to_coordinates(p);
    printf("The position is %d %d %d\n", p.x, p.y, p.z);
    return (true);
}

int microscop_z(int argc,char* argv[])
{
    coordinates p;
    int z;
    if(argc < 1) {
        printf("Error command");
        return (false);
    }
    p = micorscope_get_coordinates();
    sscanf(argv[0], "%d", &z);
    p.z+=z;
    p = micorscope_run_to_coordinates(p);
    printf("The position is %d %d %d\n", p.x, p.y, p.z);
    return (true);
}

coordinates r[4];
coordinates o;
float angle = 0 ;
int microscop_ref(int argc,char* argv[])
{
    int i;

    if(argc < 1) {
        printf("Error command");
        return (false);
    }
    sscanf(argv[0], "%d", &i);
    if(i > 4)
    	return (false);
    r[i] = micorscope_get_coordinates();
    printf("The ref point 0 is %d %d\n", r[0].x, r[0].y);
    printf("The ref point 1 is %d %d\n", r[1].x, r[1].y);
    printf("The ref point 2 is %d %d\n", r[2].x, r[2].y);
    printf("The ref point 3 is %d %d\n", r[3].x, r[3].y);
    microscope_original_angle(r, &o, &angle);
    printf("The orignial point is %d %d\n", o.x, o.y);
   	printf("The angle is %f ", angle);
    return (true);
}

int microscop_move(int argc,char* argv[])
{
    int i;
    if(argc < 1) {
        printf("Error command");
        return (false);
    }
    sscanf(argv[0], "%d", &i);
    microscope_move_to_sample(i, o, angle);
    return (true);
}

int manual_calibration(int argc,char* argv[])
{
    char buf[255];
    if(argc < 1) {
        printf("Error command");
        return (false);
    }
    sscanf(argv[0], "%s", buf);
    if(!strcmp(buf,"on"))
        microscope_manual_calibration_on();
    else if(!strcmp(buf,"off"))
        microscope_manual_calibration_off();
    return (true);
}

int syringe_control(int argc,char* argv[])
{
	return (true);
}

int unit_test(int argc,char* argv[])
{
	// Unit_test
	int i;
	printf("1:AM2301_test\n");
	printf("2:syringe_test\n");
	printf("3:step_motmor_test\n");
	printf("4:brush_motor_test\n");
	printf("5:microscope_test\n");
	printf("6:wheel_plate_test\n");
	printf("7:PID_test\n");
	printf("8:PIO_test\n");
	printf("Input choose\n");
	scanf("%d",&i);
	switch(i) {
		case 1:
			AM2301_test();
			break;
		case 2:
			syringe_test();
			break;
		case 3:
			step_motmor_test();
			break;
		case 4:
			brush_motor_test();
			break;
		case 5:
			microscope_test();
			break;
		case 6:
			wheel_plate_test();
			break;
		case 7:
			PID_test();
			break;
		case 8:
			PIO_test();
			break;
	}
	return (true);
}

static int cli_help (int argc, char *argv[])
{
	shell_cmd_func_t *func = shell_cmd_func_list;
    printf("Help Manual!\n");

    while (func->name) {
        printf("%s: %s\n", func->name, func->help);
        func++;
    };
    return (true);
}

shell_cmd_func_t shell_cmd_func_list[] = {
	{"help",      "Print Help Manual",                 cli_help},
    {"temp",      "show the temperature",              show_temperature},
    {"moist",     "show the moisture",                 show_moisture},
    {"tempt",     "Set the target temperature",        set_temperature},
    {"moistt",    "Set the target temperature",        set_moisture},
    {"scope",     "set the coordinates of the micro scope",set_microscop_position},
    {"manual",    "Manual regulate the micro scope",   manual_calibration},
    {"Syringe",   "Syringe control",                   syringe_control},
    {"x",         "regular x of micro scope",          microscop_x},
    {"y",         "regular y of micro scope",          microscop_y},
    {"z",         "regular z of micro scope",          microscop_z},
    {"move",      "Move to the sample",                microscop_move},
    {"ref",       "set the reference point of micro scope", microscop_ref},
    {"ut",        "Unit test of the system",           unit_test},
    {NULL, NULL, NULL}
};

#define CLI_BUFFER_SIZE 1024
#define ARG_LIST_SIZE 20
static int cmd_distribution (int argc, char *argv[])
{
	shell_cmd_func_t *func = shell_cmd_func_list;
    char keyword[CLI_BUFFER_SIZE];
    char *arg = argv[0];
    int  state;
    //find first argument
    sscanf(arg,"%1024s",keyword);

    while (func->name) {
        if (!strncasecmp(func->name, keyword, CLI_BUFFER_SIZE)) {
            if (func->func) {
                state = ((func->func)(--argc, ++argv));
            }
            break;
        }
        func++;
    };

    if (!func->name) {
        printf("%s: Unsupported command!\n", arg);
    }

    if (state == 0) {
        printf("%s: argument error!\n", arg);
    }
    return (true);
}

static int parser_cli(char* buffer, char* argv[])
{
    int i = 0;
    if (strlen(buffer) == 0)
        return (0);
    argv[i] = buffer;
    i++;
    while(*buffer!='\0')
    {
        buffer++;
        if(isspace(*buffer)) {
            while(*buffer!='\0') {
                buffer++;
                if(!isspace(*buffer) && *buffer !='\0'){
                    argv[i] = buffer;
                    i++;
                    break;
                }
            }
        }
    }
    return (i);
}

int gets_s(char* buffer, int buf_size)
{
    int i;
    for (i = 0; i < buf_size; i++) {
        *buffer = getchar();
        if (*buffer == '\n')
            break;
        buffer++;
    }
    *buffer = '\0';
    return (i);
}

int cli() {
    char buffer[CLI_BUFFER_SIZE];
    char *argv[ARG_LIST_SIZE];

    microscope_init();

    while(1)
    {
        int argc, i=0;
        bzero(buffer, sizeof(buffer));
        printf("Meteroi shell>");
        gets_s(buffer, sizeof(buffer));
        argc = parser_cli(buffer,argv);
        if (argc == 0)
            continue;
        debuginf("argc=%d\n",argc);
        while(i < argc ) {
            char cmd_name[256];
            sscanf(argv[i],"%256s ", cmd_name);
            debuginf("arg[%d] = %s\n", i, cmd_name);
            i++;
        }
        if(strcmp(buffer,"exit")==0)
        {
            break;
        } else {
            cmd_distribution(argc, argv);
        }
    }
    return (true);
}

