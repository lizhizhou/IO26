/*
 * PID.c
 *
 *  Created on: Nov 9, 2012
 *      Author: Zhizhou LI
 */

#include "FPGA.h"
//Algorithm:  Discrete PID algorithm
//    y[n] = y[n-1] + A0 * x[n] + A1 * x[n-1] + A2 * x[n-2]
//    A0 = Kp + Ki + Kd
//    A1 = (-Kp ) - (2 * Kd )
//    A2 = Kd  
//    where Kp is proportional constant, Ki is Integral constant and Kd is Derivative constant

float PID(float x_n,float x_n_1,float x_n_2, float Kp, float Ki, float Kd)
{
	float y_n, A0, A1, A2;
	static float y_n_1=0.0;
	A0 = Kp + Ki + Kd;
	A1 = (-Kp) - (2 * Kd);
	A2 = Kd;
	y_n = y_n_1 + A0 * x_n + A1 * x_n_1 + A2 * x_n_2;
	y_n_1 = y_n;
	return y_n;
}

double PID_d(double x_n,double x_n_1,double x_n_2, double Kp, double Ki, double Kd)
{
	double y_n, A0, A1, A2;
	static double y_n_1=0.0;
	A0 = Kp + Ki + Kd;
	A1 = (-Kp) - (2 * Kd);
	A2 = Kd;
	y_n = y_n_1 + A0 * x_n + A1 * x_n_1 + A2 * x_n_2;
	y_n_1 = y_n;
	return y_n;
}
