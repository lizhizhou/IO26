/*
 * Brush_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef BRUSHMOTOR_H_
#define BRUSHMOTOR_H_

extern void Brush_motor_init();
extern void Brush_motor_forward();
extern void Brush_motor_back();
extern void Brush_motor_set_pwm(unsigned int pwm);

#endif /* BRUSHMOTOR_H_ */
