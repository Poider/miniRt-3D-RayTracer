#include "miniRt.h"

typedef struct  s_sphere{

    t_tuple origin;
    float radius;
    int object_id;
    t_matrices *transformation;
}               t_sphere;

t_sphere *create_sphere(float radius, t_tuple origin, t_parameters *param);
