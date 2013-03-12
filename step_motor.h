/*
 * step_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_

extern void step_motor_init(unsigned int stepmotor_address);
extern void step_motor_move_step_forward(unsigned int stepmotor_address);
extern void step_motor_move_step_back(unsigned int stepmotor_address);
extern void setp_motor_subdivision(unsigned int stepmotor_address,
		unsigned int subdivision);

#endif /* STEPMOTOR_H_ */
