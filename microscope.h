/*
 * microscope.h
 *
 *  Created on: Mar 26, 2013
 *      Author: lizhizhou
 */

#ifndef MICROSCOPE_H_
#define MICROSCOPE_H_
#include "coordinate.h"
#define PARALLEL
typedef struct coordinates_t {
  int x;
  int y;
  int z;
}coordinates;

extern void microscope_init(void);
extern unsigned int microscope_x_plus(unsigned int step);
extern unsigned int microscope_x_minus(unsigned int step);
extern unsigned int microscope_y_plus(unsigned int step);
extern unsigned int microscope_y_minus(unsigned int step);
extern unsigned int microscope_z_plus(unsigned int step);
extern unsigned int microscope_z_minus(unsigned int step);
extern void microscope_manual_calibration_on(void);
extern void microscope_manual_calibration_off(void);
extern coordinates micorscope_run_to_coordinates(coordinates p);
extern coordinates micorscope_get_coordinates(void);
extern void micorscope_set_coordinates_zero(void);
extern void micorscope_set_coordinates(coordinates n);
extern coordinates rectangular_to_coordinates(rectangular n);
extern rectangular coordinates_to_rectangular(coordinates n);
extern void microscope_original_angle(coordinates ref_point[],
        coordinates* original, float* angle);
extern void microscope_move_to_sample(int index,
        coordinates ref_original, float ref_angle);
#endif /* MICROSCOPE_H_ */
