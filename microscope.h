/*
 * microscope.h
 *
 *  Created on: Mar 26, 2013
 *      Author: lizhizhou
 */

#ifndef MICROSCOPE_H_
#define MICROSCOPE_H_

extern void microscope_init(void);
extern int microscope_up(int step);
extern int microscope_down(int step);
extern int microscope_left(int step);
extern int microscope_right(int step);

#endif /* MICROSCOPE_H_ */
