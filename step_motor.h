/*
 * step_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_

extern void step_motor_init(void* stepmotor_address, unsigned int frequence, unsigned int duty_cycle);
extern void step_motor_move_step_forward(void* stepmotor_address);
extern void step_motor_move_step_back(void* stepmotor_address);
extern void setp_motor_subdivision(void* stepmotor_address, unsigned int subdivision, unsigned int duty_cycle);

#endif /* STEPMOTOR_H_ */
