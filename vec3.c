//
// Created by Arkan Yota on 19/10/2023.
//

#include "vec3.h"
#include <math.h>

vec3 vec3_diff(vec3 a, vec3 b){
    return (vec3) {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
};

vec3 vec3_add(vec3 a, vec3 b){
    return (vec3) {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
    };
};
double vec3_length(vec3 a){
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
};

vec3 vec3_normalize(vec3 a){
    double len = vec3_length(a);
    return (vec3) {
        a.x/len,
        a.y/len,
        a.z/len
    };
}

vec3 vec3_scale(vec3 a, float b){
    double len = vec3_length(a);
    return (vec3) {
            (a.x/len)*b,
            (a.y/len)*b,
            (a.z/len)*b
    };
}


vec3 vec3_new_pos(vec3 a,double dist, double yaw, double pitch){
    return (vec3) {
            a.x + dist * sin(pitch) * cos(yaw),
            a.y + dist * sin(pitch) * sin(yaw),
            a.z + dist * cos(pitch)
    };
}

vec3 vec3_abs(vec3 a){
    return (vec3) {
            fabs(a.x),
            fabs(a.y),
            fabs(a.z)
    };
}