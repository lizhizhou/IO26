/*
 * PID.h
 *
 *  Created on: Nov 9, 2012
 *      Author: Zhizhou LI
 */
#ifndef PID_H_
#define PID_H_

float PID(float x_n,float x_n_1,float x_n_2, float Kp, float Ki, float Kd);
double PID_d(double x_n,double x_n_1,double x_n_2, double Kp, double Ki, double Kd);

#endif /*  PID_H_ */