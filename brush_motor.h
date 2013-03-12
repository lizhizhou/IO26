/*
 * brush_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef BRUSHMOTOR_H_
#define BRUSHMOTOR_H_

extern void brush_motor_init();
extern void brush_motor_forward();
extern void brush_motor_back();
extern void brush_motor_ON();
extern void brush_motor_OFF();
extern void brush_motor_set_pwm(unsigned int pwm);

#endif /* BRUSHMOTOR_H_ */
