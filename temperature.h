/*
 * temperature.h
 *
 *  Created on: May 10, 2013
 *      Author: lizhizhou
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

extern void set_temperature_target(float temperature);
extern void* temperature_regulating_process(void* arg);

#endif /* TEMPERATURE_H_ */
