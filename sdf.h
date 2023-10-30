//
// Created by Arkan Yota on 19/10/2023.
//

#ifndef RAYMARCHINGC_SDF_H
#define RAYMARCHINGC_SDF_H

#include "vec3.h"


float scene(vec3 p);
double sphereSDF(vec3 p, double s);
vec3 normal(vec3 p);

#endif //RAYMARCHINGC_SDF_H
