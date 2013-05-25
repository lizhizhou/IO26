/*
 * coordinate.h
 *
 *  Created on: May 25, 2013
 *      Author: lizhizhou
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_
#include <math.h>
typedef struct rectangular_t
{
    float x;
    float y;
    float z;
}rectangular;

typedef struct cylindroid_t
{
    float r;
    float phi;
    float z;
}cylindroid;

typedef struct spheroid_t
{
    float r;
    float phi;
    float theta;
}spheroid;

static inline float angle_to_radian(float angle)
{
    return (angle/360.0*(2*M_PI));
}

static inline float radian_to_angle(float radian)
{
    return (radian*360.0/(2*M_PI));
}

extern cylindroid rectangular_to_cylindroid(rectangular n);
extern spheroid rectangular_to_spheroid (rectangular n);
extern rectangular cylindroid_to_rectangular (cylindroid n);
extern spheroid cylindroid_to_spheroid(cylindroid n);
extern cylindroid spheroid_to_cylindroid(spheroid n);
extern rectangular spheroid_to_rectangular(spheroid n);

#endif /* COORDINATE_H_ */
