//
// Created by Arkan Yota on 19/10/2023.
//

#include "sdf.h"
#include "vec3.h"
#include "math.h"
#include <math.h>


double sphereSDF(vec3 p, double s) {
    return vec3_length(p) - s;
}

double rectSDF(vec3 p, vec3 b) {
    vec3 d = vec3_diff(vec3_abs(p), b);
    return min_d(max_i(d.x, max_i(d.y, d.z)), 0) + vec3_length((vec3) {
        max_i(d.x, 0),
        max_i(d.y, 0),
        max_i(d.z, 0)
    });
}

float scene(vec3 p) {
    double min = 10000.;
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {10.,10.,10.}), 1.0));
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {10.,10.,-10.}), 1.0));
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {10.,-10.,10.}), 1.0));
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {10.,-10.,-10.}), 1.0));
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {-10.,10.,10.}), 1.0));
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {-10.,10.,-10.}), 1.0));
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {-10.,-10.,10.}), 1.0));
    min = min_d(min, sphereSDF(vec3_diff(p, (vec3) {-10.,-10.,-10.}), 1.0));
    min = min_d(min, rectSDF(vec3_diff(p, (vec3) {10.,10.,10.}), (vec3) {10.,10.,10.}));
    return min;

    return min_d(
        min_d(
            min_d(
                sphereSDF(vec3_diff(p, (vec3) {10.,10.,10.}), 1.0),
                sphereSDF(vec3_diff(p, (vec3) {10.,10.,-10.}), 1.0)
            ),
            min_d(
                sphereSDF(vec3_diff(p, (vec3) {10.,-10.,10.}), 1.0),
                sphereSDF(vec3_diff(p, (vec3) {10.,-10.,-10.}), 1.0)
            )
        ),
        min_d(
            min_d(
                sphereSDF(vec3_diff(p, (vec3) {-10.,10.,10.}), 1.0),
                sphereSDF(vec3_diff(p, (vec3) {-10.,10.,-10.}), 1.0)
            ),
            min_d(
                sphereSDF(vec3_diff(p, (vec3) {-10.,-10.,10.}), 1.0),
                sphereSDF(vec3_diff(p, (vec3) {-10.,-10.,-10.}), 1.0)
            )
        )
    );
}

vec3 normal(vec3 p) {
    double d = scene(p);
    double e = 0.01;
    return vec3_normalize((vec3) {
        d - scene(vec3_add(p, (vec3) {e, 0, 0})),
        d - scene(vec3_add(p, (vec3) {0, e, 0})),
        d - scene(vec3_add(p, (vec3) {0, 0, e}))
    });
}
