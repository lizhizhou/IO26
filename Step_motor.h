/*
 * Step_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_

extern void Step_motor_init();
extern void Step_motor_move_step_forward();
extern void Step_motor_move_step_back();
extern void Setp_motor_subdivision(unsigned int subdivision);

#endif /* STEPMOTOR_H_ */
