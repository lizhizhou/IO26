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
#define NUM_KEY 12
#define KEYBROAD PNL_BASE
static int key;
static bool key_input;
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
void keybroad_thread(void)
{
	int temp_key;
	int i;
	temp_key = PNL_BASE;
	if(temp_key == 0)
		key_input = false;
	else
		key_input = true;
	for(i=0; i< NUM_KEY; i++)
	{
		if (temp_key & (1 << i))
			key = i+1;
	}
}

void keybroad_init()
{
	pthread_t keybroad;
	pthread_create(&keybroad, NULL, keybroad_thread, NULL);
}
