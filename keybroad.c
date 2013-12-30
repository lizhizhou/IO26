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
static int delta1;
static int delta2;
static unsigned char encoder1;
static unsigned char encoder2;
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

int get_encoder_delta1()
{
	int temp = delta1;
	delta1 = 0;
	return temp;
}

int get_encoder_delta2()
{
	int temp = delta2;
	delta2 = 0;
	return temp;
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
		//printf("temp_key = %d", temp_key);
		temp_encoder1 = (temp_key >> 16) & 0xFF;
		//printf("a = %d", temp_encoder1);
		temp_encoder2 = (temp_key >> 24) & 0xFF;
		if(temp_encoder1 > 200 && encoder1 < 50)
			delta1 += encoder1 + (255 - temp_encoder1);
		else if (encoder1 > 200 && temp_encoder1 < 50)
			delta1 += -(255 - encoder1) + temp_encoder1;
		else
			delta1 += encoder1 - temp_encoder1;
		if(delta1 != 0)
			printf("d1 = %d\n", delta1);
		if(temp_encoder2 > 200 && encoder2 < 50)
			delta2 += encoder1 + (255 - temp_encoder2);
		else if (encoder2 > 200 && temp_encoder2 < 50)
			delta2 += -(255 - encoder1) + temp_encoder1;
		else
			delta2 += encoder2 - temp_encoder2;
		if(delta2 != 0)
			printf("d2 = %d\n", delta2);
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
