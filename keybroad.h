/*
 * keybroad.h
 *
 *  Created on: Sep 19, 2013
 *      Author: zhizhouli
 */

#ifndef KEYBROAD_H_
#define KEYBROAD_H_

typedef enum key_value_t{
	KEY_NONE =0,
	KEY_UP = 1,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_ENTER,
	KEY_ESC,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	ENCODER_KEY,
}key_value;

extern void keybroad_init();
extern key_value return_key();
extern key_value get_key();
extern int get_encoder_delta1();
extern int get_encoder_delta2();

#endif /* KEYBROAD_H_ */
