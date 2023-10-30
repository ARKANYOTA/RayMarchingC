//
// Created by Arkan Yota on 19/10/2023.
//

#ifndef RAYMARCHINGC_VEC3_H
#define RAYMARCHINGC_VEC3_H

typedef struct vec3 {
    double x;
    double y;
    double z;
} vec3;

vec3 vec3_diff(vec3 a, vec3 b);
vec3 vec3_add(vec3 a, vec3 b);
double vec3_length(vec3 a);
vec3 vec3_normalize(vec3 a);
vec3 vec3_scale(vec3 a, float b);
vec3 vec3_new_pos(vec3 a,double dist, double yaw, double pitch);
vec3 vec3_abs(vec3 a);

#endif //RAYMARCHINGC_VEC3_H
