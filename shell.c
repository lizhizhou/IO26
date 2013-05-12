/*
 * shell.c
 *
 *  Created on: May 10, 2013
 *      Author: lizhizhou
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    if(argc >1) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[0],"%d",&i);
    switch(i) {
        case 1:
            temperature = AM2301_get_temperature(AM2301_0);
            break;
        case 2:
            temperature = AM2301_get_temperature(AM2301_1);
            break;
    }
    printf("Temperature is %.2f C\n", temperature);
    return (1);
}
int show_moisture(int argc,char* argv[])
{
    int i;
    float moisture;
    if(argc >1) {
        printf("Error command");
        return (0);
    }
    sscanf(argv[0],"%d",&i);
    switch(i) {
        case 1:
            moisture = AM2301_get_moisture(AM2301_0);
            break;
        case 2:
            moisture = AM2301_get_moisture(AM2301_1);
            break;
    }
    printf("TMoisture is %.2f%%\n", moisture);
    return (1);
}

int set_temperature(int argc,char* argv[])
{
    float temperature;
    if(argc >1) {
        printf("Error command\n");
        return (0);
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
    return 0;
}

static int cli_help (int argc, char *argv[])
{
	shell_cmd_func_t *func = shell_cmd_func_list;
    printf("Help Manual!\n");

    while (func->name) {
        printf("%s: %s\n", func->name, func->help);
        func++;
    };
    return 1;
}

shell_cmd_func_t shell_cmd_func_list[] = {
	{"help",      "Print Help Manual",                  cli_help},
    {"temp",      "show the temperature",               show_temperature},
    {"moist",     "show the moisture",                  show_moisture},
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
    return 1;
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

    while(1)
    {
        int argc, i=0;
        bzero(buffer, sizeof(buffer));
        printf("Meteroi shell>");
        gets_s(buffer, sizeof(buffer));
        argc = parser_cli(buffer,argv);
        if (argc == 0)
            continue;
        //UTSHL_DEBUG("argc=%d\n",argc);
        while(i < argc ) {
            char cmd_name[256];
            sscanf(argv[i],"%256s ", cmd_name);
            //UTSHL_DEBUG("arg[%d] = %s\n", i, cmd_name);
            i++;
        }
        if(strcmp(buffer,"exit")==0)
        {
            break;
        } else {
            cmd_distribution(argc, argv);
        }
    }
    return (0);
}

