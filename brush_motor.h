/*
 * brush_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef BRUSHMOTOR_H_
#define BRUSHMOTOR_H_

extern void brush_motor_init(unsigned int brushmotor_address);
extern void brush_motor_forward(unsigned int brushmotor_address);
extern void brush_motor_back(unsigned int brushmotor_address);
extern void brush_motor_ON(unsigned int brushmotor_address);
extern void brush_motor_OFF(unsigned int brushmotor_address);
extern void brush_motor_set_pwm(unsigned int brushmotor_address,
        unsigned int pwm);

#endif /* BRUSHMOTOR_H_ */
