/*
 * keybroad.c
 *
 *  Created on: Sep 19, 2013
 *      Author: zhizhouli
 */
#include <stdbool.h>
#include <pthread.h>
#include "FPGA.h"
#include "platform.h"
#include "debug.h"
#define NUM_KEY 12
#define KEYBROAD PNL_DATA
static int key;
static int keybase;
static bool key_input = false;
int return_key()
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
int get_key()
{
	while(key_input == false)usleep(50000);
	key_input = false;
	return key;
}
void keybroad_thread(void)
{
	unsigned int temp_key;
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
				}
			}
			printf("key wait\n");
			while((KEYBROAD & 0xFFFF) == temp_key)usleep(50000);
			printf("key input end\n");
		}
	}
}

void keybroad_init()
{
	pthread_t keybroad;
	keybase = KEYBROAD & 0xFFFF;
	pthread_create(&keybroad, NULL, keybroad_thread, NULL);
}
