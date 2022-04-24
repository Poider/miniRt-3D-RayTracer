#include "miniRt.h"

typedef struct  s_sphere{

    t_tuple origin;
    float radius;
    int object_id;
    t_matrices *transformation;
}               t_sphere;

typedef struct  s_intersections{
    float t;
    void *object;
    struct s_intersections *next;
}               t_intersections;

void set_tranform(t_sphere *s,t_matrices *matrix);