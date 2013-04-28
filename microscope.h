/*
 * microscope.h
 *
 *  Created on: Mar 26, 2013
 *      Author: lizhizhou
 */

#ifndef MICROSCOPE_H_
#define MICROSCOPE_H_

extern void microscope_init(void);
extern int microscope_x_plus(int step);
extern int microscope_x_minus(int step);
extern int microscope_y_plus(int step);
extern int microscope_y_minus(int step);
extern int microscope_z_plus(int step);
extern int microscope_z_minus(int step);
extern void microscope_manual_calibration_on(void);
extern void microscope_manual_calibration_off(void);


#endif /* MICROSCOPE_H_ */
