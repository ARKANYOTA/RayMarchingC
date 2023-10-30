//
// Created by Arkan Yota on 19/10/2023.
//

#include "math.h"
#include <math.h>

double min_d(double a, double b){
    return a<b ? a : b;
}

int min_i(int a, int b){
    return a<b ? a : b;
}

int max_i(int a, int b){
    return a>b ? a : b;
}

float abs_f(float a) {
    return a < 0 ? -a : a;
}

double angle_between(vec3 a, vec3 b) {
    return acos((a.x * b.x + a.y * b.y + a.z * b.z) /
            (vec3_length(a) * vec3_length(b)));

}

