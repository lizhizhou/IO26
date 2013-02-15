/*
 * position_sensor.h
 *
 *  Created on: 2012-10-30
 *      Author: zhizholi
 */

#ifndef POSITION_SENSOR_H_
#define POSITION_SENSOR_H_

extern void select_position_sensor(void* address);
extern int get_position();
extern int get_direction();

#endif /* POSITION_SENSOR_H_ */
