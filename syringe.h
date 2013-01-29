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
extern int syringe_run();
extern void syringe_init();

#endif /* SYRINGE_H_ */
