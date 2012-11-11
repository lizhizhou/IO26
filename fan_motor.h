/*
 * fan_motor.h
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */

#ifndef FAN_MOTOR_H_
#define FAN_MOTOR_H_
extern void fan_motor_init();
extern void fan_ON();
extern void fan_motor_set_pwm(unsigned int pwm);

#endif /* FAN_MOTOR_H_ */
