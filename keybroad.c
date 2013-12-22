/*
 * keybroad.c
 *
 *  Created on: Sep 19, 2013
 *      Author: zhizhouli
 */
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>
#include "FPGA.h"
#include "platform.h"
#include "debug.h"
#include "keybroad.h"
#define NUM_KEY 12
#define KEYBROAD PNL_DATA
static unsigned int key;
static unsigned int keybase;
static bool key_input = false;
static char delta1;
static char delta2;
static char encoder1;
static char encoder2;
key_value return_key()
{
	if(key_input == false)
	{
		return 0;
	}
	else
	{
		key_input = false;
		return key;
	}
}
key_value get_key()
{
	while(key_input == false)usleep(50000);
	key_input = false;
	return key;
}

char get_encoder_delta1()
{
	return delta1;
}

char get_encoder_delta2()
{
	return delta2;
}

void keybroad_thread(void)
{
	unsigned int temp_key;
	unsigned char temp_encoder1;
	unsigned char temp_encoder2;
	int i;
	while(1) {
		temp_key = KEYBROAD & 0xFFFF;
		if( keybase != temp_key)
		{
			printf("key input\n");
			usleep(500);
			if( (KEYBROAD & 0xFFFF)  != temp_key) {
				printf("bad input\n");
				continue;
			}
			key_input = true;
			printf("key input 0x%x\n",KEYBROAD);
			for(i = 0; i < 16; i++)
			{
				if((~temp_key >> i) & 0x1 == 0x1)
				{
					key = i + 1;
					break;
				}
			}
			printf("key wait\n");
			while((KEYBROAD & 0xFFFF) == temp_key)usleep(50000);
			printf("key input end\n");
		}
		temp_key = KEYBROAD & 0xFFFF0000;
		printf("temp_key = %d", temp_key);
		temp_encoder1 = (temp_key >> 16) & 0xFF;
		printf("a = %d", temp_encoder1);
		temp_encoder2 = (temp_key >> 24) & 0xFF;
		delta1 = (encoder1 - temp_encoder1) & 0xFF;
		printf("b = %d", encoder1 - temp_encoder1);
		delta2 = (encoder2 - temp_encoder2) & 0xFF;
		encoder1 = temp_encoder1;
		encoder2 = temp_encoder2;
		sleep(1);
	}
}

void keybroad_init()
{
	pthread_t keybroad_p;
	unsigned int keybroad;
	keybroad = KEYBROAD;
	keybase = keybroad & 0xFFFF;
	encoder1 = (keybroad >> 16) & 0xFF;
	encoder2 = (keybroad >> 24) & 0xFF;
	pthread_create(&keybroad_p, NULL, keybroad_thread, NULL);
}
