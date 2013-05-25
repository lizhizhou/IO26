/*
 * coordinate.c
 *
 *  Created on: May 25, 2013
 *      Author: lizhizhou
 */
#include "coordinate.h"

cylindroid rectangular_to_cylindroid(rectangular n)
{
    cylindroid r;
    r.z = n.z;
    r.r = sqrt(n.x*n.x + n.y*n.y);
    r.phi = atan2(n.y, n.x);
    return (r);
}

spheroid rectangular_to_spheroid (rectangular n)
{
    spheroid r;
    r.r = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
    r.phi = atan2(n.y, n.x);
    r.theta  = atan2(sqrt(n.x * n.x + n.y * n.y), n.z);
    return (r);
}

rectangular cylindroid_to_rectangular (cylindroid n)
{
    rectangular r;
    r.z = n.z;
    r.y = n.r * sin(n.phi);
    r.x = n.r * cos(n.phi);
    return (r);
}

spheroid cylindroid_to_spheroid(cylindroid n)
{
    spheroid r;
    r.r     = sqrt(n.r * n.r + n.z * n.z);
    r.phi = n.phi;
    r.theta  = atan2(n.r, n.z);
    return (r);
}

cylindroid spheroid_to_cylindroid(spheroid n)
{
    cylindroid r;
    r.r     = n.r * sin(n.theta);
    r.phi = n.phi;
    r.z     = n.r * cos(n.theta);
    return (r);
}

rectangular spheroid_to_rectangular(spheroid n)
{
    rectangular r;
    r.x = n.r * sin(n.theta) * cos(n.phi);
    r.y = n.r * sin(n.theta) * sin(n.phi);
    r.z = n.r * cos(n.theta);
    return (r);
}

