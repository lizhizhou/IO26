/*
 * fan_motor.h
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */

#ifndef FAN_MOTOR_H_
#define FAN_MOTOR_H_
extern void fan_motor_init(unsigned int fan_address);
extern void fan_ON(unsigned int fan_address);
extern void fan_motor_set_pwm(unsigned int fan_address, unsigned int pwm);

#endif /* FAN_MOTOR_H_ */
