/*
 * syringe.h
 *
 *  Created on: Jan 29, 2013
 *      Author: lizhizhou
 */

#ifndef SYRINGE_H_
#define SYRINGE_H_
extern void syringe_mark_start();
extern void syringe_set_target(int m_litre, int u_litre);
extern void syringe_set_diameter(int m_meter);
extern int syringe_run_forward();
extern int syringe_run_back();
extern int syringe_faster_forward();
extern int syringe_faster_back();
extern unsigned int syringe_forward_step(unsigned int step);
extern unsigned int syringe_back_step(unsigned int step);
extern void syringe_init();

#endif /* SYRINGE_H_ */
